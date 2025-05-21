/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babodere <babodere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:50:55 by babodere          #+#    #+#             */
/*   Updated: 2025/05/21 21:30:55 by babodere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define ERROR_MESSAGE "Error\n"

# include "../libft/libft.h"
# include <stdio.h>

typedef struct stack
{
	t_list	*first;
	char	letter;
	int		size;
	int		og_size;
}			t_stack;

int		to_abs(int i);
int		is_sorted(t_stack *stack);
int		is_between(t_list *prev, t_list *next, t_list *node);
int		setup_stacks(char **av, t_stack **a_stack, t_stack **b_stack);
int		calculate_cost(int index, int size);
int		ft_lstindex(t_stack *stack, t_list *list);
int		*get_sorted_tab(int ac, char **av);
void	reverse_rotate_stacks(t_stack *a_stack, t_stack *b_stack);
void	reverse_rotate_stack(t_stack *stack, int print);
void	algo(t_stack *a, t_stack *b, int first, int median, int last);
void	swap_stack(t_stack *stack);
void	push_stack(t_stack *from_stack, t_stack *to_stack);
void	recursive_free(t_list *lst);
void	rotate_stack(t_stack *stack, int print);
void	rotate_stacks(t_stack *a_stack, t_stack *b_stack);
void	manage_rotate(t_stack *a, t_stack *b, t_list *current);
void	small_sort(t_stack *stack, int first, int second, int third);
void	free_all(t_stack *a, t_stack *b);
t_list	*get_smallest_cost(t_stack *a, t_stack *b);
t_list	*get_closer(t_stack *stack, t_list *list);

#endif