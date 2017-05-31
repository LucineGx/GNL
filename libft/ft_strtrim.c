/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 18:22:21 by lgaveria          #+#    #+#             */
/*   Updated: 2016/12/10 14:01:29 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ctchars(char const *s)
{
	size_t	count;
	size_t	i;
	size_t	tmp;

	count = 0;
	if (!s)
		return (0);
	while (ft_iswhitespace(s[count]) && s[count])
		count += 1;
	i = ft_strlen(s) - 1;
	tmp = count;
	while (ft_iswhitespace(s[i]) && i >= tmp)
	{
		i -= 1;
		count += 1;
	}
	return (count);
}

char			*ft_strtrim(char const *s)
{
	unsigned int	start;
	char			*str;
	size_t			len;

	start = 0;
	if (!s)
	{
		str = (char*)malloc(sizeof(char));
		str[0] = '\0';
		return (str);
	}
	len = ft_strlen(s) - ctchars(s);
	if (len == ft_strlen(s))
		return (ft_strdup(s));
	if (len == 0)
	{
		str = (char*)malloc(sizeof(char));
		str[0] = '\0';
		return (str);
	}
	while (ft_iswhitespace(s[start]))
		start++;
	str = ft_strsub(s, start, len);
	return (str);
}
