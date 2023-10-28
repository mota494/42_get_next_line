/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:50:50 by mloureir          #+#    #+#             */
/*   Updated: 2023/10/28 17:04:59 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_oldchar(char *toret, char *supstr)
{
	toret = ft_strjoin(supstr, toret);
	return (toret);
	
}

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
	if(str[0] == '\0')
		return (0);
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

	toret = ft_calloc(sizeof(char), 1);
	if(supstr[0] != '\0')
		toret = ft_oldchar(toret, supstr);
	count = read(fd, supstr, BUFFSIZE);
	supstr[count] = '\0';
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
	ft_clean(supstr);
	printf("\nsupstr: %s", supstr);
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
		str = ft_get_next_line(fd);
		printf("\n[%d]Line: %s", i, str);
		i++;
	}
	return (0);
}
