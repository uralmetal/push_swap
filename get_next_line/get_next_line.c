/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 09:35:55 by rwalder-          #+#    #+#             */
/*   Updated: 2018/12/13 17:27:44 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_line_buffer	*buf_delete(t_buffer *buf, size_t *i)
{
	size_t			j;
	t_line_buffer	*new_buf;

	j = *i;
	ft_strdel(&(buf->buf_fd[*i].buf));
	if (buf->size == 1)
	{
		buf->size = 0;
		ft_memdel((void**)&(buf->buf_fd));
	}
	else
	{
		buf->size--;
		while (j < buf->size)
		{
			buf->buf_fd[j] = buf->buf_fd[j + 1];
			j++;
		}
		CH_MAL_N(new_buf = (t_line_buffer*)malloc(M_LINE(buf->size)));
		ft_memcpy(new_buf, buf->buf_fd, (M_LINE(buf->size - 1)));
		ft_memdel((void**)&(buf->buf_fd));
		buf->buf_fd = new_buf;
		*i = j - 1;
	}
	return (buf->buf_fd);
}

static t_line_buffer	*buf_clean_n_search(t_buffer *buf,
		const int delete, const int create, const int fd)
{
	t_line_buffer	*ret;
	t_line_buffer	*new_buf;
	size_t			i;

	ret = (delete == 1) ? &(buf->buf_fd[0]) : (NULL);
	i = 0;
	while (i < buf->size)
	{
		if (buf->buf_fd[i].fd == fd)
			ret = &(buf->buf_fd[i]);
		if (buf->buf_fd[i].size == 0 && delete == 1 && create != 1)
			CH_MAL_N(buf_delete(buf, &i));
		i++;
	}
	if (ret == NULL && delete != 1 && create == 1)
	{
		CH_MAL_N(new_buf = (t_line_buffer*)malloc(M_LINE(++(buf->size))));
		ft_memcpy(new_buf, buf->buf_fd, M_LINE(buf->size - 1));
		ft_memdel((void**)&(buf->buf_fd));
		buf->buf_fd = new_buf;
		ret = &(buf->buf_fd[buf->size - 1]);
		ret->buf = NULL;
	}
	return (ret);
}

static t_line_buffer	*init(t_buffer *buf_init, const int fd, char **line,
		int *len)
{
	t_line_buffer *ret;

	ret = NULL;
	*len = 0;
	if (fd < 0 || fd == 1 || fd == 2 || line == NULL)
		return (NULL);
	CH_MAL_N(*line = ft_strdup(""));
	if (buf_init->buf_fd == NULL || buf_init->size == 0)
	{
		buf_init->buf_fd = (t_line_buffer*)malloc(sizeof(t_line_buffer));
		CH_MAL_N(buf_init->buf_fd);
		buf_init->size = 1;
		ret = &(buf_init->buf_fd[0]);
		ret->buf = NULL;
	}
	CH_MAL_N(ret = buf_clean_n_search(buf_init, 0, 1, fd));
	if (ret->buf == NULL)
	{
		ret->size = BUFF_SIZE;
		ret->i = ret->size;
		CH_MAL_N(ret->buf = (char*)malloc(sizeof(char) * BUFF_SIZE));
		ret->fd = fd;
	}
	return (ret);
}

static int				line_set(t_line_buffer *buf, char **line, int *len)
{
	void	*p;
	int		add_len;
	char	*new_line;

	if (buf->size == 0 && (*line)[0] == '\0')
		return (0);
	if (buf->size == 0 && (*line)[0] != '\0')
		return (1);
	p = ft_memchr(buf->buf + buf->i, '\n', buf->size - buf->i);
	if (p == NULL)
		add_len = buf->size - buf->i;
	else
		add_len = (char*)p - buf->buf - buf->i;
	CH_MAL_I(new_line = ft_strnew(*len + add_len));
	ft_memcpy(new_line, *line, *len);
	ft_memcpy(new_line + *len, buf->buf + buf->i, add_len);
	*len += (add_len);
	buf->i += (add_len + ((p == NULL) ? 0 : 1));
	ft_strdel(line);
	*line = new_line;
	return ((p == NULL) ? 2 : 1);
}

int						get_next_line(const int fd, char **line)
{
	static t_buffer	s_buf;
	int				len;
	int				rn;
	t_line_buffer	*buf;

	CH_MAL_I(buf = init(&s_buf, fd, line, &len));
	while (1)
	{
		if (buf->i >= buf->size)
		{
			if ((buf->size = read(buf->fd, buf->buf, BUFF_SIZE)) == (size_t)-1)
			{
				buf->size = 0;
				buf_clean_n_search(&s_buf, 1, 0, fd);
				return (-1);
			}
			buf->i = 0;
		}
		if ((rn = line_set(buf, line, &len)) != 2)
		{
			if (rn == (-1) || rn == 0)
				buf_clean_n_search(&s_buf, 1, 0, fd);
			return (rn);
		}
	}
}
