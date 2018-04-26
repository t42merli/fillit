/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 12:18:35 by tmerli            #+#    #+#             */
/*   Updated: 2017/12/02 20:45:29 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "tetriminos.h"

static void	ft_freeit(void **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static void	ft_free(char *map, void **t, void **tab)
{
	ft_freeit(tab);
	ft_freeit(t);
	free(map);
}

static char	*ft_createmap(void)
{
	char *map;

	if (!(map = (char*)malloc(sizeof(char) * 150)))
		return (NULL);
	ft_memset(map, '.', 150);
	return (map);
}

int			main(int argc, char *argv[])
{
	int				i;
	char			**tab;
	t_tetriminos	*tetriminos;
	char			*map;

	if (argc != 2)
	{
		ft_putendl("usage : ./fillit file");
		return (0);
	}
	if (!ft_checkfile(argv[1]))
		return (0);
	i = 0;
	tab = ft_readfile(argv[1]);
	while (tab[i])
		i++;
	tetriminos = ft_gettetriminos(tab, i);
	if (!(map = ft_createmap()))
		return (0);
	i = ft_minsize(i, tetriminos);
	while (i < 12 && !ft_place(tetriminos, map, 0, i))
		i++;
	ft_display(map, i);
	ft_free(map, (void**)tetriminos, (void**)tab);
	return (0);
}
