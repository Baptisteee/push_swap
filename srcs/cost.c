/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babodere <babodere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 23:29:21 by babodere          #+#    #+#             */
/*   Updated: 2025/05/26 06:05:37 by babodere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	to_abs(int i)
{
	if (i < 0)
		return (i * -1);
	return (i);
}

int	calculate_cost(int index, int size)
{
	if (index >= (size / 2))
		return (-(size - index));
	else
		return (index);
}

int	ft_lstindex(t_stack *stack, t_list *list)
{
	t_list	*current;
	int		index;

	current = stack->first;
	index = 0;
	while (current)
	{
		if (current->number == list->number)
			break ;
		index++;
		current = current->next;
	}
	return (index);
}

t_list	*test(t_stack *stack, t_list *list)
{
	t_list	*current;
	t_list	*before;
	t_list	*after;
	t_list	*min;
	int index;

	current = stack->first;
	index = 0;
	while (current->next)
	{
		if (current->number < list->number < current->next->number)
		{
			before = current;
			after = current->next;
			if (index > stack->size / 2)
				return (after);
			return (before);
		}
		index++;
		current = current->next;
	}
	if (current->number < list->number < stack->first)
		return (stack->first);
	
}


t_list	*get_closer(t_stack *stack, t_list *list)
{
	t_list	*current;
	t_list	*retval;
	int		diff;

	current = stack->first;
	diff = -1;
	while (current)
	{
		if (diff > to_abs(current->number - list->number) || diff == -1)
		{
			diff = to_abs(current->number - list->number);
			retval = current;
		}
		current = current->next;
	}
	return (retval);
}

t_list	*get_smallest_cost(t_stack *a, t_stack *b)
{
	t_list	*current;
	t_list	*smallest;
	int		cost;
	int		temp_a;
	int		temp_b;

	if (!a->first)
		return (NULL);
	current = a->first;
	cost = -1;
	temp_a = 0;
	while (current)
	{
		temp_b = ft_lstindex(b, get_closer(b, current));
		if (to_abs(calculate_cost(temp_a, a->size))
			+ to_abs(calculate_cost(temp_b, b->size)) < cost || cost == -1)
		{
			smallest = current;
			cost = to_abs(calculate_cost(temp_a, a->size))
				+ to_abs(calculate_cost(temp_b, b->size));
		}
		temp_a++;
		current = current->next;
	}
	return (smallest);
}
