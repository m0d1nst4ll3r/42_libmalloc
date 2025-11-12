/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmalloc_free_all.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:46:06 by rapohlen          #+#    #+#             */
/*   Updated: 2025/11/12 12:51:25 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmalloc.h"

static void	libmlc_free_tab(void *tab[LIBMLC_SIZE])
{
	unsigned char	i;

	i = 0;
	while (i < LIBMLC_SIZE)
	{
		if (tab[i])
			free(tab[i]);
		i++;
	}
}

void	libmlc_free_all(t_libmlc **libmlc)
{
	t_libmlc	*iter;
	t_libmlc	*last;

	iter = *libmlc;
	while (iter)
	{
		libmlc_free_tab(iter->tab);
		last = iter;
		iter = iter->next;
		free(last);
	}
	*libmlc = NULL;
}
