/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babodere <babodere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:50:07 by babodere          #+#    #+#             */
/*   Updated: 2025/06/17 04:22:57 by babodere         ###   ########.fr       */
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

void	algo_100(t_stack *a, t_stack *b, t_norm_idiot norm_idiot)
{
	int	ctr;

	ctr = 0;
	while (a->size > 3)
	{
		push_stack(a, b, 1);
		if (b->first->number > norm_idiot.median)
			rotate_stack(b, 1);
	}
	small_sort(a, a->first->number, a->first->next->number,
		a->first->next->next->number);
	push_back(a, b);
	put_smallest_on_top(a);
}

void	manage_sort(t_stack *a, t_stack *b, int size, int *tab)
{	
	if (size == 2)
	{
		if (a->first->number > a->first->next->number)
			swap_stack(a, 1);
	}
	else if (size == 3)
		small_sort(a, a->first->number,
			a->first->next->number,
			a->first->next->next->number);
	else if (size == 5)
		sort_for_5(a, b);
	else if (size <= 100)
		algo_100(a, b, create_struct(size, tab));
	else
		algo_500(a, b, create_struct(size, tab));
}

int	main(int ac, char **av)
{
	t_stack	*a_stack;
	t_stack	*b_stack;
	int		*tab;

	if (ac < 2)
		return (0);
	if (!setup_stacks(av, &a_stack, &b_stack, ac))
		return (ft_putstr_fd(ERROR_MESSAGE, 2), free_all(a_stack, b_stack), 0);
	b_stack->first = NULL;
	if (is_sorted(a_stack))
		return (free_all(a_stack, b_stack), 0);
	if (ac == 2)
		tab = get_sorted_tab(a_stack->size, ft_split(av[1], ' '));
	else
		tab = get_sorted_tab(ac, av);
	manage_sort(a_stack, b_stack, a_stack->size, tab);
	free_all(a_stack, b_stack);
	free(tab);
	return (0);
}
