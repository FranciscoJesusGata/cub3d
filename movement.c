/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 00:24:03 by fgata-va          #+#    #+#             */
/*   Updated: 2021/02/11 16:38:09 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_bonus.h"

void			vertical_move(t_map *data, double move_x, double move_y)
{
	int			pos[2];

	if (data->movement->forward == 1)
	{
		pos[0] = data->map_matrix[(int)(data->player_x + move_x)]\
			[(int)data->player_y];
		pos[1] = data->map_matrix[(int)data->player_x]\
			[(int)(data->player_y + move_y)];
		if (pos[0] == '0')
			data->player_x += move_x;
		if (pos[1] == '0')
			data->player_y += move_y;
	}
	if (data->movement->backward == 1)
	{
		pos[0] = data->map_matrix[(int)(data->player_x - move_x)]\
			[(int)data->player_y];
		pos[1] = data->map_matrix[(int)data->player_x][\
			(int)(data->player_y - move_y)];
		if (pos[0] == '0')
			data->player_x -= move_x;
		if (pos[1] == '0')
			data->player_y -= move_y;
	}
}

void			horizontal_move(t_map *data, double move_x, double move_y)
{
	int			pos[2];

	if (data->movement->left == 1)
	{
		pos[0] = data->map_matrix[(int)(data->player_x - move_y)]\
			[(int)data->player_y];
		pos[1] = data->map_matrix[(int)data->player_x]\
			[(int)(data->player_y + move_x)];
		if (pos[0] == '0')
			data->player_x -= move_y;
		if (pos[1] == '0')
			data->player_y += move_x;
	}
	if (data->movement->right == 1)
	{
		pos[0] = data->map_matrix[(int)(data->player_x + move_y)]\
			[(int)data->player_y];
		pos[1] = data->map_matrix[(int)data->player_x]\
			[(int)(data->player_y - move_x)];
		if (pos[0] == '0')
			data->player_x += move_y;
		if (pos[1] == '0')
			data->player_y -= move_x;
	}
}

void			ft_move(t_map *data)
{
	double		move_speed;
	double		move_x;
	double		move_y;

	move_speed = 0.2;
	if (data->movement->crouch == 1)
		move_speed -= 0.1;
	move_x = data->dir[0] * move_speed;
	move_y = data->dir[1] * move_speed;
	vertical_move(data, move_x, move_y);
	horizontal_move(data, move_x, move_y);
}

void			ft_rotate(t_map *data)
{
	double		rotspeed;
	double		olddir_x;
	double		oldplane_x;

	rotspeed = 0.017 * 3;
	olddir_x = data->dir[0];
	oldplane_x = data->plane[0];
	if (data->movement->r_rotation != \
		data->movement->l_rotation)
	{
		if (data->movement->r_rotation == 1)
			rotspeed *= -1;
		data->dir[0] = olddir_x * cos(rotspeed) \
					- data->dir[1] * sin(rotspeed);
		data->dir[1] = olddir_x * sin(rotspeed) \
					+ data->dir[1] * cos(rotspeed);
		data->plane[0] = oldplane_x * cos(rotspeed) \
					- data->plane[1] * sin(rotspeed);
		data->plane[1] = oldplane_x * sin(rotspeed) \
					+ data->plane[1] * cos(rotspeed);
	}
}
