/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 11:19:23 by lmartin           #+#    #+#             */
/*   Updated: 2020/09/16 12:55:45 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <unistd.h>
# include <stddef.h>
# include <pthread.h>
# include <sys/mman.h>
# include <sys/resource.h>

void		free(void *ptr);
void		*malloc(size_t size);
void		*realloc(void *ptr, size_t size);

#endif
