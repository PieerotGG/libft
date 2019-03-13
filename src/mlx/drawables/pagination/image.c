/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre </var/spool/mail/pierre>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 17:53:28 by pierre            #+#    #+#             */
/*   Updated: 2019/03/13 17:21:29 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/drawables.h"

static char				*pagination_bottom_image(t_pagination *self, t_point2d p_offset, t_image_carry *carry)
{
	t_point2d			offset;

	offset.y = p_offset.y + self->zone.dim.height - MLX_PAGINATION_BOT_SIZE;
	offset.x = p_offset.x;
	*carry->data = self->prev->image(self->prev, offset, carry);
	*carry->data = self->next->image(self->next, offset, carry);
	return (*carry->data);
}

char					*mlx_pagination_image(t_pagination *self, t_point2d p_offset, t_image_carry *carry)
{
	t_point2d			offset;
	t_point2d			next_offset;
	t_drawables			*node;
	t_zone2d			gride;
	size_t				current;

	offset = DDSUM(p_offset, self->zone.pos);
	gride = ft_zone2d_from_pdim(POS(0, 0), mlx_pagination_gride_dims(self));
	node = self->items;
	current = 0;
	while (current++ < self->page * (self->gride.width * self->gride.height))
		node = node->next;
	while (gride.pos.y < (int)gride.dim.height && node)
	{
		gride.pos.x = 0;
		while (gride.pos.x < (int)gride.dim.width && node)
		{
			next_offset = mlx_pagination_offset(self, offset, gride, true);
			ft_image_merge(ft_drawable_at(self->items, (gride.pos.y * gride.dim.width) + gride.pos.x), next_offset, carry);
			gride.pos.x++;
		}
		gride.pos.y++;
	}
	*carry->data = pagination_bottom_image(self, offset, carry);
	return (*carry->data);
}
