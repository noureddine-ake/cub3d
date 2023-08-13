/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboulgh <oaboulgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:53:08 by nakebli           #+#    #+#             */
/*   Updated: 2023/08/08 19:16:18 by oaboulgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARCING_H
# define PARCING_H

# include "./../cub3d.h"

char	*get_next_line(int fd);
int		ft_atoi(const char *str);
int		is_map_line(char *line);
t_info	*parcing(char *av, t_cubt **cub);
t_cubt	*ft_lstlast(t_cubt *lst);
void	ft_lstadd_back(t_cubt **lst, t_cubt *new);
t_cubt	*ft_lstnew(char *line, t_info *info, t_cubt *prev);
char	*ft_strtrim(char const *s1, char const *set);
void	check_cardinal_direction(t_cubt *cub);
char	**ft_split(char	const *s, char c);
char	*ft_strchr(const char *str, int c);
void	delte_empty_lines(t_cubt **cub);
void	print_errors(char *str);
int		ft_strcmp(char *s1, char *s2);
int		towd_arr_size(char **arr);
void	print_args(t_info *info);

#endif