/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloureir <mloureir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:51:07 by mloureir          #+#    #+#             */
/*   Updated: 2023/11/03 11:57:58 by mloureir         ###   ########.fr       */
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

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_hasnl(char *str)
{
	int	i;
	int	countnl;

	i = 0;
	countnl = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			countnl++;
		i++;
	}
	return (countnl);
}

char	*ft_strjoin(char *buffer, char *pstr)
{
	char	*newstring;
	size_t	i;

	i = 0;
	if (*buffer == '\0' && *pstr == '\0')
		return (NULL);
	newstring = ft_calloc(ft_strlen(pstr) + ft_strlen(buffer) + 1, sizeof(char));
	if (!newstring)
	{
		free(pstr);
		return (NULL);
	}
	while (i < ft_strlen(pstr))
	{
		newstring[i] = pstr[i];
		i++;
	}
	while (i < ft_strlen(pstr) + ft_strlen(buffer))
	{
		newstring[i] = buffer[i - ft_strlen(pstr)];
		i++;
	}
	free(pstr);
	return (newstring);
}

char 	*ft_copyuntenl(char *buffer, char *toret)
{
	char 	*newstr;

	free(toret);
	return (newstr);
}