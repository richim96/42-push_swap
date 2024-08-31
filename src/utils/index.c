/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 12:42:09 by rmei              #+#    #+#             */
/*   Updated: 2024/08/31 12:44:03 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Get the smallest value not yet indexed. */
static t_list	*ft_min_node_get(t_list *stack)
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

/* Index the given stack. */
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
