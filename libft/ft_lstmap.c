/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 12:08:42 by lgaveria          #+#    #+#             */
/*   Updated: 2016/11/24 14:00:45 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_list;
	t_list	*tmp;

	tmp = lst;
	new_list = NULL;
	if (tmp != NULL)
	{
		new_list = f(tmp);
		new_list->next = ft_lstmap(tmp->next, f);
	}
	return (new_list);
}
