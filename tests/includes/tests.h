/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 20:37:55 by pguthaus          #+#    #+#             */
/*   Updated: 2019/03/14 02:57:02 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H
# include "ft_bool.h"
# include <stdint.h>
# include <stdio.h>
# include "ft_printf.h"

typedef struct		s_mlx_state
{
	void			*mlx;
	void			*win;
	void			*cwin;
	void			(*curr_test)(struct s_mlx_state *);
}					t_mlx_state;

/*
** Printf
*/
void	ft_printf_test();

t_bool	ft_parameter_test(t_printf *pf);

t_bool	ft_flags_test(t_printf *pf);

t_bool	ft_width_test(t_printf *pf);

t_bool	ft_precision_test(t_printf *pf);

t_bool	ft_length_test(t_printf *pf);

#endif
