/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakhalil <nakhalil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 03:23:33 by nakhalil          #+#    #+#             */
/*   Updated: 2025/04/01 19:15:12 by nakhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	if (b->size > 0)
	{
		a->size++;
		ft_memmove(&a->data[1], &a->data[0], sizeof(int) * (a->size - 1));
		a->data[0] = b->data[0];
		ft_memmove(&b->data[0], &b->data[1], sizeof(int) * (b->size - 1));
		b->size--;
		write(1, "pa\n", 3);
		if (a->data[0] < a->min_val || a->data[0] > a->max_val)
			update_min_max(a);
		if (b->size > 0 && (b->data[0] == b->min_val
				|| b->data[0] == b->max_val))
			update_min_max(b);
	}
}

void	pb(t_stack *a, t_stack *b)
{
	if (a->size > 0)
	{
		b->size++;
		ft_memmove(&b->data[1], &b->data[0], sizeof(int) * (b->size - 1));
		b->data[0] = a->data[0];
		ft_memmove(&a->data[0], &a->data[1], sizeof(int) * (a->size - 1));
		a->size--;
		write(1, "pb\n", 3);
		update_min_max(a);
		update_min_max(b);
	}
}

void	sa(t_stack *a)
{
	int	tmp;

	if (a->size > 1)
	{
		tmp = a->data[0];
		a->data[0] = a->data[1];
		a->data[1] = tmp;
		write(1, "sa\n", 3);
		update_min_max(a);
	}
}

void	ra(t_stack *a)
{
	int	tmp;

	if (a->size > 1)
	{
		tmp = a->data[0];
		ft_memmove(&a->data[0], &a->data[1], sizeof(int) * (a->size - 1));
		a->data[a->size - 1] = tmp;
		write(1, "ra\n", 3);
		update_min_max(a);
	}
}

void	rra(t_stack *a)
{
	int	tmp;

	if (a->size > 1)
	{
		tmp = a->data[a->size - 1];
		ft_memmove(&a->data[1], &a->data[0], sizeof(int) * (a->size - 1));
		a->data[0] = tmp;
		write(1, "rra\n", 4);
		update_min_max(a);
	}
}
