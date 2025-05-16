/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babodere <babodere@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:50:55 by babodere          #+#    #+#             */
/*   Updated: 2025/05/16 02:19:36 by babodere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define ERROR_MESSAGE "Error\n"

# include "../libft/libft.h"

typedef struct stack
{
	t_list	*first;
}	t_stack;

int		is_sorted(t_stack *stack);
int		check_a(t_stack *stack, t_list *current, t_list *list);
int		check_b(t_stack *stack, t_list *current, t_list *list);
int		is_between(t_list *prev, t_list *next, t_list *node);
int		setup_stacks(char **av, t_stack **a_stack, t_stack **b_stack);
int		find_index(t_stack *stack, t_list *list,
			int (*check)(t_stack *stack, t_list *current, t_list *list));
void	reverse_rotate_stacks(t_stack *a_stack, t_stack *b_stack);
void	reverse_rotate_stack(t_stack *stack);
void	swap_stack(t_stack *stack);
void	push_stack(t_stack *from_stack, t_stack *to_stack);
void	recursive_free(t_list *a);
void	rotate_stack(t_stack *stack);
void	free_all(t_stack *a, t_stack *b);

#endif