/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babodere <babodere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 19:27:08 by babodere          #+#    #+#             */
/*   Updated: 2025/05/22 03:18:34 by babodere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_via_sign(t_stack *stack, int rotate, int sign)
{
	while (rotate--)
	{
		if (sign < 0)
			reverse_rotate_stack(stack, 1);
		else
			rotate_stack(stack, 1);
	}
}

void	manage_rotate(t_stack *a, t_stack *b, t_list *current)
{
	t_list	*target;
	int		a_sign;
	int		a_rotate;
	int		b_sign;
	int		b_rotate;

	a_sign = calculate_cost(ft_lstindex(a, current), a->size);
	target = get_closer(b, current);
	a_rotate = to_abs(a_sign);
	b_sign = calculate_cost(ft_lstindex(b, target), b->size);
	if (current->number > target->number)
		b_sign = calculate_cost(ft_lstindex(b, target), b->size) + 1;
	b_rotate = to_abs(b_sign);
	while (((b_sign < 0 && a_sign < 0) || (a_sign > 0 && b_sign > 0))
		&& a_rotate && b_rotate)
	{
		if (b_sign < 0)
			reverse_rotate_stacks(a, b);
		else
			rotate_stacks(a, b);
		b_rotate--;
		a_rotate--;
	}
	rotate_via_sign(a, a_rotate, a_sign);
	rotate_via_sign(b, b_rotate, b_sign);
}

void	put_smallest_on_top(t_stack *stack)
{
	t_list	*current;
	t_list	*smallest;
	int		sign;

	current = stack->first;
	smallest = current;
	while (current)
	{
		if (current->number < smallest->number)
			smallest = current;
		current = current->next;
	}
	sign = calculate_cost(ft_lstindex(stack, smallest), stack->size);
	rotate_via_sign(stack, to_abs(sign), sign);
}

void	push_back(t_stack *a, t_stack *b)
{
	t_list	*current;

	while (b->size)
	{
		current = get_smallest_cost(b, a);
		if (!current)
			return ;
		manage_rotate(b, a, current);
		push_stack(b, a);
	}
}

void	algo(t_stack *a, t_stack *b, t_norm_idiot norm_idiot)
{
	int	ctr;

	ctr = 0;
	while (ctr < (a->og_size / 2) - 1)
	{
		if (a->first->number > norm_idiot.median)
		{
			ctr++;
			push_stack(a, b);
			if (b->first->number <= norm_idiot.last)
				rotate_stack(b, 1);
			continue ;
		}
		reverse_rotate_stack(a, 1);
	}
	while (a->size > 3)
	{
		push_stack(a, b);
		if (b->first->number < norm_idiot.first)
			rotate_stack(b, 1);
	}
	small_sort(a, a->first->number, a->first->next->number,
		a->first->next->next->number);
	push_back(a, b);
	put_smallest_on_top(a);
}
