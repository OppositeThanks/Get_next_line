/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperrin <lperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:05:03 by lperrin           #+#    #+#             */
/*   Updated: 2022/05/13 12:13:27 by lperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*read_next_line(int fd, char *pre_next_str)
{
	char	*buffer;
	int		bytes;

	buffer = malloc((BUFFER_SIZE) * sizeof(char) + 1);
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(pre_next_str, '\n') && bytes != 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buffer[bytes] = '\0';
		pre_next_str = ft_strjoin(pre_next_str, buffer);
	}
	free(buffer);
	return (pre_next_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*pre_next_str;							//Vaut null au début
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	pre_next_str = read_next_line(fd, pre_next_str);	//va prendre la premiere et seconde ligne dans prev_next_str
	if (!pre_next_str)
		return (NULL);
	line = ft_get_line(pre_next_str);					//Va trouver la ligne correspondante dans pre_next_str
	pre_next_str = ft_new_sec_str(pre_next_str);		//Va changer la valeur de static char pre_next_str pour pouvoir relancer le programme
	return (line);
}
