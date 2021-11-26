/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:25:54 by bnoufel           #+#    #+#             */
/*   Updated: 2020/02/20 14:25:58 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SERVER_H
# define __SERVER_H
# include "ft_p.h"
# include <sys/types.h>
# include <signal.h>

# define BACKLOG 1
# define SERVER_FOLDER "server_folder"
# define SERVER_LOGS "logs"
# define GLOBAL_LOGS "global_logs"
# define USER_FOLDER "user"
# define PASSWORDS ".passwords"
# define NEW_CONNECT "new_connection:\nlogin: %s\npassword:%s\n\n"
# define RECV_FAIL "ERROR: recv fail, user have probably logout\n"

typedef struct		s_user
{
	char			*login;
	char			*password;
	struct s_user	*next;
}					t_user;

typedef struct		s_context
{
	uint16_t		port;
	char			*root;
	char			*pass_file;
	char			*log_folder;
	char			*error;
	t_sockaddr		sockaddr_server;
	int				sock_fd_server;
	t_user			*user_list;
	pid_t			server_pid;
	int				end;
}					t_context;

typedef struct		s_process
{
	char			*pwd;
	char			*root;
	char			*login;
	char			*log_file;
	char			*tmp_file;
	int				log_fd;
	t_sockaddr		sockaddr_client;
	int				sock_fd_client;
	char			command[512];
	unsigned int	command_len;
}					t_process;

int					authentification(t_process *process, int log_fd, char
*pass_file);
void				free_ctx(t_context *ctx);
int					connection_accepted(t_process *process, int log_fd);
int					connection_refused(t_process *process, int log_fd);
int					init_struct(char *str, t_context *ctx);
int					server(t_context *ctx);
int					keep_hand_on_server(t_context *ctx);
int					add_elem(t_user **list, char *login, char *password);
void				remove_elem(t_user **list, t_user *to_delete);
void				free_user_list(t_user **list);
void				newuser(t_context *ctx);
void				deleteuser(t_context *ctx);
void				showuser(t_user *list);
t_user				*search_user(t_user *list, char *login);
t_user				*get_pass_file(char *pass_file);
int					add_in_pass_file(char *login, char *pass, char
*pass_file, t_user **list);
int					remove_pass_file(char *login, char *pass, char
*pass_file, t_user **list);
int					verif_dir(t_process *process, char *dir);
int					verif_file_exist(t_process *process, char *file);
int					verif_can_be_created(t_process *process, char *file);
void				free_process(t_process *process);
void				client_command_loop(t_process *process);
void				message(t_process *process, char *str);
void				ft_pwd(t_process *process);
void				ft_cd(t_process *process, char **command);
int					ft_ls(t_process *process, char **command);
int					ft_get(t_process *process, char **command);
int					ft_send_file(t_process *process, char *file_name);
int					ft_send_file_fd(t_process *process, int fd);
void				ft_mkdir(t_process *process, char **command);
void				ft_mget(t_process *process, char **command);
void				ft_put(t_process *process, char **command);
void				ft_quit(t_process *process);
int					end_process(int to_return, t_process *process);
int					open_process_log_file(t_process *process, int log_fd);
int					init_process_root(t_process *process);
int					open_log_n_signal(t_context *ctx, int *log_fd);
int					open_log_fd(t_context *ctx, int *fd);
#endif
