#ifndef USER_H
# define USER_H

# include "socket.h"
# define USER_NAME_SIZE 10
# define USER_MESSAGE_SIZE 512

typedef struct			user
{
	t_socket			socket;
	char				name[USER_NAME_SIZE];
	char				message[USER_MESSAGE_SIZE];

	const char 			*(*get_name)(const struct user *const self);
	void				(*set_name)(struct user *const self, const char *name);

	const char			*(*get_message)(const struct user *const self);
	void				(*set_message)(struct user *const self, const char *message);

	void				(*bind)(struct user *const self, const int fd);
	void				(*del_user)(struct user *self);
}						t_user;

t_user					new_user(const char *name, const int fd);
void					del_user(t_user *self);
void					user_bind(struct user * const self, const int fd);

const char 				*user_get_name(const t_user *const self);
void					user_set_name(t_user *const self, const char *name);

const char				*user_get_message(const t_user *const self);
void					user_set_message(t_user *const self, const char *message);
#endif
