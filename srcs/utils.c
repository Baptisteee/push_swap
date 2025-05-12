/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babodere <babodere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 23:59:32 by babodere          #+#    #+#             */
/*   Updated: 2025/05/12 20:05:33 by babodere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_between(t_list *prev, t_list *next, t_list *node)
{
	return ((prev->number < node->number < next->number)
		|| (prev->number > node->number > next->number));
}

void	recursive_free(t_list *a)
{
	t_list	*temp;

	temp = NULL;
	if (!a)
		return ;
	while (a)
	{
		temp = a->next;
		free(a);
		a = temp;
	}
	return ;
}

void	free_all(t_stack *a, t_stack *b)
{
	if (a && a->first != NULL)
		recursive_free(a->first);
	free(a);
	if (b && b->first != NULL)
		recursive_free(b->first);
	free(b);
}

int	is_sorted(t_stack *stack)
{
	t_list	*node;

	node = stack->first;
	while (node->next)
	{
		if (node->number > node->next->number)
			return (0);
		node = node->next;
	}
	return (1);
}
