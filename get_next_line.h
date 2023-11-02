/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:51:26 by mloureir          #+#    #+#             */
/*   Updated: 2023/11/02 11:30:17 by mloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
//get_next_line
char	*get_next_line(int fd);
char 	*ft_writeline(int fd, char *buffer);
//get_next_line_utils
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_hasnl(char *str);
size_t	ft_strlen(char *str);
char	*ft_strjoin(char *buffer, char *pstr);

#endif