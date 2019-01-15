/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 15:48:48 by pguthaus          #+#    #+#             */
/*   Updated: 2019/01/14 19:51:09 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math/vec.h"

int32_t		ft_vec3_i32_norm(t_vec3_i32 self)
{
	return (self.x * self.x + self.y * self.y + self.z * self.z);
}