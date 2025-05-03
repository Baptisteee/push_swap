/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babodere <babodere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 22:40:15 by babodere          #+#    #+#             */
/*   Updated: 2025/05/03 23:03:40 by babodere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_stack(t_stack *from_stack, t_stack *to_stack)
{
	t_list	*pushed_node;

	pushed_node = from_stack->first;
	from_stack->first = pushed_node->next;
	ft_lstadd_front(&(to_stack->first), pushed_node);
}