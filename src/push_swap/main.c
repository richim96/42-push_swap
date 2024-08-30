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
/* **********************************
**************************************** */

#include "push_swap.h"

/* Check if the given stack is sorted. */
static int	ft_is_sorted(t_list *stack)
{
	int	limit;
	int	idx;

	limit = ((t_content *)stack->content)->index;
	stack = stack->next;
	while (stack)
	{
		idx = ((t_content *)stack->content)->index;
		if (idx < limit)
			return (FALSE);
		limit = idx;
		stack = stack->next;
	}
	return (TRUE);
}

/* Sort a numerical array using a second stack as sorting buffer. */
static void	ft_sort(t_list **stack, int min)
{
	t_list	*stack_b;

	stack_b	= NULL;
	if (ft_lstsize(*stack) == 2
		&& ((int *)(*stack)->content)[1] > ((int *)(*stack)->next->content)[1])
		ft_swap_top(stack, "sa");
	else if (ft_lstsize(*stack) <= 20)
	{
		while (ft_lstsize(*stack) > 3)
		{
			if (*(int *)(*stack)->next->content == min)
				ft_rotate(stack, "ra");
			else
				while(*(int *)(*stack)->content != min)
					ft_rotate_reverse(stack, "rra");
			ft_push_top(&stack_b, stack, "pb");
			min++;
		}
		ft_three_sort(stack);
		while (stack_b)
			ft_push_top(stack, &stack_b, "pa");
	}
	else
		ft_bin_radix_sort(stack, &stack_b, ft_lstsize(*stack));
}

int	main(int argc, char **argv)
{
	t_list	*stack;

	stack = NULL;
	if (argc == 1)
		return (1);
	else
		ft_stack_make(&stack, ++argv, argc);
	if (!stack)
	{
		ft_putendl_fd("Error", 2);
		return (1);
	}
	ft_stack_index(&stack);
	if (!ft_is_sorted(stack))
		ft_sort(&stack, 0);
	if (!ft_is_sorted(stack))
		ft_error("The algorithm failed to sort the stack.\n");
	ft_lstclear(&stack, free);
	return (0);
}
