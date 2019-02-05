/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 23:39:08 by pguthaus          #+#    #+#             */
/*   Updated: 2019/02/05 13:57:02 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_str.h"

static void				integer(t_printf *state)
{
	char				c;
	
	c = *(state->format);
	if (c == 'd' || c == 'i')
		state->part.modifier = CSINT;
	if (c == 'o')
		state->part.modifier = CUOCT;
	if (c == 'u')
		state->part.modifier = CUINT;
	if (c == 'x')
		state->part.modifier = CUMHX;
	if (c == 'X')
		state->part.modifier = CUHEX;
}

static void				doubled(t_printf *state)
{
	char				c;
	
	c = *(state->format);
	if (c == 'a')
		state->part.modifier = CDMHX;
	if (c == 'A')
		state->part.modifier = CDHEX;
	if (c == 'e')
		state->part.modifier = CDMEX;
	if (c == 'E')
		state->part.modifier = CDEXP;
	if (c == 'f' || c == 'F')
		state->part.modifier = CDDEC;
	if (c == 'g')
		state->part.modifier = CDMGE;
	if (c == 'G')
		state->part.modifier = CDGEN;
}

static void				alpha(t_printf *state)
{
	char				c;
	
	c = *(state->format);
	if (c == 'c')
		state->part.modifier = CACHR;
	if (c == 's')
		state->part.modifier = CASTR;
}

void					ft_apply_type(t_printf *state)
{
	if (ft_strchr(INT_MODIFIERS, *state->format))
		integer(state);
	if (ft_strchr(DOUBLE_MODIFIERS, *state->format))
		doubled(state);
	if (ft_strchr(ALPHA_MODIFIERS, *state->format))
		alpha(state);
	if (*state->format == '%')
		state->part.modifier = CXXXX;
	state->format++;
}
