/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoppe <jhoppe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 18:04:02 by jhoppe            #+#    #+#             */
/*   Updated: 2019/09/05 21:42:06 by jhoppe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

bool	get_tga_info(char *path)
{
	int		fd;
	t_u8	info[18];

	if ((fd = open(path, O_RDONLY)) == -1)
		return (open_error(path));
	read(fd, info, 18);
	close(fd);
	return (1);
}

bool	open_error(char *path)
{
	perror(path);
	return (0);
}

bool	mem_error(TGA *tga)
{
	if (tga->data)
		free(tga->data);
	return (0);
}

bool	unsupported_error(TGA *tga)
{
	free(tga->data);
	return (0);
}
