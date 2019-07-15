#include "../includes/user.h"

t_user			new_user(const char *name, const int fd)
{
	t_user		user;

	user.bind = &user_bind;
	user.get_name = &user_get_name;
	user.set_name = &user_set_name;
	user.get_message = &user_get_message;
	user.set_message = &user_set_message;

	user.socket = new_socket();
	user.bind(&user, fd);

	user.set_name(&user, name);
	memset(user.message, '\0', USER_MESSAGE_SIZE);
	return user;
}

const char		*user_get_name(const t_user *const self)
{
	return (self->name);
}

void			user_set_name(t_user *const self, const char *name)
{
	int	i;

	i = 0;
	while (i < USER_NAME_SIZE)
	{
		self->name[i] = name[i];
		i++;
	}
	self->name[i] = '\0';
}

const char		*user_get_message(const t_user *const self)
{
	return (self->message);
}

void			user_set_message(t_user *const self, const char *message)
{
	int i;

	i = 0;
	while (i < USER_MESSAGE_SIZE)
	{
		self->message[i] = message[i];
		i++;
	}
	self->message[i] = '\0';
}

void			user_bind(struct user *const self, const int fd)
{
	self->socket.fd = fd;
}
