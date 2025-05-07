/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babodere <babodere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 17:01:20 by babodere          #+#    #+#             */
/*   Updated: 2025/05/05 22:46:39 by babodere         ###   ########.fr       */
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

static int	parse_to_tab(char **av, t_list **a)
{
	t_list	*node;
	int		i;
	long	j;
	(*a) = NULL;

	i = 0;
	while (av[++i])
	{
		if(!is_number_correct(av[i]))
			return (recursive_free(a), ft_printf("Error"), 0);
		j = ft_bigatoi(av[i]);
		node = ft_lstnew(j);
		if (!node)
			return (recursive_free(a), ft_printf("Error"), 0);
		ft_lstadd_back(a, node);
	}
	return (1);
}

int	setup_stacks(char **av, t_stack **a_stack, t_stack **b_stack)
{
	t_list	*a_first;
	(*a_stack) = (t_stack *) malloc(sizeof(t_stack));
	if (!a_stack)
		return (0);
	(*b_stack) = (t_stack *) malloc(sizeof(t_stack));
	if (!b_stack)
		return (0);
	if(!parse_to_tab(av, &a_first))
		return (0);
	(*a_stack)->first = a_first;
	return (1);
}