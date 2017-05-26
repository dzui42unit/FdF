/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:31:22 by dzui              #+#    #+#             */
/*   Updated: 2017/02/02 17:51:53 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <time.h>

void	make_string(char **s1, char *s2, int n1, int n2)
{
	char	*temp;
	int		i;
	int		j;

	temp = ft_strdup(*s1);
	*s1 = ft_strnew(ft_strlen(*s1) + (n2 - n1));
	ft_strcpy(*s1, temp);
	j = n1;
	i = ft_strlen(*s1);
	while (j < n2)
	{
		(*s1)[i] = s2[j];
		j++;
		i++;
	}
	free(temp);
}

int		find_newl(char *str, int *i)
{
	while (str[*i])
	{
		if (str[*i] == '\n')
			return (1);
		(*i)++;
	}
	return (0);
}

void	set_var(char *buff, int *i, int *prev, int flag)
{
	if (flag == 1)
	{
		*i = 0;
		*prev = *i;
	}
	else
	{
		if (buff[*i] == '\n')
		{
			(*i)++;
			*prev = (*i);
		}
	}
}

int		write_line(char **buff, char **line, int *i, const int fd)
{
	static int prev;
	static int ch_r;

	if (!(*buff)[*i])
	{
		if ((ch_r = read(fd, *buff, BUFF_SIZE)) < 0)
			return (-1);
		if ((ch_r == 0) && !((*buff)[*i]))
			return (0);
		set_var(*buff, i, &prev, 1);
	}
	*line = ft_strnew(1);
	while (!find_newl(*buff, i))
	{
		make_string(line, *buff, prev, *i);
		ft_strclr(*buff);
		if ((ch_r = read(fd, *buff, BUFF_SIZE)) < 0)
			return (-1);
		if (ch_r == 0)
			break ;
		set_var(*buff, i, &prev, 1);
	}
	make_string(line, *buff, prev, *i);
	set_var(*buff, i, &prev, 0);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char		*buff;
	static int		i;
	int				res;

	if (fd < 0 || !(line))
		return (-1);
	if (!buff)
	{
		buff = ft_strnew(BUFF_SIZE);
	}
	res = write_line(&buff, line, &i, fd);
	if (res == 1)
	{
		return (1);
	}
	if (res == -1)
	{
		return (-1);
	}
	return (0);
}
