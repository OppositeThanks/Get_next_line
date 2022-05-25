/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperrin <lperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:04:59 by lperrin           #+#    #+#             */
/*   Updated: 2022/05/23 13:04:00 by lperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char	*get_next_line(int fd);
char	*read_next_line(int fd, char *pre_next_str);
size_t	ft_strlen(char *s);
char	*ft_strchr(char *str, int n);
char	*ft_strjoin(char *first, char *second);
char	*ft_get_line(char *pre_next_str);
char	*ft_new_next_str(char *pre_next_str);
#endif