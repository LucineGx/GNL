/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_gnl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 15:18:22 by lgaveria          #+#    #+#             */
/*   Updated: 2017/05/31 19:57:13 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoinfree(char **s1, char **s2, int m)
{
	char *r;

	if (*s1 == NULL && *s2 == NULL)
		return (NULL);
	if (*s1 == NULL || *s2 == NULL)
		r = ((*s1 == NULL) ? ft_strdup(*s2) : ft_strdup(*s1));
	else
	{
		if (!(r = malloc(sizeof(char) * (ft_strlen(*s1) + ft_strlen(*s2) + 1))))
			return (NULL);
		r = ft_strcpy(r, *s1);
		r = ft_strcat(r, *s2);
	}
	if ((m == 1 || m == 3) && *s1 != NULL)
	{
		free(*s1);
		*s1 = NULL;
	}
	if ((m == 2 || m == 3) && *s2 != NULL)
	{
		free(*s2);
		*s2 = NULL;
	}
	return (r);
}

t_memfd	*select_fd(t_memfd **lst, const int fd)
{
	t_memfd *tmp;
	t_memfd *newelem;

	tmp = *lst;
	while (tmp && tmp->fd != fd)
		tmp = tmp->next;
	if (tmp)
		return (tmp);
	else
	{
		if (!(newelem = malloc(sizeof(t_memfd))))
			return (NULL);
		newelem->mem = NULL;
		newelem->fd = fd;
		newelem->next = *lst;
		*lst = newelem;
	}
	return (*lst);
}

char	*cut_line(char **line)
{
	char	*mem;
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	tmp = *line;
	while (tmp[i] != '\n' && tmp[i])
		i += 1;
	if (i == (int)ft_strlen(*line))
		return (NULL);
	if (!(mem = malloc(sizeof(char) * ft_strlen(tmp) - i)))
		return (NULL);
	tmp[i] = '\0';
	j = 0;
	while (tmp[++i])
		mem[j++] = tmp[i];
	mem[j] = '\0';
	*line = ft_strdup(tmp);
	if (tmp)
		free(tmp);
	return (mem);
}

int		read_line(int fd, char **line, t_memfd *cur)
{
	int		read_ret;
	char	*buf;

	if (!(buf = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	if ((read_ret = read(fd, buf, BUFF_SIZE)) <= 0 && cur->mem == NULL)
		return (read_ret);
	buf[read_ret] = '\0';
	*line = ft_strjoinfree(&cur->mem, &buf, 1);
	while (!(ft_strchr(*line, '\n')) && read_ret != 0)
	{
		if ((read_ret = read(fd, buf, BUFF_SIZE)) < 0)
			return (-1);
		buf[read_ret] = '\0';
		*line = ft_strjoinfree(line, &buf, 1);
	}
	if (buf)
		free(buf);
	if (ft_strlen(*line) == 0)
		return (0);
	cur->mem = cut_line(line);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static t_memfd	*lst = NULL;
	t_memfd			*cur;
	int				ret;

	cur = select_fd(&lst, fd);
	if (fd < 0 || !line)
		return (-1);
	ret = read_line(fd, line, cur);
	return (ret);
}
