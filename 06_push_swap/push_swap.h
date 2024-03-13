/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:49:51 by cwan              #+#    #+#             */
/*   Updated: 2024/03/13 11:44:27 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

t_stack	*ft_stklast(t_stack *lst);
t_stack	*ft_stknew(int value);
void	ft_stkadd_back(t_stack **lst, t_stack *node);
void	ft_freestack(t_stack **lst);

void	pa(t_stack **heada, t_stack **headb);
void	pb(t_stack **heada, t_stack **headb);

void	sa(t_stack **heada);
void	sb(t_stack **headb);
void	ss(t_stack **heada, t_stack **headb);

void	ra(t_stack **heada);
void	rb(t_stack **headb);
void	rr(t_stack **heada, t_stack **headb);

void	rra(t_stack **heada);
void	rrb(t_stack **headb);
void	rrr(t_stack **heada, t_stack **headb);

void	ft_free(char **arr);
#endif
