/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:24:56 by pguthaus          #+#    #+#             */
/*   Updated: 2018/12/10 04:17:36 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"

void				*ft_memchr(const void *b, int c, size_t len)
{
	size_t			current;
	unsigned char	chr;
	unsigned char	*ptr_b;

	current = -1;
	chr = (unsigned char)c;
	ptr_b = (unsigned char *)b;
	while (++current < len)
	{
		if (*ptr_b == chr)
			return (ptr_b);
		ptr_b++;
	}
	return (NULL);
}
