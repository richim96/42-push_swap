/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:34:42 by rmei              #+#    #+#             */
/*   Updated: 2024/09/04 13:24:34 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/* Read an input stream from the CLI. */
static char	*ft_input_stream_read(void)
{
	char	input[MAX_INPUT];
	char	*input_sequence;
	char	*temp_line;

	input_sequence = ft_calloc(1, 1);
	if (!input_sequence)
		return (NULL);
	ft_memset(input, 0, MAX_INPUT);
	while (read(STDIN_FILENO, input, MAX_INPUT - 1))
	{
		temp_line = input_sequence;
		input_sequence = ft_strjoin(temp_line, input);
		free(temp_line);
		ft_bzero(input, MAX_INPUT);
	}
	return (input_sequence);
}

int	main(int argc, char **argv)
{
	char	*moves;
	t_list	*stack;

	if (argc == 1)
		return (1);
	stack = NULL;
	ft_stack_make(&stack, ++argv, argc);
	if (!stack)
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		return (1);
	}
	moves = ft_input_stream_read();
	ft_sort(moves, &stack);
	free(moves);
	ft_lstclear(&stack, free);
	ft_putendl_fd("OK", STDOUT_FILENO);
	return (0);
}
