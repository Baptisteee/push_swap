/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_nodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babodere <babodere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 23:39:58 by babodere          #+#    #+#             */
/*   Updated: 2025/05/21 21:38:13 by babodere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stack(t_stack *stack, int print)
{
	t_list	*first;

	first = stack->first;
	stack->first = first->next;
	if (stack->first)
		stack->first->prev = NULL;
	first->next = NULL;
	ft_lstadd_back(&(stack->first), first);
	if (print)
		ft_printf("r%c\n", stack->letter);
}

void	rotate_stacks(t_stack *a_stack, t_stack *b_stack)
{
	rotate_stack(a_stack, 0);
	rotate_stack(b_stack, 0);
	ft_printf("rr\n");
}

void	reverse_rotate_stack(t_stack *stack, int print)
{
	t_list	*last;

	last = ft_lstlast(stack->first);
	if (last->prev)
		last->prev->next = NULL;
	last->prev = NULL;
	ft_lstadd_front(&(stack->first), last);
	if (print)
		ft_printf("rr%c\n", stack->letter);
}

void	reverse_rotate_stacks(t_stack *a_stack, t_stack *b_stack)
{
	reverse_rotate_stack(a_stack, 0);
	reverse_rotate_stack(b_stack, 0);
	ft_printf("rrr\n");
}
