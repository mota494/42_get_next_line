/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:50:50 by mloureir          #+#    #+#             */
/*   Updated: 2023/11/02 11:59:51 by mloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_writeline(int fd, char *buffer)
{
	char	*line;
	int 	bytesread;

	bytesread = 1;
	line = ft_calloc(1 ,1);
	while(ft_hasnl(buffer) == 0 && bytesread > 0)
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread <= 0)
		{
			free(line);
			return (0);
		}
		buffer[bytesread] = '\0';
		line = ft_strjoin(buffer, line);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char	*toret;

	toret = ft_writeline(fd, buffer);

	return (toret);
}

int main(void)
{
	int fd;
	int i = 0;
	char *str;
	fd = open("teste.txt", O_RDONLY);
	while(i < 1)
	{
		str = get_next_line(fd);
		printf("\nReturned line: %s", str);
		free(str);
		printf("\n========[%d]========\n", i+1);
		i++;
	}
	return (0);
}
