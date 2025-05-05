/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_validation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakhalil <nakhalil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 03:30:19 by nakhalil          #+#    #+#             */
/*   Updated: 2025/03/26 03:47:48 by nakhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicates(t_stack *stack)
{
	int	i;
	int	j;

	i = -1;
	while (++i < stack->size)
	{
		j = i;
		while (++j < stack->size)
			if (stack->data[i] == stack->data[j])
				return (1);
	}
	return (0);
}

static int	parse_args_to_stack(char **args, t_stack *stack)
{
	int	i;

	i = -1;
	while (++i < stack->size)
	{
		if (!ft_atoi_checked(args[i], &stack->data[i]))
			return (0);
	}
	return (1);
}

int	validate_arguments(char **args, t_stack *stack)
{
	if (!parse_args_to_stack(args, stack) || check_duplicates(stack))
		return (0);
	return (1);
}

int	ft_atoi_checked(const char *str, int *num)
{
	long	result;
	int		sign;
	int		digit_found;

	result = 0;
	sign = 1;
	digit_found = 0;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
		sign = 1 - 2 * (*str++ == '-');
	if (!ft_isdigit(*str))
		return (0);
	while (ft_isdigit(*str))
	{
		result = result * 10 + (*str++ - '0');
		digit_found = 1;
		if ((sign == 1 && result > INT_MAX) || (sign == -1
				&& result > (long)INT_MAX + 1))
			return (0);
	}
	if (!digit_found || *str != '\0')
		return (0);
	*num = (int)(result * sign);
	return (1);
}
