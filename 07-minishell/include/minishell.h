/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 17:27:07 by cwan              #+#    #+#             */
/*   Updated: 2024/10/12 15:57:36 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <fcntl.h>
//# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <errno.h>
# include <termios.h>

extern volatile sig_atomic_t	g_sig;

typedef struct s_cmd
{
	char			*redir;
	char			*cmd;
	char			**cmds;
	char			**rd;
	struct s_cmd	*n;
}					t_cmd;

typedef struct s_env
{
	char			*name;
	char			*value;
	struct s_env	*n;
}					t_env;

typedef struct s_tools
{
	t_env	**env;
	t_cmd	**cmdtab;
	char	**envp;
	char	*delimiters[10];
	char	*hdname[10];
	int		dfd[10];
	int		ppid[10];
	int		ecode;
}			t_tools;

//01-initcmdtab, 02-strproc, 03-initarrexpander, 04-quoteexpforreal
int		setcmds(t_tools *tools, char *str);
int		checkquotes(char const *str, const char *c);
int		strproc(t_cmd *tab, char *str);
void	initarrexpander(t_tools *tools);
char	*quoteexpforreal(t_tools *tools, char *str);

//02-strproc2.c
int		copychars(char **ptr, char **str, char c);

char	*reproc(char **cmds, char *str);

//builtins - cd
int		cmdscount(char **cmds);
int		cd(t_tools *tools);

//builtins - echo
int		ft_echo(t_cmd *tab);

//builtins - env
char	**newenvp(t_tools *tools);
void	init_env(t_tools *tools, char **envp);
void	print_env(t_tools *tools, t_cmd *tab);

//builtins - exit
int		freeheredocs(t_tools *tools);
void	freeenv(t_env **env);
void	freelist(t_list **lst);
void	freecmdtab(t_cmd **tab);
int		quietquit(t_tools *tools);
int		exithell(t_tools *tools, char **cmds);

//builtins - export
int		ft_export(t_tools *tools);

//builtins - pwd
char	*ft_cwd(void);
int		ft_pwd(t_tools *tools);

//builtins - unset
void	ft_unset(t_tools *tools);

//signals.c
void	handlesigquit(int sig);
void	siginthandler(int sig);
void	init_childsig(void);
void	init_sig(t_tools *tools);

//sihnals_heredoc.c
void	init_heredocsig(void);

//modifiedsplit.c
char	**ft_modsplit(char const *s, char c);

//temp executer.c

int		resetfds(int in, int out);
int		fakeparser2(t_tools *tools, t_cmd *tab);
int		initcmd(t_list **env, char **cmds, int infd, int outfd);
int		isbuiltin(char *word);

//executer2.c
int		fakeparser(t_tools *tools, t_cmd *tab);

//executer3.c
int		paircount(char **arr);
void	execute_child(t_tools *tools, t_cmd *cmd, int *input_fd, int *pipefd);
int		execute_parent(t_cmd *cmd, int *input_fd, int *pipefd);
int		execute_command(t_tools *tools, t_cmd *cmd, int *input_fd, int *pipefd);
int		handle_command(t_tools *tools, t_cmd *cmd);

//executer4.c
int		initexecute(t_tools *tools);

//temp exec.c
int		perform_redirection(int type, int fdin, int fdout, char **files);
int		redirin(char **files, int *fdin, int *i);
int		redirhd(t_tools *tools, char **files, int *fdin, int *i);
int		redirout(char **files, int *fdout, int *i);

//exec2.c
char	*ft_findpath(t_tools *tools, char *cmdzero);
int		is_directory(t_tools *tools, char *str);
int		execmd(t_tools *tools, t_cmd *cmd);

//exec3.c
int		dupredir(t_tools *tools, char **files);
int		handle_null_cmds(t_tools *tools, t_cmd *cmd);

//temp heredoc.c
int		hasheredoc(t_tools *tools);
int		createheredocs(t_tools *tools);

//temp errmsg.c
void	errmsg(char *cmd, char *str, int type);

// MISC to be deleted (from utils.c)
void	freearr(char **arr);
void	printarray(char **arr);
void	print2(t_cmd *tab);
int		handle_null_cmds(t_tools *tools, t_cmd *cmd);

//minishell_utils.c
int		checkdouble_redirect(const char *line);
int		checkthreesome(const char *line);

//minishell.c
int		checkopenquote(t_tools *tools, const char *line);

//inputcheck.c
int		dblpipecheck(const char *line);
int		lastpipespacecheck(const char *line);
int		errorcheck(t_tools *tools, char *cline);

#endif
