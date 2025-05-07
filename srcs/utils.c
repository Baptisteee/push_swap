/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babodere <babodere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 23:59:32 by babodere          #+#    #+#             */
/*   Updated: 2025/05/05 22:45:05 by babodere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	recursive_free(t_list **a)
{
	t_list	*temp;
	
	if (!a|| !(*a))
		return ;
	while (*a)
	{
		temp = (*a)->next;
		free(*a);
		*a = temp;
	}
	free(a);
	return ;
}