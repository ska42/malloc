/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 00:11:15 by lmartin           #+#    #+#             */
/*   Updated: 2021/02/11 10:00:21 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

/*
** return the length of the str s
*/

size_t			ft_strlen(const char *s)
{
	const char *ptr;

	ptr = s;
	while (*ptr)
		++ptr;
	return (ptr - s);
}

/*
** print a size_t nbr
*/

void			ft_putnbr(size_t n)
{
	int				i;
	char			str[12];
	size_t			nnbr;
	int				size;

	size = 0;
	nnbr = n;
	while (nnbr)
		nnbr /= 10 + 0 * size++;
	nnbr = n;
	if (!size)
		str[size++] = '0';
	str[size] = '\0';
	i = size;
	while (i--)
	{
		str[i] = (nnbr % 10) + 48;
		nnbr /= 10;
	}
	write(STDOUT_FILENO, str, ft_strlen(str));
}

/*
** print a unsigned long number n in hexa capslock
*/

void			ft_puthexa(unsigned long n)
{
	int				i;
	char			str[20];
	unsigned long	nnbr;
	int				size;

	size = 0;
	nnbr = n;
	while (n)
		n /= 16 + 0 * size++;
	if (!size)
		str[size++] = '0';
	str[size] = '\0';
	i = size;
	n = nnbr;
	while (i--)
	{
		if (nnbr % 16 < 10)
			str[i] = (nnbr % 16) + 48;
		else
			str[i] = (nnbr % 16) + (65 - 10);
		nnbr /= 16;
	}
	write(STDOUT_FILENO, str, ft_strlen(str));
}

/*
** copy byte by byte and n size of the data in src to dst and return dst
*/

void			*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*pt_src;
	char		*pt_dst;

	pt_src = (char *)src;
	pt_dst = (char *)dst;
	while (n--)
		*pt_dst++ = *pt_src++;
	return (dst);
}
