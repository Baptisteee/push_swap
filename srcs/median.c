/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babodere <babodere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 01:58:43 by babodere          #+#    #+#             */
/*   Updated: 2025/06/19 04:03:37 by babodere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>

int	*parse_to_int(int ac, char **av)
{
	int	*tab;
	int	index;

	tab = (int *)malloc(sizeof(int) * ac);
	if (!tab)
		return (NULL);
	index = 0;
	while (index < ac)
	{
		tab[index] = ft_atoi(av[index]);
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

size_t	get_tab_size(char **tab)
{
	size_t	size;
	int		index;

	size = 0;
	index = -1;
	while (tab[++index])
		size++;
	return (size);
}

int	*get_sorted_tab(char *av)
{
	int		*tab;
	char	**splitted_av;
	size_t	size;

	splitted_av = ft_split(av, ' ');
	if (!splitted_av)
		return (NULL);
	size = get_tab_size(splitted_av);
	tab = parse_to_int(size, splitted_av);
	if (!tab)
		return (free_tab(splitted_av), NULL);
	ft_sort_int_tab(tab, size);
	free_tab(splitted_av);
	return (tab);
}
