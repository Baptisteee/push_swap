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
#include <unistd.h>

int	manage_move(t_stack *a, t_stack *b, char *line)
{
	line[ft_strlen(line) - 1] = 0;
	if (!ft_strcmp(line, "ra"))
		return (rotate_stack(a, 0), 0);
	else if (!ft_strcmp(line, "rb"))
		return (rotate_stack(b, 0), 0);
	else if (!ft_strcmp(line, "rr"))
		return (rotate_stacks(a, b, 0), 0);
	else if (!ft_strcmp(line, "rra"))
		return (reverse_rotate_stack(a, 0), 0);
	else if (!ft_strcmp(line, "rrb"))
		return (reverse_rotate_stack(b, 0), 0);
	else if (!ft_strcmp(line, "rrr"))
		return (reverse_rotate_stacks(a, b, 0), 0);
	else if (!ft_strcmp(line, "pa"))
		return (push_stack(b, a, 0), 0);
	else if (!ft_strcmp(line, "pb"))
		return (push_stack(a, b, 0), 0);
	else if (!ft_strcmp(line, "sa"))
		return (swap_stack(a, 0), 0);
	else if (!ft_strcmp(line, "sb"))
		return (swap_stack(b, 0), 0);
	return (1);
}

void	print_result(int i)
{	
	if (i)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

void	read_checker_line(t_stack *a_stack, t_stack *b_stack)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (manage_move(a_stack, b_stack, line))
		{
			ft_printf("Error\n");
			free(line);
			free_all(a_stack, b_stack);
			exit(1);
		}
		free(line);
		line = get_next_line(0);
	}
	free(line);
}

int	main(int ac, char **av)
{
	t_stack	*a_stack;
	t_stack	*b_stack;
	char	*input;

	if (ac < 2)
		return (0);
	input = get_all_nbrs(av, ac, get_total_size(av, ac));
	if (!input)
		return (1);
	if (!setup_stacks(input, &a_stack, &b_stack))
		return (free(input), ft_putstr_fd(ERROR_MESSAGE, 2), 1);
	b_stack->first = NULL;
	read_checker_line(a_stack, b_stack);
	print_result(is_sorted(a_stack));
	free(input);
	free_all(a_stack, b_stack);
}
