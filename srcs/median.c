/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babodere <babodere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 01:58:43 by babodere          #+#    #+#             */
/*   Updated: 2025/05/22 02:54:26 by babodere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*parse_to_int(int ac, char **av)
{
	int	*tab;
	int	index;

	tab = (int *)malloc(sizeof(int) * (ac - 1));
	if (!tab)
		return (NULL);
	index = 1;
	while (index < ac)
	{
		tab[index - 1] = ft_atoi(av[index]);
		index++;
	}
	return (tab);
}

void	ft_sort_int_tab(int *tab, int len)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len - 1)
		{
			if (tab[j] > tab[i])
			{
				temp = tab[j];
				tab[j] = tab[i];
				tab[i] = temp;
			}
			j++;
		}
		i++;
	}
}

int	*get_sorted_tab(int ac, char **av)
{
	int	*tab;

	tab = parse_to_int(ac, av);
	if (!tab)
		return (NULL);
	ft_sort_int_tab(tab, ac - 1);
	return (tab);
}
