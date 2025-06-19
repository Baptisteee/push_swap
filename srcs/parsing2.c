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
#include <linux/limits.h>
#include <stddef.h>

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

size_t	get_total_size(char **av, int ac)
{
	char	**temp;
	size_t	size;
	int		i;
	int		j;

	i = 0;
	size = 0;
	while (++i < ac)
	{
		j = -1;
		temp = ft_split(av[i], ' ');
		if (!temp)
			return (0);
		while (temp[++j])
			size += ft_strlen(temp[j]) + 1;
		free_tab(temp);
	}
	return (size);
}

char	*get_all_nbrs(char **av, int ac, size_t size)
{
	char	*retval;
	char	**temp;
	int		index;
	int		i;

	if (size == 0)
		return (NULL);
	retval = ft_calloc(sizeof(char), size + 1);
	if (!retval)
		return (NULL);
	index = 0;
	while (++index < ac)
	{
		i = -1;
		temp = ft_split(av[index], ' ');
		if (!temp)
			return (free(retval), NULL);
		while (temp[++i])
		{
			ft_strcat(retval, temp[i]);
			ft_strcat(retval, " ");
		}
		free_tab(temp);
	}
	return (retval[ft_strlen(retval)] = 0, retval);
}
