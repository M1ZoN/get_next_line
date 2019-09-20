/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mislamov <mislamov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 15:00:33 by mislamov          #+#    #+#             */
/*   Updated: 2019/09/19 23:49:21 by mislamov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32
# define FD_SIZE 10240
# include "libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

int get_next_line(const int fd, char **line);

#endif
