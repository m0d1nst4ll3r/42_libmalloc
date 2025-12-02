/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmalloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:05:21 by rapohlen          #+#    #+#             */
/*   Updated: 2025/12/02 14:27:47 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMALLOC_H
# define LIBMALLOC_H

# include <stdlib.h>

# define LIBMLC_SIZE	32
# define LIBMLC_ERRET	101

typedef struct s_libmlc
{
	void			*tab[LIBMLC_SIZE];
	int				avail;
	struct s_libmlc	*next;
}t_libmlc;

// Allocates (size) bytes and returns a pointer to the allocated memory
// Frees all and exits in case of malloc failure
void	*libmlc_malloc(t_libmlc **libmlc, size_t size);

// Frees allocated memory pointed to by (p)
void	libmlc_free(t_libmlc **libmlc, void *p);

// Frees all allocated memory
void	libmlc_free_all(t_libmlc **libmlc);

#endif
