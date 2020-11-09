/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvoltorb <cvoltorb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 20:00:16 by cvoltorb          #+#    #+#             */
/*   Updated: 2020/10/29 15:38:54 by cvoltorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*clean_buff(char *text)
{
	size_t	i;
	size_t	llen;
	size_t	nlen;
	char	*tmp;

	llen = line_len(text);
	nlen = buff_len(text) - llen;
	if (nlen > 0)
	{
		if (!(tmp = (char *)malloc((nlen + 1) * sizeof(char))))
			return (NULL);
		i = 0;
		while (text[llen] != '\0')
			tmp[i++] = text[++llen];
		tmp[i] = '\0';
		free(text);
		return (tmp);
	}
	free(text);
	text = NULL;
	return (text);
}

static int		save_to_line(char **line, char *text)
{
	size_t len;

	if (*line)
	{
		free(*line);
		*line = NULL;
	}
	len = line_len(text);
	if (!(*line = (char *)malloc((len + 1) * sizeof(char))))
		return (-1);
	(*line)[len] = '\0';
	if (text)
	{
		ft_strncpy(*line, text, len);
		if (text[len] == '\n')
			return (1);
	}
	return (0);
}

static char		*realloc_append_buff(char *tmp, char *buf)
{
	size_t	i;
	size_t	tmp_len;
	size_t	buf_len;
	char	*new;

	tmp_len = buff_len(tmp);
	buf_len = buff_len(buf);
	if (!(new = (char *)malloc((tmp_len + buf_len + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (i < tmp_len)
	{
		new[i] = tmp[i];
		i++;
	}
	i = 0;
	while (i < buf_len)
	{
		new[tmp_len] = buf[i];
		i++;
		tmp_len++;
	}
	new[tmp_len] = '\0';
	return (new);
}

static char		*read_join(int fd, char *text, char *buf)
{
	int		bytes_read;
	char	*tmp;

	while ((bytes_read = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[bytes_read] = '\0';
		tmp = text;
		text = realloc_append_buff(tmp, buf);
		free(tmp);
		if (is_nl(buf))
			break ;
	}
	return (text);
}

int				get_next_line(int fd, char **line)
{
	static char	*text;
	char		buf[BUFFER_SIZE + 1];
	int			ret;

	if (!line
		|| fd < 0 || BUFFER_SIZE <= 0
		|| (read(fd, buf, 0) < 0)
		|| !(*line = ft_strdup("")))
		return (-1);
	text = read_join(fd, text, buf);
	if (text == NULL)
		return (0);
	ret = save_to_line(line, text);
	text = clean_buff(text);
	return (ret);
}
