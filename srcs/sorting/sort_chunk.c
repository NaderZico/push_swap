/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakhalil <nakhalil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 05:09:19 by nakhalil          #+#    #+#             */
/*   Updated: 2025/04/01 19:16:32 by nakhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_chunks(t_stack *a, t_stack *b, int c_start, int c_end)
{
	int	pushed;
	int	mid;

	pushed = 0;
	mid = (c_start + c_end) / 2;
	while (a->size > 0 && pushed < (c_end - c_start))
	{
		if (a->data[0] >= c_start && a->data[0] < c_end)
		{
			pb(a, b);
			pushed++;
			if (b->data[0] < mid && b->size > 1)
				rb(b);
		}
		else
			ra(a);
	}
	update_min_max(a);
}

void	sort_back(t_stack *a, t_stack *b)
{
	while (b->size > 0)
	{
		update_min_max(b);
		while (b->data[0] != b->max_val)
		{
			if (b->max_pos <= b->size / 2)
				rb(b);
			else
				rrb(b);
		}
		pa(a, b);
	}
}

void	chunk_sort(t_stack *a, t_stack *b)
{
	int	chunk_size;
	int	chunk_start;
	int	original_size;

	chunk_start = 0;
	original_size = a->size;
	if (original_size <= 100)
		chunk_size = original_size / 4;
	else if (original_size <= 500)
		chunk_size = original_size / 8;
	else
		chunk_size = original_size / 12;
	while (a->size > 0)
	{
		push_chunks(a, b, chunk_start, chunk_start + chunk_size);
		chunk_start += chunk_size;
		if (original_size - chunk_start < chunk_size)
			chunk_size = original_size - chunk_start;
	}
	sort_back(a, b);
}
