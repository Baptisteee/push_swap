/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babodere <babodere@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:14:35 by babodere          #+#    #+#             */
/*   Updated: 2025/05/16 02:09:36 by babodere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	if (!lst)
	{
		*lst = new;
		return ;
	}
	new->next = *lst;
	(*lst)->prev = new;
	*lst = new;
}

// #include <stdio.h>

// int	main(void)
// {
// 	t_list	*list;
// 	t_list	*new;

// 	list = malloc(sizeof(t_list));
// 	new = malloc(sizeof(t_list));
// 	list->number = 1;
// 	new->number = 2;
// 	ft_lstadd_front(&list, new);
// 	printf("First element: %d\n", list->number);
// 	printf("Second element: %d\n", list->next->number);
// 	printf("First element prev: %d\n", list->next->prev->number);
// 	return (0);
// }