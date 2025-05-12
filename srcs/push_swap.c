/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babodere <babodere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:50:07 by babodere          #+#    #+#             */
/*   Updated: 2025/05/12 19:26:58 by babodere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a_stack;
	t_stack	*b_stack;

	(void) ac;
	if (!setup_stacks(av, &a_stack, &b_stack))
		return (ft_printf(ERROR_MESSAGE), free_all(a_stack, b_stack), 1);
	if (is_sorted(a_stack))
	{
		free_all(a_stack, b_stack);
		return (ft_printf("Sorted"), 0);
	}
	push_stack(a_stack, b_stack);
	push_stack(a_stack, b_stack);
	// start_algo(a_stack, b_stack);
	free_all(a_stack, b_stack);
	return (0);
}
