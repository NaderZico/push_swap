/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakhalil <nakhalil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 01:17:44 by nakhalil          #+#    #+#             */
/*   Updated: 2025/04/04 15:25:28 by nakhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	int	i;

	i = -1;
	while (++i < stack->size - 1)
		if (stack->data[i] > stack->data[i + 1])
			return (0);
	return (1);
}

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*new_ptr;

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = ft_calloc(1, new_size);
	if (!new_ptr)
		return (NULL);
	if (ptr)
	{
		ft_memcpy(new_ptr, ptr, old_size);
		free(ptr);
	}
	return (new_ptr);
}

void	free_stack(t_stack *stack)
{
	if (stack->data)
		free(stack->data);
	stack->data = NULL;
	stack->size = 0;
}

static void	find_min_max(t_stack *stack, int *min, int *max)
{
	int	i;

	*min = stack->data[0];
	*max = stack->data[0];
	stack->min_pos = 0;
	stack->max_pos = 0;
	i = 1;
	while (i < stack->size)
	{
		if (stack->data[i] < *min)
		{
			*min = stack->data[i];
			stack->min_pos = i;
		}
		if (stack->data[i] > *max)
		{
			*max = stack->data[i];
			stack->max_pos = i;
		}
		i++;
	}
}

void	update_min_max(t_stack *stack)
{
	int	min;
	int	max;

	if (!stack || stack->size <= 0 || !stack->data)
		return ;
	find_min_max(stack, &min, &max);
	stack->min_val = min;
	stack->max_val = max;
}

void	print_stack(t_stack *stack)
{
    for (int i = 0; i < stack->size; i++)
        printf("%d ", stack->data[i]);
    printf("\n");
}
