/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 17:15:37 by lgaveria          #+#    #+#             */
/*   Updated: 2016/12/07 19:23:40 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ret;
	int		i;

	if (!s || (ret = malloc(sizeof(char) * (ft_strlen(s)) + 1)) == 0)
		return (0);
	i = 0;
	while (s[i])
	{
		ret[i] = f(s[i]);
		i += 1;
	}
	ret[i] = '\0';
	return (ret);
}
