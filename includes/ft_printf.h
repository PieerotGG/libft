/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 03:47:04 by pierre            #+#    #+#             */
/*   Updated: 2018/12/23 09:57:07 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>

typedef struct  s_placeholder_instuction
{
    size_t      (*f)(void *, void *);
    struct s_placeholder_instuction *next;
}               t_ph_inst;

int     ft_printf(const char *format, ...);

#endif