/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:49:51 by cwan              #+#    #+#             */
/*   Updated: 2024/03/06 20:13:08 by cwan             ###   ########.fr       */
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

void	sa(t_stack **heada);
void	sb(t_stack **headb);
void	ss(t_stack **heada, t_stack **headb);
void	swap(t_stack **head);

void	ra(t_stack **heada);
void	rb(t_stack **headb);
void	rr(t_stack **heada, t_stack **headb);
void	rotate(t_stack **head);

//pa, pb, push
//rra, rrb, rrr, rrotate

#endif
