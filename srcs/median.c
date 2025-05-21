/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babodere <babodere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 01:58:43 by babodere          #+#    #+#             */
/*   Updated: 2025/05/21 20:50:20 by babodere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*parse_to_int(int ac, char **av)
{
	int	*tab;
	int	index;

	tab = (int *) malloc(sizeof(int) * (ac - 1));
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
	int	index;
	int	temp;

	index = 0;
	while (tab[index] && index < len - 1)
	{
		if (tab[index] > tab[index + 1])
		{
			temp = tab[index];
			tab[index] = tab[index + 1];
			tab[index + 1] = temp;
			index = 0; 
		}
		else
			index++;
	}
}

int	*get_sorted_tab(int ac, char **av)
{
	int	*tab;
	
	tab = parse_to_int(ac, av);
	ft_sort_int_tab(tab, ac - 1);
	return (tab);
}