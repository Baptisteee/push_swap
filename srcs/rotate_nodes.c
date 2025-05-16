/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_nodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 23:39:58 by babodere          #+#    #+#             */
/*   Updated: 2025/05/13 16:07:51 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stack(t_stack *stack)
{
	t_list	*node;
	int		temp;
	int		prev_data;

	node = ft_lstlast(stack->first);
	prev_data = node->number;
	node = node->prev;
	while (node)
	{
		temp = node->number;
		node->number = prev_data;
		prev_data = temp;
		node = node->prev;
	}
	ft_lstlast(stack->first)->number = prev_data;
}

void	rotate_stacks(t_stack *a_stack, t_stack *b_stack)
{
	rotate_stack(a_stack);
	rotate_stack(b_stack);
}

void	reverse_rotate_stack(t_stack *stack)
{
	t_list	*node;
	int		temp;
	int		prev_data;

	node = stack->first;
	prev_data = node->number;
	node = node->next;
	while (node)
	{
		temp = node->number;
		node->number = prev_data;
		prev_data = temp;
		node = node->next;
	}
	stack->first->number = prev_data;
}

void	reverse_rotate_stacks(t_stack *a_stack, t_stack *b_stack)
{
	reverse_rotate_stack(a_stack);
	reverse_rotate_stack(b_stack);
}
