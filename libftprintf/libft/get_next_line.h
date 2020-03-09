/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 22:35:56 by tblancha          #+#    #+#             */
/*   Updated: 2020/01/24 14:28:44 by tblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <fcntl.h>

# define BUFF_SIZE 128

int				get_next_line(const int fd, char **line);

typedef struct	s_gnl
{
	char		tmp[4864][BUFF_SIZE + 1];
	ssize_t		i[4864];
	ssize_t		nbyte[4864];
}				t_gnl;

typedef struct	s_var
{
	ssize_t		buf;
	ssize_t		len;
}				t_var;

#endif
