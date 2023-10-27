/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloureir <mloureir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:50:50 by mloureir          #+#    #+#             */
/*   Updated: 2023/10/26 18:02:36 by mloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char *ft_get_next_line(int fd)
{
	char *toret;
	char supstr[BUFFSIZE];

	read(fd, supstr, BUFFSIZE);
	printf("%s", supstr);
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
		get_next_line(fd);
		i++;
	}
	return (0);
}
