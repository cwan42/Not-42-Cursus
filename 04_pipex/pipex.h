/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:56:43 by cwan              #+#    #+#             */
/*   Updated: 2023/12/07 19:16:57 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"

# include <fcntl.h>
// for open

# include <stdlib.h>
// for free

# include <unistd.h>
// for access, close, read, write, execve, exit, fork, pipe, unlink

# include <sys/wait.h>
// for wait

# include <errno.h>
// for errno values used in perror

# include <stdio.h>
// for perror

#endif
