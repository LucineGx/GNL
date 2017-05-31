/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 18:14:06 by lgaveria          #+#    #+#             */
/*   Updated: 2017/01/17 15:12:36 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;

	if (s1 == NULL || s2 == NULL)
	{
		if (s1 == NULL && s2 != NULL)
			return (ft_strdup(s2));
		else if (s2 == NULL && s1 != NULL)
			return (ft_strdup(s1));
		else
			return (NULL);
	}
	if ((ret = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))) == 0)
		return (0);
	ret = ft_strcpy(ret, s1);
	return (ft_strcat(ret, s2));
}
