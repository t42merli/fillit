/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 15:24:37 by tmerli            #+#    #+#             */
/*   Updated: 2017/12/02 20:28:25 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "tetriminos.h"

void	ft_display(char *disp, int size)
{
	int i;

	i = 0;
	disp[size * size] = '\0';
	while (disp[i])
	{
		if (i != 0 && i % size == 0)
			ft_putchar('\n');
		ft_putchar(disp[i]);
		i++;
	}
	ft_putchar('\n');
}
