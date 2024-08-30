/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 15:06:13 by rmei              #+#    #+#             */
/*   Updated: 2024/08/31 01:16:07 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_min_node_get(t_list *stack)
{
	t_list		*min;
	t_content	*content;

	min = NULL;
	while (stack)
	{
		content = stack->content;
		if (content->index == -1)
			if (!min || content->n < ((t_content *)min->content)->n)
				min = stack;
		stack = stack->next;
	}
	return (min);
}

void	ft_stack_index(t_list **stack)
{
	t_list	*min_node;
    int     curr_index;

    curr_index = 0;
    min_node = ft_min_node_get(*stack);
    while (min_node)
    {
		((t_content *)min_node->content)->index = curr_index++;
        min_node = ft_min_node_get(*stack);
    }
}

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
void	ft_bin_radix_sort(t_list **stack, t_list **stack_b, int stack_size)
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

/* Sort a stack of three integers. */
void	ft_three_sort(t_list **stack)
{
	t_content	*first;
	t_content	*second;
	t_content	*third;

	first = (*stack)->content;
	second = (*stack)->next->content;
	third = (*stack)->next->next->content;
	if (first->n > second->n && first->n < third->n)
		ft_swap_top(stack, "sa");
	else if (first->n > second->n && first->n > third->n)
	{
		ft_rotate(stack, "ra");
		if (second->n > third->n)
			ft_swap_top(stack, "sa");
	}
	else if (second->n > third->n)
	{
		ft_rotate_reverse(stack, "rra");
		if (third->n > first->n)
			ft_swap_top(stack, "sa");
	}
}
