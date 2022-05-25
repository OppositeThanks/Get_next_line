/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperrin <lperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:05:03 by lperrin           #+#    #+#             */
/*   Updated: 2022/05/25 10:43:33 by lperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_next_line(int fd, char *pre_next_str)
{
	char	*buffer;
	int		read_bytes;

	buffer = malloc((BUFFER_SIZE) * sizeof(char) + 1);
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(pre_next_str, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buffer);
			free(pre_next_str);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		pre_next_str = ft_strjoin(pre_next_str, buffer);
	}
	free(buffer);
	return (pre_next_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*pre_next_str[4096];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	pre_next_str[fd] = read_next_line(fd, pre_next_str[fd]);
	if (!pre_next_str[fd])
		return (NULL);
	line = ft_get_line(pre_next_str[fd]);
	pre_next_str[fd] = ft_new_next_str(pre_next_str[fd]);
	return (line);
}
