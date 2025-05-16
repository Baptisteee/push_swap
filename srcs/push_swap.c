/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babodere <babodere@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:50:07 by babodere          #+#    #+#             */
/*   Updated: 2025/05/16 02:22:30 by babodere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print(t_stack *stack, char c)
{
	t_list	*node;

	node = stack->first;
	ft_printf("\n%c: ", c);
	while (node)
	{
		ft_printf("%d ", node->number);
		node = node->next;
	}
}

void	print_cost(t_stack *b_stack, t_stack *a_stack, t_list *node)
{
	int	i;

	ft_printf("\nNODE: %d", node->number);
	i = find_index(a_stack, node, check_a);
	ft_printf("\nCOST A : %d", i);
	i = find_index(b_stack, node, check_b);
	ft_printf("\nCOST B : %d", i);
}

int	main(int ac, char **av)
{
	t_stack	*a_stack;
	t_stack	*b_stack;

	if (ac < 2)
		return (0);
	if (!setup_stacks(av, &a_stack, &b_stack))
		return (ft_printf(ERROR_MESSAGE), free_all(a_stack, b_stack), 1);
	b_stack->first = NULL;
	if (is_sorted(a_stack))
	{
		free_all(a_stack, b_stack);
		return (ft_printf("Sorted"), 0);
	}
	push_stack(a_stack, b_stack);
	push_stack(a_stack, b_stack);
	t_list	*node = a_stack->first;
	print(a_stack, 'A');
	print(b_stack, 'B');
	push_stack(a_stack, b_stack);
	push_stack(a_stack, b_stack);
	print(a_stack, 'A');
	print(b_stack, 'B');
	node = a_stack->first->next->next;
	print_cost(b_stack, a_stack, node);
	reverse_rotate_stack(a_stack);
	rotate_stack(b_stack);
	push_stack(a_stack, b_stack);
	print(a_stack, 'A');
	print(b_stack, 'B');
	node = a_stack->first;
	print_cost(b_stack, a_stack, node);
	reverse_rotate_stack(b_stack);
	reverse_rotate_stack(b_stack);
	push_stack(a_stack, b_stack);
	print(a_stack, 'A');
	print(b_stack, 'B');
	print_cost(b_stack, a_stack, a_stack->first);
	rotate_stack(b_stack);
	rotate_stack(b_stack);
	push_stack(a_stack, b_stack);
	print(a_stack, 'A');
	print(b_stack, 'B');
	free_all(a_stack, b_stack);
	return (0);
}
