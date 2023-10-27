/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloureir <mloureir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:50:50 by mloureir          #+#    #+#             */
/*   Updated: 2023/10/27 17:57:22 by mloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	ft_clean(char *str)
{
	int i;
	int j;

	i = 0;
	while(str[i] != '\n')
	{
		i++;
	}
	j = 0;
	i++;
	while(str[i] != '\0')
	{
		str[j] = str[i];
		i++;
		j++;
	}
	str[j] = '\0';
}

void	ft_treat(char *toret)
{
	int	i;

	i = 0;
	while (toret[i] != '\0')
	{
		if (toret[i] == '\n')
		{
			toret[i + 1] = '\0';
			break ;
		}
		i++;
	}
}

int	ft_hasendl(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_get_next_line(int fd)
{
	char		*toret;
	static char	supstr[BUFFSIZE];
	int			count;

	count = read(fd, supstr, BUFFSIZE);
	supstr[count] = '\0';
	toret = ft_calloc(sizeof(char), 1);
	toret = ft_strjoin(supstr, toret);
	if (ft_hasendl(toret) == 0)
	{
		while (ft_hasendl(toret) == 0 && count > 0)
		{
			count = read(fd, supstr, BUFFSIZE);
			supstr[count] = '\0';
			toret = ft_strjoin(supstr, toret);
		}
	}
	ft_treat(toret);
	printf("Antes do clean: %s\n", supstr);
	ft_clean(supstr);
	printf("Depois do clean: %s", supstr);
	printf("\n\n\n%s", toret);
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
