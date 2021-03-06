/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:43:39 by pguthaus          #+#    #+#             */
/*   Updated: 2019/02/08 16:48:42 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include "ft_utils.h"

void			ft_putnbr_fd(int n, int fd)
{
	ft_putnbrl_fd(n, fd, ft_count_digits_int(n));
}
