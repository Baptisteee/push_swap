/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babodere <babodere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 23:29:21 by babodere          #+#    #+#             */
/*   Updated: 2025/05/12 20:17:59 by babodere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_cost_a(t_stack *stack, t_list *list)
{
	t_list	*current;
	int		size;
	int		index;

	current = stack->first;
	index = 0;
	size = ft_lstsize(current);
	while (current)
	{
		if (current->number == list->number)
			break ;
		index++;
		current = current->next;
	}
	if (index > (size / 2) - 1)
		return (-(size - index));
	else
		return (index);
}

static int	get_cost_b(t_stack *stack, t_list *list)
{
	t_list	*current;
	int		size;
	int		index;

	current = stack->first;
	index = 0;
	size = ft_lstsize(current);
	while (current)
	{
		if (is_between(current->prev, current->next, list))
			break ;
		index++;
		current = current->next;
	}
	if (index > (size / 2) - 1)
		return (-(size - index));
	else
		return (index);
}

int	get_cost(t_stack *a, t_stack *b, t_list *list)
{
	return (get_cost_a(a, list) + get_cost_b(b, list));
}
