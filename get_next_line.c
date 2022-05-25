/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperrin <lperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:17:01 by lperrin           #+#    #+#             */
/*   Updated: 2022/05/23 12:25:53 by lperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_next_line(int fd, char *pre_next_str)
{
	char	*buffer;
	int		nbytes;

	buffer = malloc((BUFFER_SIZE) * sizeof(char) + 1);
	if (!buffer)
		return (NULL);
	nbytes = 1;
	while (!ft_strchr(pre_next_str, '\n') && nbytes != 0)
	{
		nbytes = read(fd, buffer, BUFFER_SIZE);
		if (nbytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[nbytes] = '\0';
		pre_next_str = ft_strjoin(pre_next_str, buffer);
	}
	free(buffer);
	return (pre_next_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*pre_next_str;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	pre_next_str = read_next_line(fd, pre_next_str);
	if (!pre_next_str)
		return (NULL);
	line = ft_get_line(pre_next_str);
	pre_next_str = ft_new_next_str(pre_next_str);
	return (line);
}
