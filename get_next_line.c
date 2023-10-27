/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloureir <mloureir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:50:50 by mloureir          #+#    #+#             */
/*   Updated: 2023/10/27 11:58:19 by mloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int ft_hasendl(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char *ft_get_next_line(int fd)
{
	char		*toret;
	static char	supstr[BUFFSIZE];

	read(fd, supstr, BUFFSIZE);
	toret = ft_calloc(sizeof(char), 1);
	toret = ft_strjoin(supstr, toret);
	printf("%s", toret);
	return (toret);
}

int main(void)
{
	int fd;
	int i = 0;
	fd = open("teste.txt", O_RDONLY);
	while(i < 1)
	{
		printf("[%d]\n", i);
		ft_get_next_line(fd);
		i++;
	}
	return (0);
}
