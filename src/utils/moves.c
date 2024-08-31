/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 14:59:37 by rmei              #+#    #+#             */
/*   Updated: 2024/08/30 18:28:10 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Push the top element of 'stack2' on the top of 'stack1'. */
void	ft_push_top(t_list **stack1, t_list **stack2, char *msg)
{
    t_list  *head1;
    
	if (!*stack2)
        return ;
    head1 = *stack2;
    *stack2 = (*stack2)->next;
	if (!*stack1)
		head1->next = NULL;
	else
		head1->next = *stack1;
    *stack1 = head1;
	if (msg)
		ft_putendl_fd(msg, 1);
}

/* Swap the content of the top two elements of the stack. */
void	ft_swap_top(t_list **stack, char *msg)
{
	t_list	*head;
	void	*head_content;

	if (!(*stack)->next)
		return ;
	head = *stack;
	head_content = head->content;
	head->content = head->next->content;
	head->next->content = head_content;
	if (msg)
		ft_putendl_fd(msg, 1);
}

/* Place the first element at the bottom of the stack. */
void	ft_rotate(t_list **stack, char *msg)
{
	t_list	*head;
	t_list	*tail;

	if (!(*stack)->next)
		return ;
	head = *stack;
	*stack = head->next;
	tail = ft_lstlast(head);
	tail->next = head;
	head->next = NULL;
	if (msg)
		ft_putendl_fd(msg, 1);
}

/* Place the last element at the top of the stack. */
void	ft_rotate_reverse(t_list **stack, char *msg)
{
	t_list	*head;
	t_list	*tail;

	if (!(*stack)->next)
		return ;
	head = *stack;
	tail = ft_lstlast(head);
	while (head->next->next)
		head = head->next;
	head->next = NULL;
	tail->next = *stack;
	*stack = tail;
	if (msg)
		ft_putendl_fd(msg, 1);
}
