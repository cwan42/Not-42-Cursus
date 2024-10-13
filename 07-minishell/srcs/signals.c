/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:16:34 by cwan              #+#    #+#             */
/*   Updated: 2024/09/27 05:02:31 by cwan42           ###   ########.fr       */
/*   Updated: 2024/09/19 13:22:38 by cbandara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handlesigquit(int sig)
{
	if (sig == SIGQUIT)
		ft_putstr_fd("Quit (core dumped)\n", 2);
}

void	handle_signal(int sig)
{
	(void)(sig);
	ft_putstr("\n");
	rl_on_new_line();
}

void	handle_readline(int sig)
{
	if (sig == SIGINT)
	{
		g_sig = 130;
		ft_putstr_fd("\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	init_childsig(void)
{
	signal(SIGINT, handle_readline);
	signal(SIGQUIT, handlesigquit);
}

void	init_sig(t_tools *tools)
{
	(void)(tools);
	g_sig = 0;
	signal(SIGINT, handle_readline);
	signal(SIGQUIT, SIG_IGN);
}

/*

void	siginthandler(int sig)
{
	(void)sig;
	if (g_pid > 0)
	{
		// If a child process is running, send SIGINT to it
		kill(g_pid, SIGINT);
		ft_putstr_fd("\n", 1);
		g_pid = -1;
	}
	else
	{
		// If no child process, just reset the prompt
		ft_putstr_fd("\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	handle_sigquit(int sig)
{
	(void)sig;
	// Ignore SIGQUIT (^\\)
}

void	init_sig(void)
{
	struct sigaction sa_int;
	struct sigaction sa_quit;

	// signal SIGPIPE ignore 
	signal(SIGPIPE, handle_sigpipe);

	// Setup SIGINT handler
	sa_int.sa_handler = siginthandler;
	sa_int.sa_flags = SA_RESTART;
	sigemptyset(&sa_int.sa_mask);
	sigaction(SIGINT, &sa_int, NULL);

	// Setup SIGQUIT handler to ignore
	sa_quit.sa_handler = handle_sigquit;
	sa_quit.sa_flags = SA_RESTART;
	sigemptyset(&sa_quit.sa_mask);
	sigaction(SIGQUIT, &sa_quit, NULL);
}*/

/*
void	siginthandler(int sig)
{
	g_pid = -1;
	(void)sig;
	ft_putstr_fd("\n", 1);
	if (g_pid > 0)
	{
		kill(g_pid, SIGINT);
		g_pid = -1;
	}
	else
	{
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	handle_sigint(int sig)
{
	(void)(sig);
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	init_sig(void)
{
	struct sigaction sa;

	sa.sa_handler = handle_sigint;
	sa.sa_flags = SA_RESTART;
	sigaction (SIGINT, &sa, NULL);
//	signal(SIGINT, siginthandler);
	signal(SIGQUIT, SIG_IGN);
}
*/

// void siginthandler(int sig)
// {
// 	//g_pid = -1;
//     (void)sig;
//     //ft_putstr_fd("\n", 1);
//     if (g_pid > 0)
//     {
//         kill(g_pid, SIGINT);
//         g_pid = -1;
//     }
//     else
//     {
//         rl_on_new_line();
//         rl_replace_line("", 0);
//         rl_redisplay();
//     }
//     ft_putstr_fd("\n", 1);
// }
