#ifndef SOCKET_H
# define SOCKET_H

# include <netinet/in.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/select.h>
# include <sys/socket.h>
# include <sys/types.h>
# include <unistd.h>

typedef struct	socket
{
	int					fd;
	struct sockaddr_in	addr;
	socklen_t			size;

	void (*open)(struct socket *self);
	void (*close)(struct socket *self);
}				t_socket;

t_socket		new_socket(void);
void			socket_open(struct socket *self);
void			socket_close(struct socket *self);
#endif
