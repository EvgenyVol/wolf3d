/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoppe <jhoppe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 19:00:26 by jhoppe            #+#    #+#             */
/*   Updated: 2019/09/04 22:09:54 by jhoppe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	print_num(t_window *w, unsigned int num, SDL_Rect buf, bool percent)
{
	if (num == ((unsigned int)-1))
		num = 0;
	if (percent)
	{
		w->ui.digit[10]->rect.x = buf.x + 3 * DELTA_X;
		w->ui.digit[10]->rect.y = buf.y;
		render_scale(w, w->ui.digit[10]);
	}
	if (num == 0)
	{
		buf.x -= DELTA_X;
		w->ui.digit[(num % 10)]->rect.x = buf.x + 3 * DELTA_X;
		w->ui.digit[(num % 10)]->rect.y = buf.y;
		render_scale(w, w->ui.digit[(num % 10)]);
	}
	while (num)
	{
		buf.x -= DELTA_X;
		w->ui.digit[(num % 10)]->rect.x = buf.x + 3 * DELTA_X;
		w->ui.digit[(num % 10)]->rect.y = buf.y;
		render_scale(w, w->ui.digit[(num % 10)]);
		num /= 10;
	}
}

void	print_framerate(t_window *w)
{
	SDL_Rect buf;

	buf.x = 25;
	buf.y = buf.x;
	print_num(w, ((int)(1.0 / w->ftime.delta)), buf, false);
}

void	ui_bar(t_window *w)
{
	SDL_Rect buf;

	buf.y = UI_Y;
	render_scale(w, &(w->ui.bar));
	buf.x = AMMO_X;
	print_num(w, w->riffle.ammo, buf, false);
	buf.x = HEALTH_X;
	print_num(w, 100, buf, true);
	buf.x = FRAGS_X;
	print_num(w, 0, buf, false);
	buf.x = ARMOR_X;
	print_num(w, 25, buf, true);
	if (!w->pause && w->controls.p)
		print_framerate(w);
}
