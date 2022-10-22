/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueva.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 18:35:20 by jperez            #+#    #+#             */
/*   Updated: 2022/10/08 17:05:50 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

int	ft_find_n(char *buf)
{
	int	i;
	int	end;

	i = 0;
	end = 0;
	while (buf[i])
	{
		if (buf[i++] == '\n')
		{
			end = 1;
			break ;
		}
	}
	if (end == 1)
		return (1);
	else
		return (0);
}

char	*ft_read(int fd, char *stash, int read_len, char *buf)
{
	char	*aux;

	while (read_len > 0)
	{
		read_len = read(fd, buf, BUFFER_SIZE);
		if (read_len < 0)
			return (NULL);
		if (read_len == 0)
			break ;
		if (!stash)
		{
			stash = (char *)malloc(sizeof(char) * 1);
			stash[0] = '\0';
		}
		buf[read_len] = '\0';
		aux = stash;
		stash = ft_strjoin(aux, buf);
		free(aux);
		if (ft_find_n(buf) == 1)
			break ;
	}
	return (stash);
}

char	*ft_get_line(char **stash, int *end)
{
	int		i;
	char	*line;
	char	*aux;

	i = 0;
	while (stash[0][i] && stash[0][i] != '\n')
		i++;
	if (stash[0][i] == '\0')
	{
		*end = 1;
		return (*stash);
	}
	aux = *stash;
	*stash = ft_substr(aux, i + 1, ft_strlen(aux) - i);
	line = ft_substr(aux, 0, i + 1);
	free(aux);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	int			end;
	char		buf[BUFFER_SIZE + 1];

	end = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	stash = ft_read(fd, stash, 1, buf);
	if (!stash)
		return (0);
	line = ft_get_line(&stash, &end);
	if (end == 1)
		stash = NULL;
	if (line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}
