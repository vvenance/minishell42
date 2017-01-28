#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1
# include "libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

// typedef struct	s_save
// {
// 	char		*save;
// 	int			fd;
// }				t_save;

int				get_next_line(const int fd, char **line);

#endif