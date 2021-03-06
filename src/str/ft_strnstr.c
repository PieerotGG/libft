/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:27:22 by pguthaus          #+#    #+#             */
/*   Updated: 2019/03/14 02:48:47 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned char	*ptr_haystack;
	int				current;
	size_t			len_c;

	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	ptr_haystack = (unsigned char *)haystack;
	len_c = -1;
	while (*ptr_haystack && ++len_c < len)
	{
		current = 0;
		while (*(ptr_haystack + current) == *(needle + current)
			&& (len_c + current < len))
		{
			if (*(needle + current + 1) == '\0')
				return ((char *)ptr_haystack);
			current++;
		}
		ptr_haystack++;
	}
	return (NULL);
}
