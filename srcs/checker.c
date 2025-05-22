/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babodere <babodere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:58:52 by babodere          #+#    #+#             */
/*   Updated: 2025/05/22 03:39:32 by babodere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	manage_move(t_stack *a, t_stack *b, char *line)
{
	if (!ft_strncmp(line, "ra", 2))
		rotate_stack(a, 0);
	if (!ft_strncmp(line, "rb", 2))
		rotate_stack(b, 0);
	if (!ft_strncmp(line, "rr", 2))
		rotate_stacks(a, b);
	if (!ft_strncmp(line, "rra", 3))
		reverse_rotate_stack(a, 0);
	if (!ft_strncmp(line, "rrb", 3))
		reverse_rotate_stack(b, 0);
	if (!ft_strncmp(line, "rrr", 3))
		reverse_rotate_stacks(a, b);
	if (!ft_strncmp(line, "pa", 2))
		push_stack(b, a);
	if (!ft_strncmp(line, "pb", 2))
		push_stack(a, b);
	if (!ft_strncmp(line, "sa", 2))
		swap_stack(a);
	if (!ft_strncmp(line, "sb", 2))
		swap_stack(b);
}

int	main(int ac, char **av)
{
	t_stack	*a_stack;
	t_stack	*b_stack;
	char	*line;

	if (ac < 2)
		return (0);
	if (!setup_stacks(av, &a_stack, &b_stack))
		return (ft_printf(ERROR_MESSAGE), free_all(a_stack, b_stack), 0);
	b_stack->first = NULL;
	if (is_sorted(a_stack))
		return (free_all(a_stack, b_stack), 0);
	line = get_next_line(0);
	while (line)
	{
		manage_move(a_stack, b_stack, line);
		free(line);
		line = get_next_line(0);
	}
	free(line);
	if (is_sorted(a_stack))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_all(a_stack, b_stack);
}
