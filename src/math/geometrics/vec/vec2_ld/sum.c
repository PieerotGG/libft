/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sum.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 15:32:08 by pguthaus          #+#    #+#             */
/*   Updated: 2019/01/14 19:48:32 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math/vec.h"

t_vec2_ld		ft_vec2_ld_sum(t_vec2_ld self, t_vec2_ld vec)
{
	self.x += vec.x;
	self.y += vec.y;
	return (self);
}
