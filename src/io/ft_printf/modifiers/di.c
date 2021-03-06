/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   di.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 16:12:02 by pguthaus          #+#    #+#             */
/*   Updated: 2019/03/13 21:14:53 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_utils.h"

/*
** Flags: 0/-/ /+/'
** Width
** Precision
** Lengths
*/

static void				ft_print_signed_int_pf(t_printf *state, size_t p_length,
		size_t length, uint32_t width)
{
	intmax_t			i;

	i = (int)state->part.value.i;
	if (ft_test_flag(state, FSIGN) || ft_test_flag(state, FPOSI))
		if (i >= 0)
			ft_putchar_fd((ft_test_flag(state, FSIGN) ? '+' : ' '), state->fd);
	if (ft_test_flag(state, FFIL0) && p_length == length)
		ft_print_0(state, width - p_length);
	ft_print_precised_int(state, i, length, p_length);
}

static size_t			ft_adjust_length(t_printf *state, size_t length)
{
	if ((ft_test_flag(state, FSIGN) || ft_test_flag(state, FPOSI))
			&& (int)state->part.value.i >= 0)
		length++;
	else if ((int)state->part.value.i < 0)
		length++;
	return (length);
}

void					ft_pfdi(t_printf *state)
{
	size_t				length;
	uint32_t			width;
	size_t				p_length;

	length = ft_adjust_length(state,
			ft_count_digits_int((int)state->part.value.i));
	width = state->part.width;
	if (width < length)
		width = length;
	p_length = length;
	if (state->part.precision > length)
		p_length = ft_adjust_length(state, state->part.precision);
	if (ft_test_flag(state, FLEFT))
	{
		ft_print_signed_int_pf(state, p_length, length, width);
		ft_print_blank(state, width - p_length);
	}
	else if (ft_test_flag(state, FFIL0) && p_length == length)
		ft_print_signed_int_pf(state, p_length, length, width);
	else
	{
		ft_print_blank(state, width - p_length);
		ft_print_signed_int_pf(state, p_length, length, width);
	}
	state->length += width;
}
