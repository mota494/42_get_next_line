/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:51:26 by mloureir          #+#    #+#             */
/*   Updated: 2023/10/28 17:03:48 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFSIZE 42
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

char    *ft_get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
int 	ft_strl(char *str);
int 	ft_hadendl(char *str);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_treat(char *toret);
void	ft_clean(char *str);
char	*ft_oldchar(char *toret, char *supstr);
#endif