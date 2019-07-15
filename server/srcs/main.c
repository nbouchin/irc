#include "../includes/user.h"
#include "../includes/socket.h"
#include "../includes/server.h"

#define LISTEN_BACKLOG 50

int main(void)
{
	t_server server;
	t_user user;

	server = new_server("nbouchin");

	printf("%s : %d\n", server.name, server.socket.fd);
	user = new_user("coucou", 33);

	printf("%s\n", user.name);
	user.set_name(&user, "nico");
	printf("%s\n", user.name);
	printf("%d\n", user.socket.fd);

	t_user user2;
	user2 = new_user("caca", 122);

	printf("%s\n", user2.name);
	user2.set_name(&user2, "coucoucoucoucoaaaaaaaaaaaaa");
	printf("%s\n", user2.name);
	printf("%d\n", user2.socket.fd);
	return 0;
}
