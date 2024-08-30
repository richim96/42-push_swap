/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:19:45 by rmei              #+#    #+#             */
/*   Updated: 2024/08/30 23:12:42 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Validate `n` as a non-duplicate integer (of size `int`). */
static int	ft_n_is_valid(int n, char *arg, t_list **stack)
{
	t_list	*node;

	if (ft_numlen(n) != ft_strlen(arg))
		return (FALSE);
	if (n == 0 && *arg != '0')
		return (FALSE);
	if (!*stack)
		return (TRUE);
	node = *stack;
	while (node)
	{
		if (n == ((t_content *)node->content)->n)
			return (FALSE);
		node = node->next;
	}
	return (TRUE);
}

/* Create the content of the list node. */
static t_content	*ft_content_make(int n)
{
	t_content *content;

	content = malloc(sizeof(t_content));
	if (!content)
		return (NULL);
	content->index = -1;
	content->n = n;
	return (content);
}

/* Creata a numerical array for sorting. */
static void	ft_args_to_stack(t_list **stack, char **args, int pos)
{
	int			n;
	t_list		*node;
	t_content	*content;

	while (args[pos])
	{
		n = ft_atoi(args[pos]);
		if (!ft_n_is_valid(n, args[pos], stack))
		{
			ft_lstclear(stack, free);
			return ;
		}
		content = ft_content_make(n);
		node = ft_lstnew(content);
		if (!node)
		{
			free(content);
			ft_lstclear(stack, free);
			ft_error("Malloc failed. No free memory for the stack.\n");
		}
		ft_lstadd_back(stack, node);
		pos++;
	}
}

/* Split the argument into a viable data structure. */
void	ft_stack_make(t_list **stack, char **args, int argc)
{
	int		pos;
	char	**split_args;

	pos = 0;
	if (argc > 2)
		ft_args_to_stack(stack, args, pos);
	else
	{
		split_args = ft_split(*args, ' ');
		ft_args_to_stack(stack, split_args, pos);
		while (split_args[pos])
			free(split_args[pos++]);
		free(split_args);
	}
}
