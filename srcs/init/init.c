/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoppe <jhoppe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 22:32:41 by jhoppe            #+#    #+#             */
/*   Updated: 2019/09/04 22:26:31 by jhoppe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	init_player(t_window *w)
{
	w->player.pos.x = 0;
	w->player.pos.y = 0;
	w->player.dir.x = -1;
	w->player.dir.y = 0;
	w->player.plane.x = 0;
	w->player.plane.y = 0.66;
	w->player.rotation = 0.05;
	w->player.speed = 0.05;
	w->player.pos.x = 3;
	w->player.pos.y = 3;
}

void	init_controls(t_window *w)
{
	w->controls.w = false;
	w->controls.a = false;
	w->controls.s = false;
	w->controls.d = false;
	w->controls.q = false;
	w->controls.e = false;
	w->controls.p = false;
}

void	init_riffle(t_window *w)
{
	w->riffle.rect.w = w->riffle.fraps[0]->img->width * 2;
	w->riffle.rect.h = w->riffle.fraps[0]->img->height * 2;
	w->riffle.rect.x = w->width / 2 - w->riffle.rect.w / 2;
	w->riffle.rect.y = w->height - w->riffle.rect.h + 40;
}

void	init_sky(t_window *w)
{
	w->sky.rect.x = 0;
	w->sky.rect.y = 0;
	w->sky.rect.w = w->width;
	w->sky.rect.h = w->height / 2;
}

int		global_init(t_window *w)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		return (1);
	w->height = HEIGHT - 120;
	w->width = WIDTH;
	w->map.width = 0;
	w->map.height = 0;
	w->map.x = 0;
	w->map.y = 0;
	init_player(w);
	init_controls(w);
	init_sky(w);
	w->riffle.shoot = 0;
	w->riffle.tr = 0;
	w->riffle.ammo = 25;
	w->riffle.busy_anim = false;
	w->riffle.active = false;
	w->riffle.pos.x = 0;
	w->riffle.pos.y = 0;
	w->power = true;
	w->ui.position = 0;
	w->ui.clicked = false;
	return (0);
}
