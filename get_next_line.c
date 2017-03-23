/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 18:25:15 by lgaveria          #+#    #+#             */
/*   Updated: 2017/03/13 20:29:44 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_strjoin_free(char *s1, char *s2, int m)
{
	char *ret;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL || s2 == NULL)
		ret = ((s1 == NULL) ? ft_strdup(s2) : ft_strdup(s1));
	else
	{
		if (!(ret = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
			return (NULL);
		ret = ft_strcpy(ret, s1);
		ret = ft_strcat(ret, s2);
	}
	if ((m == 1 || m == 3) && s1 != NULL)
		free(s1);
	if ((m == 2 || m == 3) && s2 != NULL)
		free(s2);
	return (ret);
}

int		countchar(char *s)
{
	int i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i += 1;
	return (i);
}

t_memfd	*create_new_elem(t_memfd **lst, const int fd)
{
	t_memfd *tmp;

	if (!*lst)
	{
		if (!(*lst = (t_memfd*)malloc(sizeof(t_memfd))))
			return (NULL);
		(*lst)->fd = fd;
		(*lst)->mem = NULL;
		(*lst)->next = NULL;
	}
	tmp = *lst;
	while (tmp && tmp->fd != fd)
		tmp = tmp->next;
	if (tmp == NULL)
	{
		if (!(tmp = (t_memfd*)malloc(sizeof(t_memfd))))
			return (NULL);
		tmp->fd = fd;
		tmp->mem = NULL;
		tmp->next = NULL;
	}
	return (tmp);
}

char	*get_mem(char *line)
{
	char	*mem;
	int		i;
	int		j;

	i = countchar(line);
	if (i == (int)ft_strlen(line))
		return (NULL);
	if (!(mem = malloc(sizeof(char) * (ft_strlen(line) - i))))
		return (NULL);
	j = 0;
	while (line[++i])
		mem[j++] = line[i];
	mem[j] = '\0';
	return (mem);
}

int		get_next_line(const int fd, char **line)
{
	static t_memfd	*lst = NULL;
	t_memfd			*cur;
	char			*buf;
	int				read_ret;

	cur = create_new_elem(&lst, fd);
	if (!line || !(buf = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	*line = ft_strjoin_free(NULL, cur->mem, 2);
	read_ret = 1;
	while (!(ft_strchr(*line, '\n')) && read_ret != 0)
	{
		if ((read_ret = read(fd, buf, BUFF_SIZE)) == -1)
			return (-1);
		buf[read_ret] = '\0';
		*line = ft_strjoin_free(*line, buf, 1);
	}
	if (ft_strlen(*line) == 0)
		return (0);
	cur->mem = get_mem(*line);
	(*line)[countchar(*line)] = '\0';
	free(buf);
	return (1);
}
