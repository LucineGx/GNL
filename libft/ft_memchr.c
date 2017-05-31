/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 19:40:17 by lgaveria          #+#    #+#             */
/*   Updated: 2016/12/01 16:32:26 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*memar;

	i = 0;
	memar = (unsigned char *)s;
	while (i < n)
	{
		if (memar[i] == (unsigned char)c)
			return ((void *)(s + i));
		i += 1;
	}
	return (0);
}
