/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 10:20:10 by fgata-va          #+#    #+#             */
/*   Updated: 2021/02/03 09:21:27 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		*ft_resize(void *p, size_t oldlen, size_t newlen)
{
	void	*new;

	if (!p)
		return (ft_calloc(newlen, 1));
	if (newlen <= oldlen)
		return (p);
	new = ft_calloc(newlen, 1);
	ft_memcpy(new, p, newlen);
	free(p);
	return (new);
}

char		**ft_newline(char **file, char *line, size_t size)
{
	char	**new_matrix;

	new_matrix = ft_resize(file, size * sizeof(char *), \
						(size + 1) * sizeof(char *));
	new_matrix[size] = line;
	return (new_matrix);
}

int			ft_count_chars(const char *s, char c)
{
	int		i;
	int		fnd;

	i = 0;
	fnd = 0;
	while (s[i])
	{
		if (s[i] == c)
			fnd++;
		i++;
	}
	return (fnd);
}

void		ft_free_all(t_map *data, t_tex *textures, void **file)
{
	ft_free_textures(textures, data);
	ft_free_data(data);
	ft_free_matrix(file, data->lines);
}
