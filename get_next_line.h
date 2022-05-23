/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperrin <lperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:25:53 by lperrin           #+#    #+#             */
/*   Updated: 2022/05/23 11:09:39 by lperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*read_next_line(int fd, char *pre_next_str);
size_t	ft_strlen(char *s);
char	*ft_strchr(char *str, int n);
char	*ft_strjoin(char *first, char *second);
char	*ft_get_line(char *pre_next_str);
char	*ft_new_next_str(char *pre_next_str);

#endif