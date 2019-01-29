/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 12:10:50 by pguthaus          #+#    #+#             */
/*   Updated: 2019/01/29 16:31:05 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include "ft_printf.h"
#include "ft_str.h"

t_bool				ft_parameter_test(t_printf *pf)
{
	pf->format = ft_strnew(10);
	ft_strcpy(pf->format, "123$");
	if (!(ft_is_parameter(pf)))
		return (false);
	ft_strcpy(pf->format, "12a$");
	if (ft_is_parameter(pf))
		return (false);
	return (true);
}

t_bool				ft_flags_test(t_printf *pf)
{
	pf->format = ft_strnew(10);
	ft_strcpy(pf->format, "-");
	if (!(ft_is_flags(pf)))
		return (false);
	ft_strcpy(pf->format, "#");
	if (!(ft_is_flags(pf)))
		return (false);
	ft_strcpy(pf->format, " ");
	if (!(ft_is_flags(pf)))
		return (false);
	ft_strcpy(pf->format, "+");
	if (!(ft_is_flags(pf)))
		return (false);
	ft_strcpy(pf->format, "0");
	if (!(ft_is_flags(pf)))
		return (false);
	ft_strcpy(pf->format, "1a");
	if (ft_is_flags(pf))
		return (false);
	return (true);
}

t_bool	ft_width_test(t_printf *pf)
{
	pf->format = ft_strnew(10);
	ft_strcpy(pf->format, "120");
	if (!(ft_is_width(pf)))
		return (false);
	ft_strcpy(pf->format, "*");
	if (!(ft_is_width(pf)))
		return (false);
	ft_strcpy(pf->format, "dea");
	if (ft_is_width(pf))
		return (false);
	return (true);
}

t_bool	ft_precision_test(t_printf *pf)
{
	pf->format = ft_strnew(10);
	ft_strcpy(pf->format, ".2");
	if (!(ft_is_precision(pf)))
		return (false);
	ft_strcpy(pf->format, ".223");
	if (!(ft_is_precision(pf)))
		return (false);
	ft_strcpy(pf->format, ".*");
	if (!(ft_is_precision(pf)))
		return (false);
	ft_strcpy(pf->format, ".g");
	if (ft_is_precision(pf))
		return (false);
	ft_strcpy(pf->format, "*");
	if (ft_is_precision(pf))
		return (false);
	return (true);
}

t_bool	ft_length_test(t_printf *pf)
{
	pf->format = ft_strnew(10);
	ft_strcpy(pf->format, "hh");
	if (!(ft_is_length(pf)))
		return (false);
	ft_strcpy(pf->format, "h");
	if (!(ft_is_length(pf)))
		return (false);
	ft_strcpy(pf->format, "l");
	if (!(ft_is_length(pf)))
		return (false);
	ft_strcpy(pf->format, "#");
	if (ft_is_length(pf))
		return (false);
	return (true);
}