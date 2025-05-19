/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babodere <babodere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:50:07 by babodere          #+#    #+#             */
/*   Updated: 2025/05/19 02:22:00 by babodere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a_stack;
	t_stack	*b_stack;

	if (ac < 2)
		return (0);
	if (!setup_stacks(av, &a_stack, &b_stack))
		return (ft_printf(ERROR_MESSAGE), free_all(a_stack, b_stack), 0);
	b_stack->first = NULL;
	if (is_sorted(a_stack))
		return (free_all(a_stack, b_stack), 0);
	push_stack(a_stack, b_stack);
	push_stack(a_stack, b_stack);
	algo(a_stack, b_stack);
	// t_list *current = b_stack->first;
	// t_list *smallest = current;
	// while (current)
	// {
	// 	if (current->number < smallest->number)
	// 		smallest = current;
	// 	current = current->next;
	// }
	// manage_rotate(b_stack, smallest, check_a);
	// current = b_stack->first;
	// while (current)
	// {
	// 	ft_printf("%d\n", current->number);
	// 	current = current->next;
	// }
	// ft_printf("End");
	free_all(a_stack, b_stack);
	return (0);
}
