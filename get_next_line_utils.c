/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:50:50 by mloureir          #+#    #+#             */
/*   Updated: 2023/11/09 10:06:33 by mloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	hasnl(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*alocpy(char *str)
{
	char	*toret;
	int		i;

	i = 0;
	toret = malloc(sizeof(char) * ft_strlen(str) + 1);
	while (str[i])
	{
		toret[i] = str[i];
		i++;
	}
	toret[i] = '\0';
	return (toret);
}

char	*strjoinchr(char *oldtoret, char car)
{
	char	*newtoret;
	int		i;

	i = 0;
	newtoret = malloc(ft_strlen(oldtoret) + 2);
	while (oldtoret[i])
	{
		newtoret[i] = oldtoret[i];
		i++;
	}
	newtoret[i] = car;
	newtoret[i + 1] = '\0';
	free(oldtoret);
	return (newtoret);
}
