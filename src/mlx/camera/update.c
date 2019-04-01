/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 15:52:15 by pguthaus          #+#    #+#             */
/*   Updated: 2019/04/01 22:54:16 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/camera.h"

void					mlx_camera_update(t_camera *self)
{
	mlx_camera_update_vecs(self);
	mlx_camera_update_view_mat(self);
}

void					mlx_camera_update_view_mat(t_camera *self)
{
	self->view_mat.raw = (t_mat44_d_data){
		self->vec_right.x, self->vec_right.y, self->vec_right.z, 0,
		self->vec_up.x, self->vec_up.y, self->vec_up.z, 0,
		self->vec_front.x, self->vec_front.y, self->vec_front.z, 0,
		self->position.x, self->position.y, self->position.z, 1
	};
}

void					mlx_camera_update_vecs(t_camera *self)
{
	const double		rad_pitch = ft_degrees_to_radian(self->pitch);
	const double		rad_yaw = ft_degrees_to_radian(self->yaw);

	self->vec_front.x = cos(rad_yaw) * cos(rad_pitch);
	self->vec_front.y = sin(rad_pitch);
	self->vec_front.z = sin(rad_yaw) * cos(rad_pitch);
	self->vec_front = ft_vec3_d_normalize(self->vec_front);
	self->vec_right = ft_vec3_d_normalize(ft_vec3_d_cross(self->vec_front, self->world_up));
	self->vec_up = ft_vec3_d_normalize(ft_vec3_d_cross(self->vec_right, self->vec_front));
}
