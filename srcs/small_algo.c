/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babodere <babodere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:37:37 by babodere          #+#    #+#             */
/*   Updated: 2025/05/20 23:20:07 by babodere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_sort(t_stack *stack, int first, int second, int third)
{
	if (is_sorted(stack))
		return ;
	if (first < second && second > third && first < third)
	{
		swap_stack(stack);
		rotate_stack(stack, 1);
	}
	else if (first < second && second > third && first < third)
		reverse_rotate_stack(stack, 1);
	else if (first > second && second < third && first < third)
		swap_stack(stack);
	else if (first > second && second < third && first > third)
		rotate_stack(stack, 1);
	else if (first > second && second > third && first > third)
	{
		swap_stack(stack);
		reverse_rotate_stack(stack, 1);
	}
}
