/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:57:05 by rmei              #+#    #+#             */
/*   Updated: 2024/08/31 12:43:11 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "libft.h"

typedef struct s_content
{
    int index;
    int n;
} t_content;

/* index.c */

void	ft_stack_index(t_list **stack);

/* moves.c */

void	ft_push_top(t_list **stack1, t_list **stack2, char *msg);
void	ft_swap_top(t_list **stack, char *msg);
void	ft_rotate(t_list **stack, char *msg);
void	ft_rotate_reverse(t_list **stack, char *msg);

/* stack.c */

int     ft_stack_is_sorted(t_list *stack);
void	ft_stack_make(t_list **stack, char **args, int argc);

#endif
