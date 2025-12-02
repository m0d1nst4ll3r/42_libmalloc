/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmalloc_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:41:22 by rapohlen          #+#    #+#             */
/*   Updated: 2025/12/02 12:04:34 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmalloc.h"

static int	libmlc_remove_addr(void *tab[LIBMLC_SIZE], void *p)
{
	int	i;

	i = 0;
	while (i < LIBMLC_SIZE)
	{
		if (tab[i] == p)
		{
			free(p);
			tab[i] = NULL;
			return (1);
		}
		i++;
	}
	return (0);
}

// finding where p is can take VERY long if there are lots of addresses
// since we add front, newer addresses will be checked first
// a lower LIBMLC_SIZE will use more memory but force newer addresses forward
void	libmlc_free(t_libmlc **libmlc, void *p)
{
	t_libmlc	*iter;
	t_libmlc	*last;

	iter = *libmlc;
	while (iter)
	{
		if (libmlc_remove_addr(iter->tab, p))
		{
			iter->avail++;
			if (iter->avail == LIBMLC_SIZE)
			{
				if (iter == *libmlc)
					*libmlc = iter->next;
				else
					last = iter->next;
				free(iter);
			}
			return ;
		}
		last = iter;
		iter = iter->next;
	}
}
