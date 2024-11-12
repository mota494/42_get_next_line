/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloureir <mloureir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:51:07 by mloureir          #+#    #+#             */
/*   Updated: 2023/11/06 11:46:30 by mloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *oldtoret, char *buffer, int *passed)
{
	char	*toret;
	int		i;

	i = 0;
	toret = alocpy(oldtoret);
	while (buffer[i] != '\n' && buffer[i])
	{
		toret = strjoinchr(toret, buffer[i]);
		*passed += 1;
		i++;
	}
	if (buffer[i] == '\n')
	{
		toret = strjoinchr(toret, buffer[i]);
		*passed += 1;
	}
	free(oldtoret);
	return (toret);
}

void	clean_buffer(char *buffer, int toclean)
{
	int	i;

	i = 0;
	while (buffer[i + toclean])
	{
		buffer[i] = buffer[i + toclean];
		i++;
	}
	buffer[i] = '\0';
}

char	*get_next_line(int fd)
{
	char		*toret;
	static char	buffer[BUFFER_SIZE];
	int			byteread;
	int			passed;

	toret = malloc(1);
	toret[0] = '\0';
	passed = 0;
	if (buffer[0] != '\0')
	{
		toret = get_line(toret, buffer, &passed);
		clean_buffer(buffer, passed);
	}
	while (hasnl(toret) == 0)
	{
		passed = 0;
		byteread = read(fd, buffer, BUFFER_SIZE);
		if (byteread <= 0)
			return (NULL);
		toret = get_line(toret, buffer, &passed);
		buffer[byteread] = '\0';
		clean_buffer(buffer, passed);
	}
	return (toret);
}
