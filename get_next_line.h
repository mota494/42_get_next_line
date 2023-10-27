/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloureir <mloureir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:51:26 by mloureir          #+#    #+#             */
/*   Updated: 2023/10/27 17:48:03 by mloureir         ###   ########.fr       */
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
#endif