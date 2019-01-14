/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   at.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 16:06:19 by pguthaus          #+#    #+#             */
/*   Updated: 2019/01/14 19:29:09 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math/vec.h"

double		ft_vec3_d_at(t_vec3_d self, uint8_t i)
{
	if (i == 0)
		return (self.x);
	if (i == 1)
		return (self.y);
	if (i == 2)
		return (self.z);
	else
		return (0);
}
