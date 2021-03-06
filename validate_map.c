/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 11:26:02 by fgata-va          #+#    #+#             */
/*   Updated: 2021/02/17 20:14:15 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_check_player(char **map, int lines)
{
	int		i;
	int		j;
	int		fnd;

	fnd = 0;
	i = 0;
	while (i < lines)
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr("NSWE", map[i][j]))
			{
				if (fnd == 1)
					return (0);
				fnd = 1;
			}
			j++;
		}
		i++;
	}
	if (fnd == 0)
		return (0);
	return (1);
}

void		ft_player_pos(t_map *data)
{
	int		i;
	int		j;
	char	**map;

	map = data->map_matrix;
	i = 0;
	while (i < data->max_y)
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr("NSWE", map[i][j]))
			{
				data->player_x = i;
				data->player_y = j;
				ft_set_orientation(map[i][j], data);
			}
			j++;
		}
		i++;
	}
}

void		ft_check_elements(t_map *data)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	map = data->map_matrix;
	while (i < data->max_y)
	{
		j = 0;
		while (map[i][j])
		{
			if (!(ft_strchr("012NSWE ", map[i][j])))
				data->valid_map = 0;
			if (map[i][j] == '2')
				data->num_sprites += 1;
			j++;
		}
		i++;
	}
	if (!ft_check_player(map, data->max_y))
		data->valid_map = 0;
}

void		map_validator(char ***mapa, int x, int y, t_map *data)
{
	char	**map;

	map = *mapa;
	if (data->valid_map == 0 || map[y][x] == '1' || map[y][x] == '3')
		return ;
	if (y == data->max_y - 1 || y == 0 ||
		x == (int)(ft_strlen(map[y]) - 1) || x == 0)
	{
		data->valid_map = 0;
		return ;
	}
	map[y][x] = '3';
	map_validator(mapa, x - 1, y, data);
	map_validator(mapa, x + 1, y, data);
	map_validator(mapa, x, y - 1, data);
	map_validator(mapa, x, y + 1, data);
	map_validator(mapa, x + 1, y + 1, data);
	map_validator(mapa, x - 1, y + 1, data);
	map_validator(mapa, x + 1, y - 1, data);
	map_validator(mapa, x - 1, y - 1, data);
}

int			ft_valid_map(t_map *data)
{
	char	**map_cpy;

	map_cpy = ft_mtxdup(data->map_matrix, data->max_y);
	ft_check_elements(data);
	if (data->valid_map)
	{
		ft_player_pos(data);
		map_validator(&map_cpy, data->player_y, data->player_x, data);
	}
	ft_free_matrix((void **)map_cpy, data->max_y);
	if (!data->valid_map)
		ft_error("Map is not valid");
	return (data->valid_map);
}
