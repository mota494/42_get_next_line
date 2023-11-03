/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:50:50 by mloureir          #+#    #+#             */
/*   Updated: 2023/11/03 15:45:56 by mloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char 	*ft_copyuntnl(char *buffer, char *toret)
{
	char 	*newstr;
	int 	i;
	int 	j;

	i = 0;
	j = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	newstr = ft_calloc(i + 2, sizeof(char));
	while (j <= i)
	{
		newstr[j] = buffer[j];
		j++;
	}
	free(toret);
	ft_cleanbuffer(buffer);
	return (newstr);
}

char	*ft_writeline(int fd, char *buffer, char *toret)
{
	int 	bytesread;

	bytesread = 1;
	if (buffer[0] != '\0')
	{
		if (ft_hasnl(buffer) > 0)
			toret = ft_copyuntnl(buffer, toret);
		else
			toret = ft_copyuntenl(buffer, toret);
	}
	while(ft_hasnl(buffer) == 0 && bytesread > 0)
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread <= 0)
		{
			free(toret);
			return (NULL);
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
	ft_cleanbuffer(buffer);
	return (newstr);
}

void	ft_cleanbuffer(char *buffer)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (buffer[j] != '\n' && j < BUFFER_SIZE && buffer[j] != '\0')
		j++;
	if (buffer[j] == '\n')
		j++;
	while (j < BUFFER_SIZE && buffer[j] != '\0')
	{
		buffer[i] = buffer[j];
		j++;
		i++;
	}
	while (i < BUFFER_SIZE && buffer[i] != '\0')
	{
		buffer[i] = '\0';
		i++;
	}
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*toret;

	toret = ft_calloc(1, sizeof(char));
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
	while(i < 5)
	{
		str = get_next_line(fd);
//		printf("%s", str);
		printf("Returned line: %s", str);
		printf("\n========[%d]========\n", i+1);
		free(str);
		i++;
	}
	return (0);
}
