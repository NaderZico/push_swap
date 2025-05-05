/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakhalil <nakhalil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 01:12:49 by nakhalil          #+#    #+#             */
/*   Updated: 2025/04/04 15:33:24 by nakhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "srcs/libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int	*data;
	int	size;
	int	min_pos;
	int	max_pos;
	int	min_val;
	int	max_val;
}		t_stack;

// Error handling
void	error_exit(t_stack *a, t_stack *b, char **args, int args_allocated);

// Parsing
int		parse_input(char **args, t_stack *stack);
char	**split_args(int *argc, char **argv, int *allocated);
void	free_split(char **split);
int		check_duplicates(t_stack *stack);
int		normalize_main(t_stack *stack);
int		ft_atoi_checked(const char *str, int *num);

// Stack operations
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);

// Sorting
void	chunk_sort(t_stack *a, t_stack *b);
void	handle_sorting(t_stack *a, t_stack *b);

// Utils
int		is_sorted(t_stack *stack);
void	free_stack(t_stack *stack);
int		validate_arguments(char **args, t_stack *stack);
void	sort_back(t_stack *a, t_stack *b);
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size);
void	update_min_max(t_stack *stack);

#endif