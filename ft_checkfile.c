/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 11:20:11 by tmerli            #+#    #+#             */
/*   Updated: 2017/12/02 20:34:44 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

static int	ft_checkbound(char *piece)
{
	int i;
	int bound;

	bound = 0;
	i = 0;
	while (i < 21)
	{
		if (piece[i] == '#')
		{
			if (piece[i + 1] == '#')
				bound++;
			if (piece[i + 5] == '#')
				bound++;
		}
		i++;
	}
	if (bound >= 3)
		return (1);
	return (0);
}

static int	ft_checkpiece(char *piece)
{
	int i;
	int bloc;

	bloc = 0;
	i = 0;
	while (i < 20)
	{
		if ((i + 1) % 5 == 0 && piece[i] != '\n' && i != 0)
			return (0);
		if (((i != 0 && (i + 1) % 5 != 0) || i == 0) && piece[i] != '.' &&
				piece[i] != '#')
			return (0);
		if (piece[i] == '#')
		{
			bloc++;
			if (!(piece[i - 1] == '#' || piece[i + 1] == '#' ||
				piece[i + 5] == '#' || piece[i - 5] == '#') || bloc > 4)
				return (0);
		}
		i++;
	}
	if (bloc != 4 || piece[i] != '\n')
		return (0);
	return (ft_checkbound(piece));
}

int			ft_checklast(char *file, int i)
{
	char	buf[21 * i];
	int		fd;

	fd = open(file, O_RDONLY);
	buf[21 * i - 1] = '\0';
	read(fd, buf, 21 * i);
	close(fd);
	if (buf[21 * i - 1])
	{
		ft_putendl("error");
		return (0);
	}
	return (1);
}

int			ft_checkfile(char *file)
{
	int		i;
	char	buf[21];
	int		fd;

	i = 0;
	buf[20] = '\n';
	if ((fd = open(file, O_RDONLY)) < 0)
		return (0);
	while (read(fd, buf, 21))
	{
		if (!ft_checkpiece(buf))
		{
			ft_putendl("error");
			return (0);
		}
		ft_memset(buf, 0, 20);
		i++;
	}
	if (i > 26 || i == 0)
	{
		ft_putendl("error");
		return (0);
	}
	close(fd);
	return (ft_checklast(file, i));
}
