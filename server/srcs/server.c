#include "server.h"

t_server	new_server(const char *name)
{
	t_server server;

	server.get_name = &server_get_name;
	server.set_name = &server_set_name;
	server.user_add = &user_add;
	server.user_del = &user_del;
	server.get_user = &get_user;

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

t_user		*get_user(t_server *const self, const char *name)
{
	int	i;

	i = 0;
	while (i < MAX_USER)
	{
		if (!strcmp(self->users[i].name, name))
			return &self->users[i];
		i++;
	}
	printf("No user named %s\n", name);
	return NULL;
}

void			user_add(t_server *const self, const char *name, const int fd) {
	int	i;

	i = 0;
	while (i < MAX_USER) {
		if (self->users[i].socket.fd == 0)
		{
			self->users[i] = new_user(name, fd);
			break ;
		}
		i++;
	}
}

void			user_del(t_server *const self, const char *name)
{
	t_user	*user;

	if ((user = self->get_user(self, name)))
		user->del_user(user);
}
