/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmalloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:05:21 by rapohlen          #+#    #+#             */
/*   Updated: 2025/11/12 11:36:22 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMALLOC_H
# define LIBMALLOC_H

# include <stdlib.h>

# define LIBMLC_SIZE	64

typedef struct s_libmlc
{
	void			*tab[LIBMLC_SIZE];
	struct s_libmlc	*next;
}t_libmlc;

void	*libmlc_malloc(t_libmlc **libmlc, size_t size);
void	libmlc_free(t_libmlc **libmlc, void *p);
void	libmlc_free_all(t_libmlc **libmlc);

#endif
