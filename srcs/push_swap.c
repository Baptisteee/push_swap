/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babodere <babodere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:50:07 by babodere          #+#    #+#             */
/*   Updated: 2025/05/21 22:05:20 by babodere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a_stack;
	t_stack	*b_stack;
	int		size;
	int		*tab;

	if (ac < 2)
		return (0);
	if (!setup_stacks(av, &a_stack, &b_stack))
		return (ft_printf(ERROR_MESSAGE), free_all(a_stack, b_stack), 0);
	if (is_sorted(a_stack))
		return (free_all(a_stack, b_stack), 0);
	if (ac == 4)
		small_sort(a_stack, a_stack->first->number, a_stack->first->next->number, a_stack->first->next->next->number);
	else
	{
		size = ft_lstsize(a_stack->first);
		a_stack->og_size = size;
		tab = get_sorted_tab(ac, av);
		b_stack->first = NULL;
		algo(a_stack, b_stack, tab[(ac - 1) / 4], tab[(ac - 1) / 2], tab[(ac - 1) / 4 * 3]);
	}
	free_all(a_stack, b_stack);
	return (0);
}
