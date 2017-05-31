/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 17:19:04 by lgaveria          #+#    #+#             */
/*   Updated: 2016/12/07 19:24:07 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ret;
	unsigned int	i;

	if (!s || (ret = malloc(sizeof(char) * (ft_strlen(s) + 1))) == 0)
		return (0);
	i = 0;
	while (s[i])
	{
		ret[i] = f(i, s[i]);
		i += 1;
	}
	ret[i] = '\0';
	return (ret);
}
