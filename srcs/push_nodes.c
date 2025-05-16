/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babodere <babodere@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 22:40:15 by babodere          #+#    #+#             */
/*   Updated: 2025/05/16 02:22:48 by babodere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_stack(t_stack *from_stack, t_stack *to_stack)
{
	t_list	*pushed_node;

	pushed_node = from_stack->first;
	from_stack->first = pushed_node->next;
	if (from_stack->first)
		from_stack->first->prev = NULL;
	pushed_node->prev = NULL;
	if (!to_stack->first)
	{
		to_stack->first = pushed_node;
		pushed_node->next = NULL;
	}
	else
		ft_lstadd_front(&(to_stack->first), pushed_node);
}
