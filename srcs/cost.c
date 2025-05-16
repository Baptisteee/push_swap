/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babodere <babodere@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 23:29:21 by babodere          #+#    #+#             */
/*   Updated: 2025/05/16 02:20:12 by babodere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calculate_cost(int index, int size)
{
	if (index > (size / 2))
		return (-(size - index));
	else
		return (index);
}

int	check_a(t_stack *stack, t_list *current, t_list *list)
{
	(void) stack;
	return (current->number == list->number);
}

int	check_b(t_stack *stack, t_list *current, t_list *list)
{
	if (current->prev == NULL)
		return (is_between(ft_lstlast(current), current, list));
	if (current == NULL)
		return (is_between(current->prev, stack->first, list));
	return (is_between(current->prev, current, list));
}

int	find_index(t_stack *stack, t_list *list,
	int (*check)(t_stack *stack, t_list *current, t_list *list))
{
	t_list	*current;
	int		size;
	int		index;

	current = stack->first;
	index = 0;
	size = ft_lstsize(current);
	while (current)
	{
		if (check(stack, current, list))
			break ;
		index++;
		current = current->next;
	}
	return (calculate_cost(index, size));
}
