/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoppe <jhoppe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 22:31:37 by jhoppe            #+#    #+#             */
/*   Updated: 2019/09/05 21:42:45 by jhoppe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int			count_rows_colls(t_window *w, char *path)
{
	int		fd;
	char	*tmp;

	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &tmp) > 0)
	{
		w->map.width = ft_strlen(tmp);
		w->map.height++;
		free(tmp);
	}
	close(fd);
	if (!w->map.height)
		return (1);
	return (0);
}

int			is_correct_wall(t_window *w, Uint32 i, Uint32 j)
{
	if (i == 0 || i == w->map.height - 1 || j == 0 || j == w->map.width - 1)
	{
		if (w->map.block[i][j] < 1 || w->map.block[i][j] > 9)
			return (0);
	}
	return (1);
}

int			read_map(t_window *w, char *path)
{
	int		fd;
	t_u32	i;
	t_u32	j;
	char	*line;

	i = 0;
	if (count_rows_colls(w, path))
		return (1);
	w->map.block = (t_u32 **)malloc(sizeof(t_u32 *) * w->map.height);
	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		j = 0;
		w->map.block[i] = (t_u32 *)malloc(sizeof(t_u32) * w->map.width);
		while (j < w->map.width)
		{
			w->map.block[i][j] = line[j] - '0';
			if (!is_correct_wall(w, i, j))
				return (1);
			j++;
		}
		free(line);
		i++;
	}
	return (0);
}
