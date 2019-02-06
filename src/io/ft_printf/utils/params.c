/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 18:09:56 by pguthaus          #+#    #+#             */
/*   Updated: 2019/02/06 22:44:56 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void				ft_next_in_va_list(t_printf *state, va_list list)
{
	if (state->part.modifier == CASTR)
		state->part.value.str = va_arg(list, char *);
	if (state->part.modifier == CACHR)
		state->part.value.i = (intmax_t)va_arg(list, int);
	if (state->part.modifier == CAWCH)
		state->part.value.i = (intmax_t)va_arg(list, wchar_t);
	if (state->part.modifier == CSINT)
		state->part.value.i = va_arg(list, intmax_t);
	if (state->part.modifier == CUOCT)
		state->part.value.i = (intmax_t)va_arg(list, uintmax_t);
	if (state->part.modifier == CUINT)
		state->part.value.i = (intmax_t)va_arg(list, uintmax_t);
}

void					ft_next_param(t_printf *state)
{
	ft_next_in_va_list(state, state->it_params);
}

void					ft_iparam(t_printf *state)
{
	va_list				node;
	size_t				current;

	va_copy(node, state->params);
	current = 0;
	while (current < state->part.nu)
		current++;
	ft_next_in_va_list(state, node);
	va_end(node);
}
