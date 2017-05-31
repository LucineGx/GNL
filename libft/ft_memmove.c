/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 19:33:12 by lgaveria          #+#    #+#             */
/*   Updated: 2016/11/24 16:43:51 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t i;

	i = 0;
	if (&(*dest) == &(*src))
		return (dest);
	else if (&(*dest) > &(*src))
		ft_memcpy(dest, src, n);
	else
	{
		while (i < n)
		{
			*(char *)(dest + i) = *(char *)(src + i);
			i += 1;
		}
	}
	return (dest);
}
