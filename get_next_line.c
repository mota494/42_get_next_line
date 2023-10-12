/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloureir <mloureir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:50:50 by mloureir          #+#    #+#             */
/*   Updated: 2023/10/12 15:32:33 by mloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char *get_next_line(int fd)
{
	int count;
	int i;
	int check;
	char str[BUFFSIZE];
	char *newstr;

	count = 0;
	check = 0;
	while(check != 0)
	{
		check = read(fd, str, BUFFSIZE);
		while(str[i++])
		{
			if(str[i] == '\n')
				break;
			count++;
		}
	}
	i = 0;
	newstr = malloc(sizeof(char) * count);
	while(i < count)
	{
		newstr[i] = str[i];
		i++;
	}
	return (newstr);
}

int main(void)
{
	int fd;
	char *str;

	fd = open("teste.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("%s", str);
	return (0);
}