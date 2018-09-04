/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 14:43:40 by msukhare          #+#    #+#             */
/*   Updated: 2017/11/22 16:09:56 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct			s_tetris
{
	char				letter;
	char				**piece;
	int					pos[4][2];
	int					extrem[2];
	struct s_tetris		*next;
}						t_tetris;

t_tetris				*ft_readfile(char *str);
int						ft_countsize(char *str);
void					ft_checkerror1(char *str);
void					ft_checkerror2(char *str);
void					ft_checkerror3(t_tetris *begin_list);
void					ft_error(void);
t_tetris				*ft_lstsplit(char *str, int size);
void					ft_posrela(t_tetris *begin_list);
int						ft_nblinks(t_tetris *list);
char					**ft_map(int sidelen);
void					ft_printmap(char **map, int size);
int						ft_resolve(char **map, t_tetris *list, int size);
int						ft_maplen(t_tetris *lst);
void					ft_freeall(t_tetris *begin_list, char **map, int size);
void					ft_error_usage(void);
#endif
