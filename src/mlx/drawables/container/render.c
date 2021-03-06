/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 21:38:53 by pguthaus          #+#    #+#             */
/*   Updated: 2019/04/09 17:20:34 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/drawables.h"
#include "ft_mlx/window.h"
#include <mlx.h>

void					mlx_container_render_txt(t_container *container,
		t_point2d offset, void *win)
{
	const t_point2d		next_offset = DDSUM(offset, container->pos);
	size_t				current;
	t_drawable			drawable;
	t_drwble			obj;

	current = 0;
	while (container->childs && current < container->childs->len)
	{
		drawable = container->childs->drawables[current];
		obj = drawable.drawable;
		if (drawable.type == CONTAINER)
			mlx_container_render_txt(obj.container, next_offset, win);
		if (drawable.type == TEXT)
			obj.text->render_txt(obj.text, next_offset, win);
		if (drawable.type == BUTTON)
			obj.button->render_txt(obj.button, next_offset, win);
		if (drawable.type == PAGINATION)
			obj.pagination->render_txt(obj.pagination, next_offset, win);
		if (drawable.type == CANVAS)
			obj.canvas->register_events(obj.canvas, next_offset, win);
		current++;
	}
}

t_image_carry			*mlx_container_render(t_container *container,
		void *win, t_image_carry *old)
{
	const t_window		*window = win;
	void				*tmptr;
	char				*tmpch;
	int					parms[3];

	if (!old)
	{
		tmptr = mlx_new_image(window->mlx, window->width, window->height);
		tmpch = mlx_get_data_addr(tmptr, &parms[0], &parms[1], &parms[2]);
		old = ft_image_carry_from(tmptr, tmpch, parms[0], parms[1], parms[2]);
	}
	else
	{
		tmpch = mlx_get_data_addr(old->img_ptr, &parms[0], &parms[1], &parms[2]);
		old = ft_image_carry_from(old->img_ptr, tmpch, parms[0], parms[1], parms[2]);
	}
	old->data = container->image(container, POS(0, 0), old);
	mlx_put_image_to_window(window->mlx, window->ptr, old->img_ptr, 0, 0);
	container->render_txt(container, POS(0, 0), win);
	return (old);
}
