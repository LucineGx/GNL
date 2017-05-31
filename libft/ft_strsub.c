/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 18:08:15 by lgaveria          #+#    #+#             */
/*   Updated: 2017/01/14 11:44:23 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*ret;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	if ((ret = malloc(sizeof(char) * (len + 1))) == 0)
		return (0);
	i = start;
	while (i - start < len)
	{
		ret[i - start] = s[i];
		i += 1;
	}
	ret[i - start] = '\0';
	return (ret);
}
