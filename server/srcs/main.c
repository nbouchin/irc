#include "../includes/user.h"
#include "../includes/socket.h"
#include "../includes/server.h"

#define LISTEN_BACKLOG 50

int main(void)
{
	t_server server;

	server = new_server("server");

	printf("%s : %d\n", server.name, server.socket.fd);
	server.user_add(&server, "nbouchin", 42);
	server.user_add(&server, "bnouchin", 8);
	server.user_add(&server, "nobuchin", 2);
	server.user_add(&server, "nbuochin", 3);

	server.user_del(&server, "nbouchin");
	server.user_del(&server, "bnouchin");
	server.user_del(&server, "bnouchin");

	printf("%s\n", server.get_user(&server, "nbuochin")->name);
	return 0;
}
