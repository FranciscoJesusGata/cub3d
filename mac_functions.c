/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mac_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 11:09:11 by fgata-va          #+#    #+#             */
/*   Updated: 2020/12/23 11:11:02 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		loadTexture(t_map *data, t_tex_img *texture, char *path)
{
	if (ft_check_extension(path, ".xpm"))
		texture->img.img = mlx_xpm_file_to_image(data->mlx_ptr, path, &texture->width, &texture->height);
	else
		texture->img.img = mlx_png_file_to_image(data->mlx_ptr, path, &texture->width, &texture->height);
	texture->img.addr = mlx_get_data_addr(texture->img.img, &texture->img.bpp, &texture->img.line_length, &texture->img.endian);
}