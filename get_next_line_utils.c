/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloureir <mloureir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:51:07 by mloureir          #+#    #+#             */
/*   Updated: 2023/10/27 10:59:53 by mloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strl(char *str)
{
	int	i;

	i = 0;
	if(!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char *ft_strjoin(char *s1, char *s2)
{
	char	*newstr;
	int 	strl[2];
	int 	i;
	int		j;

	strl[0] = ft_strl(s1);
	strl[1] = ft_strl(s2);
	newstr = malloc(sizeof(char) * (strl[0] + strl[1]));
	if (!newstr)
		return (NULL);
	i = 0;
	j = 0;
	while(s1[i++] != '\0')
		newstr[i] = s1[i];
	while(s2[j++] != '\0')
		newstr[i + j] = s2[j];
	newstr[i+j] = '\0';
	return (newstr);
}