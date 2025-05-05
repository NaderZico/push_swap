/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_normalize.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakhalil <nakhalil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 03:32:20 by nakhalil          #+#    #+#             */
/*   Updated: 2025/04/02 15:23:49 by nakhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

static int	*create_sorted_copy(int *copy, int size)
{
	int	*sorted;

	sorted = ft_calloc(size, sizeof(int));
	if (!sorted)
		return (NULL);
	ft_memcpy(sorted, copy, sizeof(int) * size);
	sort_array(sorted, size);
	return (sorted);
}

static void	normalize_stack(t_stack *stack, int *original, int *sorted,
		int *index_map)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->size)
	{
		j = 0;
		while (j < stack->size)
		{
			if (original[j] == sorted[i])
			{
				index_map[j] = i;
				break ;
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (i < stack->size)
	{
		stack->data[i] = index_map[i];
		i++;
	}
}

static void	apply_normalization(t_stack *stack, int *original, int *sorted)
{
	int	*index_map;

	index_map = malloc(stack->size * sizeof(int));
	if (!index_map)
		return ;
	normalize_stack(stack, original, sorted, index_map);
	free(index_map);
}

int	normalize_main(t_stack *stack)
{
	int	*copy;
	int	*sorted;

	copy = ft_calloc(stack->size, sizeof(int));
	if (!copy)
		return (0);
	ft_memcpy(copy, stack->data, sizeof(int) * stack->size);
	sorted = create_sorted_copy(copy, stack->size);
	if (!sorted)
	{
		free(copy);
		return (0);
	}
	apply_normalization(stack, copy, sorted);
	free(copy);
	free(sorted);
	update_min_max(stack);
	return (1);
}
