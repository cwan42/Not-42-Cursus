/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:49:51 by cwan              #+#    #+#             */
/*   Updated: 2024/01/03 13:18:03 by cwan             ###   ########.fr       */
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
	int				value;
	int				pos;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

t_stack	*ft_stacknew(int value);
void	ft_stackadd_back(t_stack **stack, t_stack *new);
t_stack	*ft_stacklast(t_stack *stack);

void	sa(t_stack **a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);

#endif
