/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 20:35:47 by rwalder-          #+#    #+#             */
/*   Updated: 2018/12/13 17:28:04 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GET_NEXT_LINE_H
# define _GET_NEXT_LINE_H

# define BUFF_SIZE 32

# define CH_MAL_N(x) if ((x) == NULL) return (NULL)
# define CH_MAL_I(x) if ((x) == NULL) return (-1)
# define M_LINE(x) sizeof(t_line_buffer) * (x)

# if (BUFF_SIZE < 0)
#  error BUFF_SIZE must  have > 0
# endif

# include "../libft/libft.h"

typedef struct	s_line_buffer
{
	size_t	i;
	size_t	size;
	char	*buf;
	int		fd;
}				t_line_buffer;

typedef struct	s_buffer
{
	t_line_buffer	*buf_fd;
	size_t			size;
}				t_buffer;

int				get_next_line(const int fd, char **line);

#endif
