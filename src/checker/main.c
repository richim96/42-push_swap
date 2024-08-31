/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:34:42 by rmei              #+#    #+#             */
/*   Updated: 2024/08/31 14:47:19 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_sort_checker(char *moves, t_list **stack)
{
	if (!ft_stack_is_sorted(*stack))
	{
		free(moves);
		ft_lstclear(stack, free);
		ft_putendl_fd("KO", STDERR_FILENO);
		exit(1);
	}	
}

int	main(int argc, char **argv)
{
	char	command[MAX_INPUT];
	char	*moves;
	t_list	*stack;

	if (argc == 1)
		return (1);
	stack = NULL;
	ft_stack_make(&stack, ++argv, argc);
	if (!stack)
		ft_error("Invalid list.");
	moves = "\0";
	ft_memset(command, 0, MAX_INPUT);
	while (read(STDIN_FILENO, command, MAX_INPUT - 1))
	{
		moves = ft_strjoin(moves, command);
		ft_bzero(command, MAX_INPUT);
	}
	if (moves)
	{
		ft_sort_checker(moves, &stack);
		free(moves);
	}
	ft_lstclear(&stack, free);
	ft_putendl_fd("OK", STDOUT_FILENO);
	return (0);
}
