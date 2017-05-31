/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:53:16 by lgaveria          #+#    #+#             */
/*   Updated: 2016/12/07 19:09:25 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t ld;
	size_t ls;

	ld = ft_strlen(dest);
	ls = ft_strlen(src);
	if (ld >= size)
		return (size + ls);
	else
	{
		ft_strncat(dest, src, size - ld - 1);
		return (ls + ld);
	}
}
