/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:50:50 by mloureir          #+#    #+#             */
/*   Updated: 2023/11/02 16:53:46 by mloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_writeline(int fd, char *buffer, char *toret)
{
	int 	bytesread;

	bytesread = 1;
	while(ft_hasnl(buffer) == 0 && bytesread > 0)
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread < 0)
		{
			free(toret);
			return (0);
		}
		buffer[bytesread] = '\0';
		toret = ft_strjoin(buffer, toret);
	}
	return (toret);
}

char 	*ft_treatline(char *toret, char *buffer)
{
	int		i;
	int 	j;
	char	*newstr;

	i = 0;
	j = 0;
	while(toret[i] != '\n' && toret[i] != '\0')
		i++;
	newstr = ft_calloc(i + 2,sizeof(char));
	if (!newstr)
	{
		free(toret);
		return (NULL);
	}
	while(j <= i)
	{
		newstr[j] = toret[j];
		j++;
	}
	free(toret);
	ft_cleanbuffer(buffer, j);
	return (newstr);
}

void	ft_cleanbuffer(char *buffer, int nchars)
{
	int i;

	i = 0;
	while (buffer[i] != '\0' && buffer[i + nchars] !='\0')
	{
		buffer[i] = buffer[i + nchars];
		i++;
	}
}

char 	*ft_writeoldchar(char *buffer, char *toret)
{
	char *newstr;
	int i;
	int j;

	i = 0;
	while(buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	newstr = ft_calloc(i + 2, sizeof(char)) // ISTO ESTA MALE
	j = 0;
	while (j <= i)
	{
		newstr[j] = buffer[j];
		j++;
	}
	ft_cleanbuffer(buffer, j);
	free(toret);
	return (newstr);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*toret;

	toret = ft_calloc(1, sizeof(char));
	if (buffer[0] != '\0')
	{
		toret = ft_writeoldchar(buffer, toret);
		if(ft_hasnl(toret) > 0)
			return (toret);
	}
	toret = ft_writeline(fd, buffer, toret);
	toret = ft_treatline(toret, buffer);
	return (toret);
}

int main(void)
{
	int fd;
	int i = 0;
	char *str;
	fd = open("teste.txt", O_RDONLY);
	while(i < 6)
	{
		str = get_next_line(fd);
		printf("\nReturned line: %s", str);
		free(str);
		printf("\n========[%d]========\n", i+1);
		i++;
	}
	return (0);
}
