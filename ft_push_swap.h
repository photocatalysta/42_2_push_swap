/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jsala@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 22:16:31 by jsala             #+#    #+#             */
/*   Updated: 2024/02/17 10:46:35 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include "libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 512
# endif

//ADD FUNCTIONS

//Ordinate integers array
int		*ft_sort_int(int *arr, int size);
t_list	*ft_init_pos(t_list *stackA, int *arr, int argc);
t_list	*ft_init_args(t_list *stack, char **argv, int **pos);

int		*ft_sort_int(int *arr, int size);
t_list	*ft_init_args(t_list *stack, char **argv, int **pos);
t_list	*ft_init_list(int argc, char **argv, t_list *stack, int **pos);
void	ft_push_swap(t_list **stackA, t_list **stackB);

t_list	*ft_init_list(int argc, char **argv, t_list *stack, int **pos);
t_list	*ft_delone(t_list *stack);
int		ft_chknum(char *str);
void	ft_push_swap(t_list **stackA, t_list **stackB);

// Functions to recreate the moves of the list
void	ft_rotate(t_list **lst);
void	ft_rotate_rev(t_list **stack);
void	ft_rotate_both(t_list **stackA, t_list **stackB);
void	ft_rotate_rev_both(t_list **stackA, t_list **stackB);
void	ft_push(t_list **stackA, t_list **stackB, char c);
void	ft_swap(t_list **stack);

// Sorting functions
void	ft_fast_sort(t_list **stackA, t_list **stackB);
void	ft_fast_sort_3(t_list **stackA);
//void	ft_stack_sort(t_list **stackA, t_list **stackB); // Used for the Turk algorithm
void	ft_stack_radixsort(t_list **stackA, t_list **stackB);
int		ft_max_pow_3(t_list *stackA);

// Turk related functions
//int		ft_get_move(t_list **stackA, t_list **stackB, int *pos, int *rev);
//int		ft_get_best_cost(int l_stackA, int l_stackB, int *costA, int *costB);
//int		ft_cost_B(t_list *stackB, int val);
//int		ft_calc_abs_cost(t_list *stackA, t_list *stackB, int *costA, int *costB);
//int		get_arr_pos(int *arr, int size, int val);
//void	ft_move(t_list **stackA, t_list **stackB, int *mov_a, int *mov_b);
//void	ft_move_stack(t_list **stack, int *mov, char c);

int		ft_lstval(t_list *stack, int val);
int		is_ordered(t_list *stack);

// Math
int		ft_abs_sum(int a, int b);
int		ft_abs_min(int val, int val_rev);
int		ft_max(int i, int j);
int		ft_min(int i, int j);
int		ft_pow(int n, int pow);

int		ft_lstmin(t_list *stack);
int		ft_lstmax(t_list *stack);

// Exit functions
void	free_exit(t_list **stackA, t_list **stackB, int exit_val);

// Checker functions
void	ft_rotate_both_check(t_list **stackA, t_list **stackB);
void	ft_rotate_rev_both_check(t_list **stackA, t_list **stackB);
void	ft_rotate_check(t_list **stack);
void	ft_rotate_rev_check(t_list **stack);
void	ft_swap_check(t_list **lst);
void	ft_push_check(t_list **stackFrom, t_list **stackTo);

// Testing functions
void	print_list(t_list *list, int c);
void	test_rotate(t_list **stack);
void	test_swap(t_list **stack);
void	test_stack(t_list **stackA, t_list **stackB);
void	ft_print_int(int *arr, int count);

#endif
