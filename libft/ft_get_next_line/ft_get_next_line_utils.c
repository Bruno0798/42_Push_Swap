/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:00:58 by bsousa-d          #+#    #+#             */
/*   Updated: 2023/10/07 12:29:48 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_get_char(char *str, char fetch)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == fetch)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

char	*join(char *temp, char *buffer)
{
	int		i;
	int		j;
	char	*str;

	i = -1;
	j = 0;
	if (!temp)
	{
		temp = malloc(sizeof(char) * 1);
		temp[0] = '\0';
	}
	str = malloc(sizeof(char) * ((ft_strlen(temp) + ft_strlen(buffer)) + 1));
	if (!str)
		return (NULL);
	while (temp[++i])
		str[i] = temp[i];
	while (buffer[j])
		str[i++] = buffer[j++];
	str[i] = '\0';
	free(temp);
	return (str);
}

char	*ft_get_line(char *temp)
{
	int		i;
	char	*line;

	i = 0;
	if (!temp[i])
		return (NULL);
	while (temp[i] != '\0' && temp[i] != '\n')
		i++;
	if (temp[i] == '\0')
		line = malloc(sizeof(char) * (i + 1));
	else
		line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (temp[i] != '\0' && temp[i] != '\n')
	{
		line[i] = temp[i];
		i++;
	}
	if (temp[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*new_temp(char *temp)
{
	int		i;
	int		j;
	char	*new_temp;

	i = 0;
	j = 0;
	while (temp[i] != '\0' && temp[i] != '\n')
		i++;
	if (temp[i] == '\0')
	{
		free(temp);
		return (NULL);
	}
	new_temp = malloc(sizeof(char) * (ft_strlen(temp) - i + 1));
	if (!new_temp)
		return (NULL);
	i = i + 1;
	while (temp[i])
		new_temp[j++] = temp[i++];
	new_temp[j] = '\0';
	free(temp);
	return (new_temp);
}
