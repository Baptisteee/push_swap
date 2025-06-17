/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babodere <babodere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 23:01:40 by babodere          #+#    #+#             */
/*   Updated: 2025/06/17 04:25:24 by babodere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_stack *stack, int print)
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
	if (third)
		third->prev = first;
	if (print)
		ft_printf("s%c\n", stack->letter);
}

void	swap_stacks(t_stack *a_stack, t_stack *b_stack, int print)
{
	swap_stack(a_stack, 0);
	swap_stack(b_stack, 0);
	if (print)
		ft_printf("ss");
}
