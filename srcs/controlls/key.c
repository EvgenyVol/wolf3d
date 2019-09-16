/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoppe <jhoppe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 22:40:02 by jhoppe            #+#    #+#             */
/*   Updated: 2019/09/04 22:40:24 by jhoppe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/wolf3d.h"

bool	key_action(SDL_Event *ev, int32_t key_code, Uint32 press)
{
	if ((ev->type == press && ev->key.keysym.sym == key_code))
		return (true);
	return (false);
}

bool	switch_key(t_window *w, char key, bool *key_tr)
{
	if (key_action(&(w->e), key, SDL_KEYDOWN))
		*key_tr = !*key_tr;
	return (key_tr);
}

bool	handle_key(t_window *w, char key, bool *key_tr)
{
	if (key_action(&(w->e), key, SDL_KEYDOWN))
		*key_tr = true;
	else if (key_action(&w->e, key, SDL_KEYUP))
		*key_tr = false;
	return (key_tr);
}
