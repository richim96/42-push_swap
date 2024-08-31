/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 15:06:13 by rmei              #+#    #+#             */
/*   Updated: 2024/08/31 13:51:37 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Count the bits of the biggest number in the stack. */
static int	ft_max_bits_count(t_list *stack)
{
	int			max;
	int			max_bits;
	t_content	*content;

	max = ((t_content *)stack->content)->index;
	max_bits = 0;
	while (stack)
	{
		content = stack->content;
		if (content->index > max)
			max = content->index;
		stack = stack->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

/* Binary radix sort operating in `O(nlogn)` time and `O(1)` space. */
static void	ft_radix_sort(t_list **stack, t_list **stack_b, int stack_size)
{
	int			i;
	int			bits;
	int			max_bits;
	t_content	*content;

	bits = 0;
	max_bits = ft_max_bits_count(*stack);
	while (bits < max_bits)
	{
		i = 0;
		while (i++ < stack_size)
		{
			content = (*stack)->content;
			if ((content->index >> bits) & 1)
				ft_rotate(stack, "ra");
			else
				ft_push_top(stack_b, stack, "pb");
		}
		while (*stack_b)
			ft_push_top(stack, stack_b, "pa");
		bits++;
	}
}

/* Sort a stack of three integers based on their index. */
static void	ft_three_sort(t_list **stack)
{
	int	first;
	int	second;
	int	third;

	first = *(int *)(*stack)->content;
	second = *(int *)(*stack)->next->content;
	third = *(int *)(*stack)->next->next->content;
	if (first > second && first < third)
		ft_swap_top(stack, "sa");
	else if (first > second && first > third)
	{
		ft_rotate(stack, "ra");
		if (second > third)
			ft_swap_top(stack, "sa");
	}
	else if (second > third)
	{
		ft_rotate_reverse(stack, "rra");
		if (third > first)
			ft_swap_top(stack, "sa");
	}
}

/* Sort a stack with a `rotate-to-minimum` approach. */
static void	ft_naive_sort(t_list **stack, t_list **stack_b, int min_index)
{
	while (ft_lstsize(*stack) > 3)
	{
		if (*(int *)(*stack)->next->content == min_index)
			ft_rotate(stack, "ra");
		else
			while(*(int *)(*stack)->content != min_index)
				ft_rotate_reverse(stack, "rra");
		ft_push_top(stack_b, stack, "pb");
		min_index++;
	}
	ft_three_sort(stack);
	while (*stack_b)
		ft_push_top(stack, stack_b, "pa");
}

/* Sort a numerical array using a second stack as sorting buffer. */
void	ft_sort(t_list **stack, int len, int min_index)
{
	t_list	*stack_b;

	stack_b	= NULL;
	ft_stack_index(stack);
	if (len == 2)
		ft_swap_top(stack, "sa");
	else if (len <= 20)
		ft_naive_sort(stack, &stack_b, min_index);
	else
		ft_radix_sort(stack, &stack_b, len);
	if (!ft_stack_is_sorted(*stack))
	{
		ft_lstclear(stack, free);
		ft_error("Sorting failed. The stack is not ready.");
	}
}
