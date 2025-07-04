/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babodere <babodere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 17:01:20 by babodere          #+#    #+#             */
/*   Updated: 2025/06/19 15:02:44 by babodere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static long	ft_bigatoi(const char *s)
{
	const char	*tmp;
	long		result;
	int			sign;

	tmp = s;
	result = 0;
	sign = 1;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s && *s >= '0' && *s <= '9')
	{
		result = (result * 10) + (*s++ - '0') * sign;
	}
	if (*s == *tmp || (*s != '\0' && *s != ' '))
		return (INT_MAX);
	return (result);
}

static int	is_number_correct(char *num)
{
	long	atoi;
	int		index;

	index = -1;
	if (ft_strlen(num) == 1 && num[0] == '-')
		return (0);
	while (num[++index])
	{
		if (index == 0 && !ft_isdigit(num[index]) && num[index] != '-')
			return (0);
		else if (!ft_isdigit(num[index]) && index != 0)
			return (0);
	}
	if (ft_strlen(num) > 11)
		return (0);
	atoi = ft_bigatoi(num);
	if (atoi > INT_MAX || atoi < INT_MIN)
		return (0);
	return (1);
}

static int	parse_to_tab(char *av, t_list **a)
{
	char	**splitted_av;
	t_list	*node;
	int		i;
	long	j;

	(*a) = NULL;
	splitted_av = ft_split(av, ' ');
	if (!splitted_av)
		return (free(av), recursive_free(*a), 0);
	i = -1;
	while (splitted_av[++i])
	{
		if (!is_number_correct(splitted_av[i]))
			return (free_tab(splitted_av), recursive_free(*a), 0);
		j = ft_bigatoi(splitted_av[i]);
		node = ft_lstnew(j);
		if (!node)
			return (free_tab(splitted_av), recursive_free(*a), 0);
		ft_lstadd_back(a, node);
	}
	free_tab(splitted_av);
	return (1);
}

void	set_variables(t_stack *a, t_stack *b)
{
	a->size = ft_lstsize(a->first);
	b->size = 0;
	a->letter = 'a';
	b->letter = 'b';
	a->og_size = ft_lstsize(a->first);
}

int	setup_stacks(char *av, t_stack **a_stack, t_stack **b_stack)
{
	t_list	*a_first;

	(*a_stack) = (t_stack *)malloc(sizeof(t_stack));
	if (!*a_stack)
		return (free(av), 0);
	(*b_stack) = (t_stack *)malloc(sizeof(t_stack));
	if (!*b_stack)
		return (free(av), free(*a_stack), 0);
	if (!parse_to_tab(av, &a_first))
		return (free(*a_stack), free(*b_stack), 0);
	if (!a_first)
		return (free(*a_stack), free(*b_stack), 0);
	(*a_stack)->first = a_first;
	set_variables(*a_stack, *b_stack);
	if (!check_duplicates(*a_stack))
		return (free(*a_stack), free(*b_stack), 0);
	return (1);
}
