/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakhalil <nakhalil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 01:14:46 by nakhalil          #+#    #+#             */
/*   Updated: 2025/04/02 15:23:57 by nakhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *a)
{
	update_min_max(a);
	if (a->max_pos == 0)
		ra(a);
	else if (a->max_pos == 1)
		rra(a);
	if (a->data[0] > a->data[1])
		sa(a);
}

void	sort_four_five(t_stack *a, t_stack *b)
{
	int	min_index;
	int	i;

	while (a->size > 3)
	{
		update_min_max(a);
		min_index = a->min_pos;
		if (min_index <= a->size / 2)
		{
			i = 0;
			while (i++ < min_index)
				ra(a);
		}
		else
		{
			i = 0;
			while (i++ < a->size - min_index)
				rra(a);
		}
		pb(a, b);
	}
	sort_three(a);
	while (b->size > 0)
		pa(a, b);
}

void	handle_sorting(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		sa(a);
	else if (a->size == 3)
		sort_three(a);
	else if (a->size <= 5)
		sort_four_five(a, b);
	else
		chunk_sort(a, b);
}
