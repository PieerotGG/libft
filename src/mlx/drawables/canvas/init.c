/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 16:41:15 by pguthaus          #+#    #+#             */
/*   Updated: 2019/03/21 17:17:45 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/canvas.h"

t_canvas				*mlx_init_canvas(t_point2d pos, t_dim2d dim)
{
	t_canvas			*canvas;

	if (!(canvas = malloc(sizeof(t_canvas))))
		return (NULL);
	canvas->s = NULL;
	canvas->zone = ft_zone2d_from_pdim(pos, dim);
	canvas->image = NULL;
	canvas->register_events = mlx_canvas_register_events;
	canvas->img = NULL;
	canvas->keyboard_hooks = NULL;
	canvas->add_keyboard_hook = add_keyboard_hook;
	canvas->image_intern = mlx_canvas_image_intern;
	canvas->background_color = 0x000000;
	return (canvas);
}
