/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmalloc_malloc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:04:50 by rapohlen          #+#    #+#             */
/*   Updated: 2025/11/12 12:52:03 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmalloc.h"

static void	libmlc_init_tab(void *tab[LIBMLC_SIZE])
{
	int	i;

	i = 0;
	while (i < LIBMLC_SIZE)
	{
		tab[i] = NULL;
		i++;
	}
}

static t_libmlc *libmlc_create_elem(void)
{
	t_libmlc	*new;

	new = malloc(sizeof(t_libmlc));
	if (!new)
		return (new);
	libmlc_init_tab(new->tab);
	return (new);
}

static int	libmlc_add_new(t_libmlc **libmlc, void *to_add)
{
	t_libmlc	*new;

	new = libmlc_create_elem();
	if (!new)
		return (1);
	new->tab[0] = to_add;
	new->next = *libmlc;
	*libmlc = new;
	return (0);
}

static int	libmlc_add_first_null(t_libmlc *libmlc, void *to_add)
{
	int	i;

	while (libmlc)
	{
		i = 0;
		while (i < LIBMLC_SIZE)
		{
			if (!libmlc->tab[i])
			{
				libmlc->tab[i] = to_add;
				return (1);
			}
			i++;
		}
		libmlc = libmlc->next;
	}
	return (0);
}

void	*libmlc_malloc(t_libmlc **libmlc, size_t size)
{
	void	*new;

	new = malloc(size);
	if (!new)
		return (new);
	if (!libmlc_add_first_null(*libmlc, new))
	{
		if (!libmlc_add_new(libmlc, new))
		{
			free(new);
			return (NULL);
		}
	}
	return (new);
}
