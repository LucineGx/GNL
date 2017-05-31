/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 11:41:16 by lgaveria          #+#    #+#             */
/*   Updated: 2017/01/25 17:53:12 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	size_t	i;

	if ((dest = malloc(sizeof(char) * ft_strlen(s) + 1)) == 0)
		return (0);
	i = 0;
	while (i < ft_strlen(s))
	{
		dest[i] = s[i];
		i += 1;
	}
	dest[ft_strlen(s)] = '\0';
	return (dest);
}
