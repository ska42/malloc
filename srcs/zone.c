/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 14:05:37 by lmartin           #+#    #+#             */
/*   Updated: 2020/11/08 17:28:46 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int			get_alloc_size(size_t block_size)
{
	if (block_size <= TINY_ALLOC)
		return (TINY_ALLOC);
	else if (block_size <= SMALL_ALLOC)
		return (SMALL_ALLOC);
	return (block_size);
}

int			get_zone_size(size_t block_size)
{
	int		new_size;
	int		page_size;
	int		alloc_size;

	page_size = getpagesize();
	alloc_size = get_alloc_size(block_size);
	if (block_size <= SMALL_ALLOC)
	{
		new_size = (NB_ALLOC / (page_size / alloc_size) + 1) * page_size;
		if (new_size - NB_ALLOC * alloc_size < (int)sizeof(t_zone))
			new_size += page_size;
	}
	else
	{
		new_size = (alloc_size / page_size + 1) * page_size;
		if (new_size - alloc_size < (int)sizeof(t_zone))
			new_size += page_size;
	}
	return (new_size);
}

t_zone		*create_zone(size_t size)
{
	t_zone		new_zone;
	int			zone_size;

	zone_size = get_zone_size((size_t)(size + sizeof(t_block)));
	new_zone = mmap(NULL, zone_size, PROT_READ | PROT_WRITE, MAP_PRIVATE |
MAP ANON, -1, 0);
	new_zone->size = size;
	new_zone->blocks = NULL;
	new_zone->next = NULL;
	return (new_zone);
}

int			get_size_taken_zone(t_zone *zone)
{
	int			size;
	t_block		*tmp;

	size = sizeof(t_zone);
	if (zone->blocks)
	{
		tmp = zone->blocks;
		while (tmp)
		{
			size += tmp->size;
			tmp = tmp->next;
		}
	}
	return (size);
}

t_block		*add_block_to_zone(t_zone *zone, size_t size)
{
	int			block_size;
	int			size_taken;
	t_block		*block;

	if (zone->size - sizeof(t_zone) < size + sizeof(t_block))
		return (NULL);
	block_size = get_alloc_size(size + sizeof(t_block));
	if (!zone->blocks)
	{
		zone->blocks = zone + sizeof(t_zone);
		block = zone->blocks;
	}
	else
	{
		size_taken = get_size_taken_zone(zone);
		if (zone->size - size_taken > block_size)
		{
			
		}
	}
	block->size = block_size;
	block->next = NULL;
	return (block);
}
