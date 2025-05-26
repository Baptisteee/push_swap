/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babodere <babodere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 17:01:20 by babodere          #+#    #+#             */
/*   Updated: 2025/05/26 05:37:40 by babodere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

	index = 0;
	while (num[index])
	{
		if (!ft_isdigit(num[index++]))
			return (0);
	}
	if (ft_strlen(num) > 11)
		return (0);
	atoi = ft_bigatoi(num);
	if (atoi > INT_MAX || atoi < INT_MIN)
		return (0);
	return (1);
}

static int	parse_to_tab(char **av, t_list **a, int ac)
{
	t_list	*node;
	int		i;
	long	j;

	(*a) = NULL;
	if (ac == 2)
		i = -1;
	else
		i = 0;
	while (av[++i])
	{
		if (!is_number_correct(av[i]))
			return (0);
		j = ft_bigatoi(av[i]);
		node = ft_lstnew(j);
		if (!node)
			return (0);
		ft_lstadd_back(a, node);
	}
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

int	setup_stacks(char **av, t_stack **a_stack, t_stack **b_stack, int ac)
{
	t_list	*a_first;
	char	**split;

	split = av;
	(*a_stack) = (t_stack *)malloc(sizeof(t_stack));
	if (!a_stack)
		return (0);
	(*b_stack) = (t_stack *)malloc(sizeof(t_stack));
	if (!b_stack)
		return (0);
	if (ac == 2)
		split = ft_split(av[1], ' ');
	if (!parse_to_tab(split, &a_first, ac))
		return (0);
	if (!a_first)
		return (0);
	(*a_stack)->first = a_first;
	set_variables(*a_stack, *b_stack);
	return (check_duplicates(*a_stack));
}
