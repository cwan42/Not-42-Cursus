/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:49:51 by cwan              #+#    #+#             */
/*   Updated: 2024/03/25 11:20:58 by cwan             ###   ########.fr       */
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
	int				nu;
	struct s_stack	*n;
	struct s_stack	*p;
}					t_stack;

t_stack	*mediannode(t_stack **a);
t_stack	*ft_stklast(t_stack *lst);
t_stack	*ft_stknew(int value);
void	ft_stkadd_back(t_stack **lst, t_stack *node);
void	ft_freestack(t_stack **lst);

int		numax(t_stack **a);
int		numin(t_stack **a);
int		stacksize(t_stack **a);
int		stacksorted(t_stack **a);
int		stacksortedrev(t_stack **a);

int		indexb2a(t_stack **a, t_stack **b);
int		indexa2b(t_stack **a, t_stack **b);
int		stepsreq(int pos, t_stack **a);

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

long	ft_atol(const char *str);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_free(char **arr);

int		procargv(char **av, t_stack **stacka);

int		stacksize(t_stack **a);
int		initpri(t_stack **a, t_stack **b);
#endif
