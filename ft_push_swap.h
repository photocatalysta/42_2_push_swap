/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jsala@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 22:16:31 by jsala             #+#    #+#             */
/*   Updated: 2024/02/14 15:03:57 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"

//ADD FUNCTIONS

void	ft_sort_int(int	**arr, int size);
int		get_arr_pos(int *arr, int size, int val);
t_list	*ft_init_list(int argc, char **argv, t_list *stack);
t_list	*ft_init_args(t_list *stack, char **argv);
t_list	*ft_delone(t_list *stack);
int		ft_chknum(char *str);
void	ft_push_swap(t_list *stackA, t_list *stackB);

void	ft_rotate(t_list **lst);
void	ft_rotate_rev(t_list **stack);
void	ft_rotate_both(t_list **stackA, t_list **stackB);
void	ft_rotate_rev_both(t_list **stackA, t_list **stackB);
void	ft_push(t_list **stackA, t_list **stackB);
void	ft_swap(t_list **stack);

void	ft_sort_int(int	**arr, int size);
int		get_arr_pos(int *arr, int size, int val);

int		ft_lstval(t_list *stack, int val);
int 	is_ordered(t_list *stack);

void	free_exit(t_list *stackA, t_list *stackB, int exit_val);

// Testing functions
void	print_list(t_list *list, int c);
void	test_rotate(t_list **stack);
void	test_swap(t_list **stack);
void	test_stack(t_list *stackA, t_list *stackB);

#endif
