/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperrin <lperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:25:37 by lperrin           #+#    #+#             */
/*   Updated: 2022/05/23 11:21:18 by lperrin          ###   ########.fr       */
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
	if (n == '\0')
		return ((char *)&str[ft_strlen(str)]);
	/* (char *)&str[ft_strlen(str)] ou just str ??? */
	while (str[i] != '\0')
	{
		if (str[i] == (char)n)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *first, char *second)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	if (!first)
	{
		first = (char *)malloc(1 * sizeof(char));
		first[0] = '\0';
	}
	if (!first || !second)
		return (NULL);
	new_str = malloc(sizeof(char) * (ft_strlen(first) + ft_strlen(second)) + 1);
	if (!new_str)
		return (NULL);
	j = -1;
	i = 0;
	if (first)
		while (first[++j] != '\0')
			new_str[j] = first[j];
	while (second[i] != '\0')
		new_str[j++] = second[i++];
	new_str[ft_strlen(first) + ft_strlen(second)] = '\0';
	free(first);
	return (new_str);
}

char	*ft_get_line(char *pre_next_str)
{
	char	*sep;
	int		i;

	i = 0;
	if (!pre_next_str[i])
		return (NULL);
	while (pre_next_str[i] && pre_next_str[i] != '\n')
		i++;
	sep = (char *)malloc(sizeof(char) * (i + 2));
	if (!sep)
		return (NULL);
	i = 0;
	while (pre_next_str[i] && pre_next_str[i] != '\n')
	{
		sep[i] = pre_next_str[i];
		i++;
	}
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

	i = 0;
	while (pre_next_str[i] && pre_next_str[i] != '\n')
		i++;
	if (!pre_next_str[i])
	{
		free(pre_next_str);
		return (NULL);
	}
	new_next_str = (char *)malloc(sizeof(char) * (ft_strlen(pre_next_str) - i
				+ 1));
	if (!new_next_str)
		return (NULL);
	i++;
	j = 0;
	while (pre_next_str[i])
		new_next_str[j++] = pre_next_str[i++];
	new_next_str[j] = '\0';
	free(pre_next_str);
	return (new_next_str);
}
