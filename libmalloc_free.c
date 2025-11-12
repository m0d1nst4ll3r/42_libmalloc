/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmalloc_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:41:22 by rapohlen          #+#    #+#             */
/*   Updated: 2025/11/12 12:48:11 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmalloc.h"

static int	libmlc_is_tab_empty(void *tab[LIBMLC_SIZE])
{
	int	i;

	i = 0;
	while (i < LIBMLC_SIZE)
	{
		if (tab[i])
			return (0);
		i++;
	}
	return (1);
}

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

// Gotta find where p is, then check if the tab is empty, and if so, remove node
// To remove node, need a last
// To find p, and check if it's empty, need a i
void	libmlc_free(t_libmlc **libmlc, void *p)
{
	t_libmlc	*iter;
	t_libmlc	*last;

	iter = *libmlc;
	while (iter)
	{
		if (libmlc_remove_addr(iter->tab, p))
		{
			if (libmlc_is_tab_empty(iter->tab))
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
