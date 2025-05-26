/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babodere <babodere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 04:54:44 by babodere          #+#    #+#             */
/*   Updated: 2025/05/26 04:54:44 by babodere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicates(t_stack *a_stack)
{ 
	t_list	*a_first;
	t_list	*temp;

	a_first = a_stack->first;
	while (a_first)
	{
		temp = a_first->next;
		while (temp)
		{
			if (a_first->number == temp->number)
				return (0);
			temp = temp->next;
		}
		a_first = a_first->next;
	}
	return (1);
}
