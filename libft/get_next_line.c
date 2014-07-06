/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/10 11:34:31 by rduclos           #+#    #+#             */
/*   Updated: 2013/12/22 15:16:10 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

int		get_next_line(int const fd, char **line)
{
	static char		*str;
	char			*buf;
	int				ret;
	size_t			i;

	*line = (char *)malloc(sizeof(char) * 1 + 1);
	buf = ft_strnew(BUF_SIZE);
	while (ft_strchr(buf, '\n') == NULL && (ret = read(fd, buf, BUF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		str = ft_realloc_str(str, ft_strlen(str) + ft_strlen(buf));
		str = ft_strjoin(str, buf);
	}
	if (ret == -1)
		return (-1);
	buf[ret] = '\0';
	i = ft_count_char_befor(str, '\n');
	*line = (char *)malloc(sizeof(char) * i + 1);
	*line = ft_strncpy(*line, str, i);
	str = ft_strchr(str, '\n');
	if (ret == 0 && str == NULL)
		return (0);
	if (str[0] == '\n')
		str++;
	return (1);
}
