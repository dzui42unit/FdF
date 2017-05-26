/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 16:19:37 by dzui              #+#    #+#             */
/*   Updated: 2017/02/02 17:52:01 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft.h"
# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>
# define BUFF_SIZE 1

int			get_next_line(const int fd, char **line);
void		make_string(char **s1, char *s2, int n1, int n2);
int			write_line(char **buff, char **line, int *i, const int fd);

#endif
