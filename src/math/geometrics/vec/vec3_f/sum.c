/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sum.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 15:32:08 by pguthaus          #+#    #+#             */
/*   Updated: 2019/01/14 19:42:44 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math/vec.h"

t_vec3_f	ft_vec3_f_sum(t_vec3_f self, t_vec3_f vec)
{
	self.x += vec.x;
	self.y += vec.y;
	self.z += vec.z;
	return (self);
}
