/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babodere <babodere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:50:07 by babodere          #+#    #+#             */
/*   Updated: 2025/05/07 05:27:52 by babodere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a_stack;
	t_stack	*b_stack;

	(void) ac;
	if (!setup_stacks(av, &a_stack, &b_stack))
		return (ft_printf(ERROR_MESSAGE), 0);
	t_list *temp = a_stack->first;
	while (temp)
	{
		ft_printf("%d - ", temp->number);
		temp = temp->next;
	}
	ft_printf("\n\n\n");
	rotate_stack(a_stack);
	temp = a_stack->first;
	while (temp)
	{
		ft_printf("%d - ", temp->number);
		temp = temp->next;
	}
	ft_printf("\n\n\n");
	reverse_rotate_stack(a_stack);
	temp = a_stack->first;
	while (temp)
	{
		ft_printf("%d - ", temp->number);
		temp = temp->next;
	}
	ft_printf("\n\n\n");
	push_stack(a_stack, b_stack);
	temp = a_stack->first;
	while (temp)
	{
		ft_printf("%d - ", temp->number);
		temp = temp->next;
	}
	ft_printf("\n\n\n");
	push_stack(b_stack, a_stack);
	temp = a_stack->first;
	while (temp)
	{
		ft_printf("%d - ", temp->number);
		temp = temp->next;
	}
	temp = a_stack->first->next->next->next;
	ft_printf("\n\n%d\n%d\n\n\n%d", temp->number, get_cost_a(a_stack, temp), (ft_lstsize(a_stack->first)));
	recursive_free(&a_stack->first);
	recursive_free(&b_stack->first);
	return (0);
}
