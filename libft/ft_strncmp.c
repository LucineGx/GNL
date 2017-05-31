/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 17:38:34 by lgaveria          #+#    #+#             */
/*   Updated: 2016/12/07 18:46:21 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (ft_strlen(s1) < n || ft_strlen(s2) < n)
		return (ft_strcmp(s1, s2));
	else
		return (ft_strcmp(ft_strsub(s1, 0, n), ft_strsub(s2, 0, n)));
}
