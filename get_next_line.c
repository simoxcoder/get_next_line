/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhajja <melhajja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 20:34:14 by melhajja          #+#    #+#             */
/*   Updated: 2023/01/22 20:47:19 by melhajja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *storage)
{
	int		newline_position;
	char	*line;

	if (!*storage)
		return (NULL);
	line = NULL;
	newline_position = position(storage);
	if (newline_position == -7 && ft_strlen(storage) > 0)
	{
		line = ft_strdup(storage);
		free(storage);
	}
	if (newline_position != -7 && ft_strlen(storage) > 0)
	{
		if (storage[0] == '\n')
			line = ft_strdup("\n");
		else
			line = ft_substr(storage, 0, newline_position + 1);
	}
	return (line);
}
//==================================================================

char	*read_lines(int fd, char *storage)
{
	ssize_t	read_bytes;
	char	*buffer;

	read_bytes = 1;
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (read_bytes > 0 && position(storage) == -7)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			if (storage)
				free(storage);
			free(buffer);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		storage = ft_strjoin(storage, buffer);
	}
	free(buffer);
	return (storage);
}
//==================================================================

char	*ft_trim(char *storage)
{
	char	*tmp;

	if (!*storage)
	{
		free(storage);
		return (NULL);
	}
	tmp = ft_substr(storage, position(storage) + 1, ft_strlen(storage));
	free(storage);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	storage = read_lines(fd, storage);
	if (!storage)
		return (NULL);
	line = get_line(storage);
	storage = ft_trim(storage);
	return (line);
}

// int	main(void)
// {
// 	int fd = open("file2.txt", O_RDONLY);
// 	printf("line1--%s--\n", get_next_line(fd));
// 	//close(fd);
// 	printf("line2--%s--\n", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// }