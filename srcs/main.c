/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakhalil <nakhalil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 01:15:37 by nakhalil          #+#    #+#             */
/*   Updated: 2025/04/04 15:33:30 by nakhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	initialize_stacks(t_stack *a, t_stack *b)
{
	a->data = NULL;
	a->size = 0;
	b->data = NULL;
	b->size = 0;
}

static int	input_is_empty(int argc, char **argv)
{
	char	*trimmed;

	if (argc != 2)
		return (0);
	trimmed = ft_strtrim(argv[1], " \t\n\r");
	if (!trimmed || trimmed[0] == '\0')
	{
		free(trimmed);
		return (1);
	}
	free(trimmed);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	char	**args;
	int		args_allocated;

	args_allocated = 0;
	initialize_stacks(&a, &b);
	if (argc < 2)
		return (0);
	if (input_is_empty(argc, argv))
		error_exit(&a, &b, NULL, args_allocated);
	args = split_args(&argc, argv, &args_allocated);
	if (!parse_input(args, &a))
		error_exit(&a, &b, args, args_allocated);
	b.data = ft_calloc(a.size, sizeof(int));
	if (!b.data)
		error_exit(&a, &b, args, args_allocated);
	b.size = 0;
	if (!is_sorted(&a))
		handle_sorting(&a, &b);
	if (args_allocated)
		free_split(args);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
