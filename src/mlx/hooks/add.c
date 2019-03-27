/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 18:27:36 by pguthaus          #+#    #+#             */
/*   Updated: 2019/03/27 19:02:55 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/hooks.h"

void				mlx_add_keyhook(t_keyboard_hooks *hooks, int key,
		t_onpress onpress, void *s)
{
	hooks->hooks[hooks->len] = (t_keyboard_hook){ key, onpress, s };
	hooks->len++;
}

void				mlx_add_mousehook(t_mouse_hooks *hooks, int id,
		t_zone2d zone, t_onclick onclick, void *s)
{
	hooks->hooks[hooks->len] = (t_mouse_hook){ zone, id, onclick, s };
	hooks->len++;
}

void				mlx_add_motionhook(t_motion_hooks *hooks, t_zone2d zone,
		t_onmotion onmotion, void *s)
{
	hooks->hooks[hooks->len] = (t_motion_hook){ zone, onmotion, s };
	hooks->len++;
}
