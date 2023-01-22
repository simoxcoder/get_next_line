#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *str, char c)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == c)
			return (str);
		str++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	int		i;
	int		j;
	int		k;

	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	i = 0;
	j = 0;
	k = 0;
	dest = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (dest == NULL)
		return (0);
	while (s1[i])
		dest[k++] = s1[i++];
	while (s2[j])
		dest[k++] = s2[j++];
	dest[k] = '\0';
	free(s1);
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
		dest[i++] = s[start++];
	dest[i] = '\0';
	// free(s);
	return (dest);
}

char	*ft_strdup(char *s)
{
	char *dest;
	int i;

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
	free(s);
	return (dest);
}