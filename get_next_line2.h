#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*ft_substr(char *s, unsigned int start, unsigned int stop);
// size_t	ft_strlen(char *s);
char	*ft_strdup(char *s);
int		position(char *str);
int		ft_strlen(char *str);
char	*ft_strchr(char *str, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);

#endif