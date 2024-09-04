/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 18:25:50 by rmei              #+#    #+#             */
/*   Updated: 2024/09/04 13:15:06 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/* Apply a swap, if possible. */
static void	ft_swap_apply(
	char *move, t_list **stack, t_list **stack_b, int *success)
{
	if (ft_strncmp(move, "sa", 3) == 0)
		ft_swap_top(stack, NULL);
	else if (ft_strncmp(move, "sb", 3) == 0)
		ft_swap_top(stack_b, NULL);
	else if (ft_strncmp(move, "ss", 3) == 0)
	{
		ft_swap_top(stack, NULL);
		ft_swap_top(stack_b, NULL);
	}
	else
		*success = FALSE;
}

/* Apply a rotation, if possible. */
static void	ft_rotate_apply(
	char *move, t_list **stack, t_list **stack_b, int *success)
{
	if (ft_strncmp(move, "ra", 3) == 0)
		ft_rotate(stack, NULL);
	else if (ft_strncmp(move, "rb", 3) == 0)
		ft_rotate(stack_b, NULL);
	else if (ft_strncmp(move, "rr", 3) == 0)
	{
		ft_rotate(stack, NULL);
		ft_rotate(stack_b, NULL);
	}
	else if (ft_strncmp(move, "rra", 4) == 0)
		ft_rotate_reverse(stack, NULL);
	else if (ft_strncmp(move, "rrb", 4) == 0)
		ft_rotate_reverse(stack_b, NULL);
	else if (ft_strncmp(move, "rrr", 4) == 0)
	{
		ft_rotate_reverse(stack, NULL);
		ft_rotate_reverse(stack_b, NULL);
	}
	else
		*success = FALSE;
}

/* Apply the instructions on stack. Return success or failure. */
static int	ft_move(char **moves, t_list **stack, t_list **stack_b)
{
	int		pos;
	int		success;
	char	*move;

	pos = 0;
	success = TRUE;
	while (moves[pos])
	{
		move = ft_strtrim(moves[pos], " \t\v\f\r");
		if (ft_strncmp(move, "s", 1) == 0)
			ft_swap_apply(move, stack, stack_b, &success);
		else if (ft_strncmp(move, "pa", 3) == 0)
			ft_push_top(stack, stack_b, NULL);
		else if (ft_strncmp(move, "pb", 3) == 0)
			ft_push_top(stack_b, stack, NULL);
		else if (ft_strncmp(move, "r", 1) == 0)
			ft_rotate_apply(move, stack, stack_b, &success);
		else if (*move)
			success = FALSE;
		free(move);
		free(moves[pos++]);
	}
	return (success);
}

/* Sort the stack using the input instruction set. Return error on failure. */
void	ft_sort(char *moves, t_list **stack)
{
	int		success;
	char	**split_moves;
	t_list	*stack_b;

	stack_b = NULL;
	split_moves = ft_split(moves, '\n');
	success = ft_move(split_moves, stack, &stack_b);
	free(split_moves);
	if (success && ft_stack_is_sorted(*stack) && stack_b == NULL)
		return ;
	free(moves);
	if (stack)
		ft_lstclear(stack, free);
	if (stack_b)
		ft_lstclear(&stack_b, free);
	ft_putendl_fd("KO", STDERR_FILENO);
	exit(1);
}
