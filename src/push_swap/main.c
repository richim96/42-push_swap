/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:44:16 by rmei              #+#    #+#             */
/*   Updated: 2024/08/23 13:19:33 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
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
	if (!ft_stack_is_sorted(stack))
		ft_sort(&stack, ft_lstsize(stack), 0);
	ft_lstclear(&stack, free);
	return (0);
}
