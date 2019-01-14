/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 15:48:48 by pguthaus          #+#    #+#             */
/*   Updated: 2019/01/14 18:23:57 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math/vec.h"

float		ft_vec2_f_norm(t_vec2_f self)
{
	return (self.x * self.x + self.y * self.y);
}
