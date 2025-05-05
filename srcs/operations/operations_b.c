/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakhalil <nakhalil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 03:23:30 by nakhalil          #+#    #+#             */
/*   Updated: 2025/03/29 21:27:04 by nakhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_stack *b)
{
	int	tmp;

	if (b->size > 1)
	{
		tmp = b->data[0];
		b->data[0] = b->data[1];
		b->data[1] = tmp;
		write(1, "sb\n", 3);
		update_min_max(b);
	}
}

void	rb(t_stack *b)
{
	int	tmp;

	if (b->size > 1)
	{
		tmp = b->data[0];
		ft_memmove(&b->data[0], &b->data[1], sizeof(int) * (b->size - 1));
		b->data[b->size - 1] = tmp;
		write(1, "rb\n", 3);
		update_min_max(b);
	}
}

void	rrb(t_stack *b)
{
	int	tmp;

	if (b->size > 1)
	{
		tmp = b->data[b->size - 1];
		ft_memmove(&b->data[1], &b->data[0], sizeof(int) * (b->size - 1));
		b->data[0] = tmp;
		write(1, "rrb\n", 4);
		update_min_max(b);
	}
}
