/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloureir <mloureir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:51:07 by mloureir          #+#    #+#             */
/*   Updated: 2023/10/27 16:19:27 by mloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void *ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;
	size_t			sizetotal;
	size_t			i;

	i = 0;
	sizetotal = nmemb * size;
	ptr = (unsigned char *) malloc(sizetotal);
	if (ptr == NULL)
		return (NULL);
	while (i < sizetotal)
		ptr[i++] = 0;
	return (ptr);
}

int	ft_strl(char *str)
{
	int	i;

	i = 0;
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
	newstr = ft_calloc((strl[0] + strl[1]) , sizeof(char));
	if (!newstr)
		return (NULL);
	i = 0;
	j = 0;
	while (s2[j] != '\0')
	{
		newstr[j] = s2[j];
		j++;
	}
	while (s1[i] != '\0')
	{
		newstr[i + j] = s1[i];
		i++;
	}
	return (newstr);
}