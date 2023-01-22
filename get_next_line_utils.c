/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhajja <melhajja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 20:34:10 by melhajja          #+#    #+#             */
/*   Updated: 2023/01/22 20:48:03 by melhajja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char *s, unsigned int start, unsigned int stop)
{
	char	*dest;
	int		i;

	i = 0;
	if (!*s)
	{
		free(s);
		return (NULL);
	}
	dest = malloc((stop - start) + 2);
	if (!dest)
		return (NULL);
	while (start < stop)
		dest[i] = s[start++];
	dest[i++] = '\0';
	// free(s);
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
	{
		free(s1);
		return (NULL);
	}
	dest = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dest)
		return (NULL);
	while (s1 && s1[i])
		dest[i++] = s1[j++];
	j = 0;
	while (s2 && s2[j])
		dest[i++] = s2[j++];
	dest[i] = '\0';
	free(s1);
	return (dest);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	char	*dest;
	int		i;

	i = 0;
	dest = malloc(ft_strlen(s) + 1);
	if (!dest)
		return (NULL);
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	position(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-7);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\0')
		return (-7);
	return (i);
}
