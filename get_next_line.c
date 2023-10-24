/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloureir <mloureir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:50:50 by mloureir          #+#    #+#             */
/*   Updated: 2023/10/24 09:57:25 by mloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	char	newstr[BUFFSIZE];
	int		read;

	read = 1;
    if (fd < 0)
        return (NULL);
	while(read > 0)
	{
		read = read(fd, newstr, BUFFSIZE);

	}
	return (*newstr);
}

#include <stdio.h>
int main(void)
{
	int fd;
	char *str;

	fd = open("teste.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("%s", str);
	return (0);
}