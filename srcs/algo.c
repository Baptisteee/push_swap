/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babodere <babodere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 19:27:08 by babodere          #+#    #+#             */
/*   Updated: 2025/05/21 22:11:59 by babodere         ###   ########.fr       */
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

	target = get_closer(b, current);
	a_sign = calculate_cost(ft_lstindex(a, current), a->size);
	a_rotate = to_abs(a_sign);
	b_sign = calculate_cost(ft_lstindex(b, get_closer(b, current)), b->size);
	if (current->number > target->number)
		b_sign = calculate_cost(ft_lstindex(b, get_closer(b, current)), b->size) + 1;
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
	t_list	*target;

	while (b->size)
	{
		target = get_smallest_cost(b, a);
		if (!target)
			return ;
		manage_rotate(b, a, target);
		push_stack(b, a);
	}
}

void	algo(t_stack *a, t_stack *b, int first, int median, int last)
{
	t_list	*current;
	int		temp_number;

	while (a->size > a->og_size / 2 + 1)
	{
		current = a->first;
		temp_number = current->number;
		if (temp_number < first)
		{
			push_stack(a, b);
			rotate_stack(b, 1);
		}
		else if (temp_number > first && temp_number < median)
			push_stack(a, b);
		else
			reverse_rotate_stack(a, 1);
	}
	while (a->size > 3)
	{
		current = a->first;
		temp_number = current->number;
		if (temp_number > median && temp_number < last)
		{
			push_stack(a, b);
			rotate_stack(b, 1);
		}
		else
			push_stack(a, b);
	}
	small_sort(a, a->first->number, a->first->next->number,
		a->first->next->next->number);
}
