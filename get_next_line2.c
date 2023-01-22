#include "get_next_line.h"

// char	*fill_stock(char *stock, int fd)
// {
// 	char	*str;
// 	int		i;

// 	str = malloc(BUFFER_SIZE + 1);
// 	if (!str)
// 		return (NULL);
// 	i = 1;
// 	while (i != 0 && !ft_strchr(stock, '\n'))
// 	{
// 		i = read(fd, str, BUFFER_SIZE);
// 		if (i == -1)
// 		{
// 			if (stock)
// 				free(stock);
// 			free(str);
// 			return (NULL);
// 		}
// 		str[i] = '\0';
// 		stock = ft_strjoin(stock, str);
// 	}
// 	free(str);
// 	return (stock);
// }
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
//============================================================================

// char	*get_line(char *storage)
// {
// 	int		newline_position;
// 	char	*line;

// 	if (!*storage)
// 		return (NULL);
// 	newline_position = position(storage);
// 	if (newline_position != -7)
// 		line = ft_substr(storage, 0, newline_position + 1);
// 	if (newline_position == -7 && ft_strlen(storage) > 0)
// 		line = ft_substr(storage, 0, ft_strlen(storage));
// 	return (line);
// }
char	*fill_line(char *stock)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	if (!*stock)
		return (NULL);
	while (stock[i] && stock[i] != '\n')
		i++;
	if (stock[i] == '\n')
		i += 1;
	str = malloc(i + 1);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (stock[i] && stock[i] != '\n')
		str[j++] = stock[i++];
	if (stock[i] == '\n')
		str[j++] = stock[i++];
	str[j] = '\0';
	return (str);
}

///===========================================================================================
// char	*sec_save(char *stock)
// {
// 	char	*str;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	if (!*stock)
// 	{
// 		free(stock);
// 		return (NULL);
// 	}
// 	while (stock[i] && stock[i] != '\n')
// 		i++;
// 	if (!stock[i])
// 	{
// 		free(stock);
// 		return (NULL);
// 	}
// 	str = malloc(ft_strlen(stock) - i + 1);
// 	j = 0;
// 	i += 1;
// 	while (stock[i])
// 		str[j++] = stock[i++];
// 	str[j] = '\0';
// 	free(stock);
// 	return (str);
// }
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

//====================================================
char	*get_next_line(int fd)
{
	char		*line;
	static char	*stock;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	// stock = fill_stock(stock, fd);
	stock = read_lines(fd, stock);
	if (!stock)
		return (NULL);
	line = fill_line(stock);
	// line = get_line(stock);
	// stock = sec_save(stock);
	stock = ft_trim(stock);
	return (line);
}
// int	main(void)
// {
// 	int fd = open("file2.txt", O_RDONLY);
// 	printf("line1--%s--\n", get_next_line(fd));
// 	//close(fd);
// 	printf("line2--%s--\n", get_next_line(fd));
// 	printf("line3--%s--\n", get_next_line(fd));
// 	printf("line4--%s--\n", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// }