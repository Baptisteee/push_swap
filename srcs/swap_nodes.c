/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babodere <babodere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 23:01:40 by babodere          #+#    #+#             */
/*   Updated: 2025/05/22 02:52:18 by babodere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_stack *stack)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	first = stack->first;
	second = first->next;
	third = second->next;
	stack->first = second;
	second->next = first;
	second->prev = NULL;
	first->prev = second;
	first->next = third;
	third->prev = first;
	ft_printf("s%c\n", stack->letter);
}

void	swap_stacks(t_stack *a_stack, t_stack *b_stack)
{
	swap_stack(a_stack);
	swap_stack(b_stack);
}
