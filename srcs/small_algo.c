/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babodere <babodere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:37:37 by babodere          #+#    #+#             */
/*   Updated: 2025/06/17 04:28:32 by babodere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_sort(t_stack *stack, int first, int second, int third)
{
	if (is_sorted(stack))
		return ;
	if (first < second && second > third && first < third)
	{
		swap_stack(stack, 1);
		rotate_stack(stack, 1);
	}
	else if (first < second && second > third && first > third)
		reverse_rotate_stack(stack, 1);
	else if (first > second && second < third && first < third)
		swap_stack(stack, 1);
	else if (first > second && second < third && first > third)
		rotate_stack(stack, 1);
	else if (first > second && second > third && first > third)
	{
		swap_stack(stack, 1);
		reverse_rotate_stack(stack, 1);
	}
}

t_list	*get_smallest(t_stack *stack)
{
	t_list	*current;
	t_list	*retval;
	int		nbr;

	current = stack->first;
	retval = current;
	nbr = retval->number;
	while (current)
	{
		if (current->number < nbr)
		{
			retval = current;
			nbr = retval->number;
		}
		current = current->next;
	}
	return (retval);
}

void	push_smallest(t_stack *a, t_stack *b)
{
	int	size;
	int	rotate;

	size = ft_lstsize(a->first);
	rotate = calculate_cost(ft_lstindex(a, get_smallest(a)), size);
	while (rotate)
	{
		if (rotate > 0)
		{
			rotate--;
			rotate_stack(a, 1);
		}
		else if (rotate < 0)
		{
			rotate++;
			reverse_rotate_stack(a, 1);
		}
	}
	push_stack(a, b, 1);
}

void	sort_for_5(t_stack *a, t_stack *b)
{
	push_smallest(a, b);
	push_smallest(a, b);
	small_sort(a, a->first->number, a->first->next->number,
		a->first->next->next->number);
	if (b->first->number < b->first->next->number)
		swap_stack(b, 1);
	push_stack(b, a, 1);
	push_stack(b, a, 1);
}
