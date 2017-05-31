/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 11:46:26 by lgaveria          #+#    #+#             */
/*   Updated: 2016/11/10 11:50:12 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	while (dest[i])
		i += 1;
	j = i;
	while (i - j < n && src[i - j])
	{
		dest[i] = src[i - j];
		i += 1;
	}
	dest[i] = '\0';
	return (dest);
}
