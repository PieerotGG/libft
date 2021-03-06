/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 16:36:07 by pguthaus          #+#    #+#             */
/*   Updated: 2019/03/18 18:36:43 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math/vec.h"

t_vec3_f				ft_vec3_f_cross(t_vec3_f self, t_vec3_f vec)
{
	return ((t_vec3_f){ self.y * vec.z - self.z * vec.y,
						self.z * vec.x - self.x * vec.z,
						self.x * vec.y - self.y * vec.x });
}
