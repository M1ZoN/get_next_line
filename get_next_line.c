/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mislamov <mislamov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 15:00:24 by mislamov          #+#    #+#             */
/*   Updated: 2019/09/20 17:06:00 by mislamov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		helper(char **str, char **line, const int fd)
{
	int		index;
	char	*tmp;

	index = 0;
	while (str[fd][index] != '\0' && str[fd][index] != '\n')
		index++;
	if (str[fd][index] == '\n')
	{
		*line = ft_strsub(str[fd], 0, index);
		tmp = ft_strdup(str[fd] + index + 1);
		free(str[fd]);
		str[fd] = tmp;
		if (str[fd][0] == '\0')
			free(str[fd]);
	}
	else if (str[fd][index] == '\0')
	{
		*line = ft_strdup(str[fd]);
		ft_strdel(&str[fd]);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*str[FD_SIZE];
	int			byte_size;
	char		buffer[BUFF_SIZE + 1];
	char		*temp;

	if (fd < 0 || fd > FD_SIZE || !line)
		return (-1);
	if (!str[fd])
		str[fd] = ft_strnew(0);
	while ((byte_size = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[byte_size] = '\0';
		temp = ft_strjoin(str[fd], buffer);
		free(str[fd]);
		str[fd] = temp;
		if (ft_strrchr(str[fd], '\n'))
			break ;
	}
	if (byte_size < 0)
		return (-1);
	else if (str[fd][0] == '\0' && byte_size == 0)
		return (0);
	return (helper(str, line, fd));
}
