/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babodere <babodere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 23:01:40 by babodere          #+#    #+#             */
/*   Updated: 2025/05/19 03:51:38 by babodere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_stack *stack)
{
	t_list	*first;
	int		temp;

	first = stack->first;
	temp = first->number;
	first->number = first->next->number;
	first->next->number = temp;
	ft_printf("s%c\n", stack->letter);
}

void	swap_stacks(t_stack *a_stack, t_stack *b_stack)
{
	swap_stack(a_stack);
	swap_stack(b_stack);
}
