/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 10:47:02 by tmerli            #+#    #+#             */
/*   Updated: 2017/12/02 20:53:39 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRIMINOS_H
# define TETRIMINOS_H

typedef struct	s_point
{
	int x;
	int y;
}				t_point;

typedef t_point* t_tetriminos;

t_tetriminos	*ft_gettetriminos(char **tab, int size);
int				ft_checkfile(char *file);
char			**ft_readfile(char *file);
t_tetriminos	*ft_alloc(int size);
int				ft_place(t_tetriminos *t, char *map, int i, int min_size);
int				ft_move(t_tetriminos t, int min_size);
int				ft_minsize(int i, t_tetriminos *t);
void			ft_display(char *map, int size);
void			ft_piece(t_tetriminos t);
void			ft_resetx(t_tetriminos t);
int				ft_reset(t_tetriminos t);

#endif
