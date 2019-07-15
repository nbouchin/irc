#include  "socket.h"

t_socket new_socket(void)
{
	t_socket socket;

	socket.fd = 0;
	socket.size = 0;
	socket.open = &socket_open;
	socket.close = &socket_close;
	return socket;
}

void socket_open(struct socket *self)
{
	if (self->fd)
	{
		printf("socket: already open %d\n", self->fd);
		return ;
	}
	if ((self->fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		perror("socket");
		exit(-1);
	}
	memset(&self->addr, 0, sizeof(struct sockaddr_in));
	self->addr.sin_family = AF_INET;
	self->addr.sin_addr.s_addr = INADDR_ANY;
	self->addr.sin_port = htons(6667);
	self->size = sizeof(self->addr);
}

void socket_close(struct socket *self)
{
	close(self->fd);
	self->size = 0;
	self->fd = 0;
	self->size = 0;
}
