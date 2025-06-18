/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babodere <babodere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 23:59:32 by babodere          #+#    #+#             */
/*   Updated: 2025/05/21 05:53:24 by babodere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_between(t_list *prev, t_list *next, t_list *node)
{
	if (!prev || !next || !node)
		return (-1);
	return ((prev->number > node->number && node->number > next->number));
}

void	recursive_free(t_list *lst)
{
	t_list	*temp;

	if (!lst)
		return ;
	while (lst)
	{
		temp = lst->next;
		free(lst);
		lst = temp;
	}
	return ;
}

void	free_all(t_stack *a, t_stack *b)
{
	if (a->first)
		recursive_free(a->first);
	free(a);
	if (b->first)
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
