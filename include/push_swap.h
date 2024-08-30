/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:40:27 by rmei              #+#    #+#             */
/*   Updated: 2024/08/30 22:42:18 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_content
{
    int index;
    int n;
} t_content;

/* stack.c */

void	ft_stack_make(t_list **stack, char **argv, int argc);

/* sort.c */

void	ft_stack_index(t_list **stack);
void	ft_three_sort(t_list **stack);
void	ft_bin_radix_sort(t_list **stack, t_list **stack_b, int stack_size);

/* push_swap_rotate.c */

void	ft_push_top(t_list **stack1, t_list **stack2, char *msg);
void	ft_swap_top(t_list **stack, char *msg);
void	ft_rotate(t_list **stack, char *msg);
void	ft_rotate_reverse(t_list **stack, char *msg);

#endif
