/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babodere <babodere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 19:27:08 by babodere          #+#    #+#             */
/*   Updated: 2025/05/19 03:54:22 by babodere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	to_abs(int i)
{
	if (i < 0)
		return (-i);
	return (i);
}

int	rotate_order(int a, int b)
{
	if (a == 0 || b == 0)
		return (0);
	else if (a < 0 && b < 0)
		return (-1);
	else if (a > 0 && b > 0)
		return (1);
	return (0);
}

void	manage_rotate(t_stack *stack, int sign)
{
	int	rotate;
	
	rotate = to_abs(sign);
	while (rotate--)
	{
		if (sign < 0)
			reverse_rotate_stack(stack);
		else
			rotate_stack(stack);
	}
}

void print_stack(t_stack *stack)
{
	ft_printf("print stack %c\n", stack->letter);
	if (stack == NULL || !stack->first)
		ft_printf("STACK NULL\n");
	t_list *current = stack->first;
	while (current)
	{
		ft_printf("%d\n", current->number);	
		current = current->next;
	}
}

void	algo(t_stack *a, t_stack *b)
{
	t_list	*current;
	t_list	*target;

	while (a->size > 3)
	{
		current = get_smallest_cost(a, b);
		if (!current)
			return ;
		target = get_closer(b, current);
		manage_rotate(a, calculate_cost(ft_lstindex(a, current), a->size));
		if (current->number < target->number)
			manage_rotate(b, calculate_cost(ft_lstindex(b, get_closer(b, current)), b->size) + 1);
		else
			manage_rotate(b, calculate_cost(ft_lstindex(b, get_closer(b, current)), b->size));
		push_stack(a, b);
	}
}
