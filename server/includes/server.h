#ifndef SERVER_H
# define SERVER_H

# include "user.h"
# include "socket.h"
# include "server.h"
# define SERVER_NAME_SIZE 63

typedef struct	server
{
	char		name[SERVER_NAME_SIZE];
	t_user		users[50];
	t_socket	socket;

	const char		*(*get_name)(const struct server *const self);
	void			(*set_name)(struct server *const self, const char *name);
}				t_server;

t_server		new_server(const char *name);
const char		*server_get_name(const t_server *const self);
void			server_set_name(t_server *const self, const char *name);
#endif
