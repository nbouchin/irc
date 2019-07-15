#include "server.h"

t_server	new_server(const char *name)
{
	t_server server;

	server.get_name = &server_get_name;
	server.set_name = &server_set_name;

	server.set_name(&server, name);

	server.socket = new_socket();
	server.socket.open(&server.socket);
	return server;
}

const char		*server_get_name(const t_server *const self)
{
	return (self->name);
}

void			server_set_name(t_server *const self, const char *name)
{
	int	i;

	i = 0;
	while (i < SERVER_NAME_SIZE)
	{
		self->name[i] = name[i];
		i++;
	}
	self->name[i] = '\0';
}
