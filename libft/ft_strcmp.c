/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 11:35:39 by lgaveria          #+#    #+#             */
/*   Updated: 2016/11/30 18:12:02 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*uc1;
	unsigned char	*uc2;

	uc1 = (unsigned char *)s1;
	uc2 = (unsigned char *)s2;
	i = 0;
	while (uc2[i])
	{
		if (uc1[i] != uc2[i])
			return (uc1[i] - uc2[i]);
		i += 1;
	}
	if (!(uc1[i]))
		return (0);
	else
		return (uc1[i] - uc2[i]);
}
