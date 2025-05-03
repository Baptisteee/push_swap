/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babodere <babodere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 04:15:16 by babodere          #+#    #+#             */
/*   Updated: 2025/04/28 02:27:47 by babodere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int number)
{
	t_list	*list;

	list = (t_list *) malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->number = number;
	list->next = NULL;
	return (list);
}
