/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babodere <babodere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 23:59:32 by babodere          #+#    #+#             */
/*   Updated: 2025/05/07 05:54:13 by babodere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	recursive_free(t_list *a)
{
	t_list	*temp;
	
	if (!a)
		return ;
	while (a)
	{
		temp = (a)->next;
		free(a);
		a = temp;
	}
	return ;
}

void	free_all(t_stack *a, t_stack *b)
{
	recursive_free(a->first);
	recursive_free(b->first);
	free(a);
	free(b);
}