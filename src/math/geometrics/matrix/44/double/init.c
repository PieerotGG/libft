/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 19:15:31 by pguthaus          #+#    #+#             */
/*   Updated: 2019/03/18 17:01:38 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math/matrix.h"
#include "ft_mem.h"

static void					fill_with(t_matrix44_d *matrix, double a)
{
	uint8_t					x;
	uint8_t					y;

	y = 0;
	while (y <= 4)
	{
		x = 0;
		while (++x <= 4)
			matrix->matrix[y][x - 1] = a;
		y++;
	}
}

t_matrix44_d				ft_init0_matrix44_d(void)
{
	t_matrix44_d			matrix;

	fill_with(&matrix, 0.0);
	return (matrix);
}

t_matrix44_d				ft_init1_matrix44_d(double a)
{
	t_matrix44_d			matrix;

	fill_with(&matrix, a);
	return (matrix);
}

t_matrix44_d				ft_init44_matrix44_d(t_mat44_d_data data)
{
	return ((t_matrix44_d)data);
}
