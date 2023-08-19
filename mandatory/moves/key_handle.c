/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboulgh <oaboulgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 19:09:59 by nakebli           #+#    #+#             */
/*   Updated: 2023/08/19 18:48:02 by oaboulgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_2d(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_info(t_cub *info)
{
	free_2d(info->info->no);
	free_2d(info->info->ea);
	free_2d(info->info->so);
	free_2d(info->info->we);
	free(info->info);
}

int	handle_keypress(int keycode, void *param)
{
	t_cub	*info;

	info = (t_cub *)param;
	if (keycode == 53)
	{
		mlx_destroy_window(info->mlx, info->mlx_win);
		free_info(info);
		exit (0);
	}
	if (keycode == 36 && check_d2(info) == 1)
		info->player->open = 1;
	else if (keycode == 51 && check_d2(info) == 2)
		info->player->open = 0;
	else if (keycode == 0)
		info->player->move_forward_l = 1;
	else if (keycode == 2)
		info->player->move_forward_r = 1;
	else if (keycode == 49 && !info->player->stop)
		info->player->shot = 1;
	else if (keycode == 13)
		info->player->move_forward = 1;
	else if (keycode == 1)
		info->player->move_backward = 1;
	else if (keycode == 123)
		info->player->rotate_left = 1;
	else if (keycode == 124)
		info->player->rotate_right = 1;
	return (0);
}

int	handle_keyrelease(int keycode, void *param)
{
	t_cub	*info;

	info = (t_cub *)param;
	if (keycode == 0)
		info->player->move_forward_l = 0;
	if (keycode == 2)
		info->player->move_forward_r = 0;
	if (keycode == 49)
	{
		info->player->shot = 0;
		info->player->stop = 0;
	}
	if (keycode == 13)
		info->player->move_forward = 0;
	else if (keycode == 1)
		info->player->move_backward = 0;
	else if (keycode == 123)
		info->player->rotate_left = 0;
	else if (keycode == 124)
		info->player->rotate_right = 0;
	return (0);
}

int	get_sign(float nbr)
{
	if (nbr >= 0)
		return (1);
	return (-1);
}

int	long_line(char **map)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	x = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (j > x)
			x = j;
		i++;
	}
	return (x);
}

int	height_of_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}