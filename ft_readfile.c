/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getpiece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 15:46:44 by tmerli            #+#    #+#             */
/*   Updated: 2017/11/23 19:18:04 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "tetriminos.h"

char	**ft_readfile(char *file)
{
	int		fd;
	char	buf[21];
	int		i;
	char	**tab;

	i = 0;
	if ((fd = open(file, O_RDONLY)) < 0)
		return (0);
	while (read(fd, buf, 21))
		i++;
	close(fd);
	fd = open(file, O_RDONLY);
	if (!(tab = (char**)malloc(sizeof(char*) * i + 1)))
		return (NULL);
	i = 0;
	while (read(fd, buf, 21))
	{
		buf[20] = '\0';
		tab[i++] = ft_strdup(buf);
	}
	tab[i] = NULL;
	close(fd);
	return (tab);
}
