/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babodere <babodere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:50:07 by babodere          #+#    #+#             */
/*   Updated: 2025/05/22 18:01:57 by babodere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_norm_idiot	create_struct(int ac, int *tab)
{
	t_norm_idiot	norm_idiot;

	norm_idiot.first = tab[(ac - 1) / 4];
	norm_idiot.median = tab[(ac - 1) / 2];
	norm_idiot.last = tab[(ac - 1) / 4 * 3];
	return (norm_idiot);
}

int	main(int ac, char **av)
{
	t_stack	*a_stack;
	t_stack	*b_stack;
	int		*tab;
	

	if (ac < 2)
		return (0);
	if (!setup_stacks(av, &a_stack, &b_stack))
		return (ft_printf(ERROR_MESSAGE), free_all(a_stack, b_stack), 0);
	b_stack->first = NULL;
	if (is_sorted(a_stack))
		return (free_all(a_stack, b_stack), 0);
	tab = get_sorted_tab(ac, av);
	if (ac == 4)
		small_sort(a_stack, a_stack->first->number,
			a_stack->first->next->number,
			a_stack->first->next->next->number);
	else
	{
		a_stack->og_size = ft_lstsize(a_stack->first);
		algo(a_stack, b_stack, create_struct(ac - 1, tab));
	}
	free_all(a_stack, b_stack);
	free(tab);
	return (0);
}
