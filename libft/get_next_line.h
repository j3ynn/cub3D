#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <stdint.h>
# include <fcntl.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif

//char	*ft_strchr(char *str, int s);
//char	*ft_strjoin(char *s1, char *s2);
//char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_extraction_storage(char storage[BUFFER_SIZE]);
int		ft_check_storage(char storage[BUFFER_SIZE], char **line);
char	*get_next_line(int fd);
//size_t	ft_strlen(char *str);

#endif
