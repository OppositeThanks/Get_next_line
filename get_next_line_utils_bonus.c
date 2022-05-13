/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperrin <lperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:04:43 by lperrin           #+#    #+#             */
/*   Updated: 2022/05/13 12:12:20 by lperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *str, int n)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (c == '\0')
		return (str); // (char *)&s[ft_strlen(s)] ou NULL ???
	while (str)
	{
		if (str[i] == n)
			return (str);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *first, char *second)
{
	char	*new_str;
	int		i;
	int		j;

	if (!first)
	{
		first = (char *)malloc(sizeof(char));
		first[0] = '\0';
	}
	if (!first || !second)
		return (NULL);
	new_str = malloc(sizeof(char) * (ft_strlen(first) + ft_strlen(second)) + 1);
	j = 0;
	if (first)
		while (first[j] != '\0')
			new_str[j++] = first[j++];
	i = -1;
	while (second)
	{
		news_tr[j] = second[i++];
		j++;
	}
	new_str[j] = '\0';
	free(first);
	return (new_str);
}

char	*ft_get_line(char *pre_next_str)
{
	char	*sep;
	int		i;

	if (!pre_next_str)
		return (NULL);
	i = 0;
	while (pre_next_str[i] && pre_next_str[i] != '\n')
		i++;
	sep = malloc(sizeof(char) * (i + 2));
	if (!sep)
		return (NULL);
	/* i = -1; */ //a verif
	while (pre_next_str[i] && pre_next_str[i] != '\n')
		sep[++i] = pre_next_str[++i];
	if (pre_next_str[i] == '\n')
	{
		sep[i] = pre_next_str[i];
		i++;
	}
	sep[i] = '\0';
	return (sep);
}

char	*ft_new_next_str(char *pre_next_str)
{
	char	*new_next_str;
	int		i;
	int		j;

	while (pre_next_str[i] && pre_next_str[i] != '\n')
		i++;
	if (!pre_next_str[i])
	{
		free(pre_next_str);
		return (NULL);
	}
	new_next_str = (char *)malloc(sizeof(char) * (ft_strlen(pre_next_str) - i
				+ 1));
	if (!str)
		return (NULL);
	/* i++;
	j = 0; */ //a verif
	while (pre_next_str[i])
		new_next_str[j++] = pre_next_str[i++];
	new_next_str[j] = '\0';
	return (new_next_str);
}