/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jsala@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:22:01 by jsala             #+#    #+#             */
/*   Updated: 2024/02/16 15:46:45 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include <stdio.h>

void	test_success(char *str)
{
	printf("\n =======================%s======================\n\n", str);
	printf(" ===================================================== \n");
	printf("|                        Success!                     |\n");
	printf(" ===================================================== \n\n");
}

void	ft_print_int(int *arr, int count)
{
	int i = -1;
	while (++i < count)
	{
		printf("%i\n", arr[i]);
	}
}

void	print_list(t_list *list, int c)
{
	printf("\nBeginning to print the list\n");
	while (list && c > 0)
	{
		printf("Val list: %i; Val of pos: %i; Val of c: %i\n", list->content, list->position, c);
		list = list->next;
		c--;
	}
	printf("\nEnding to print the list\n");
}

void	test_rotate(t_list **stack)
{
	printf("\nStart rotation moves;\n\n");
	ft_rotate(stack);
	print_list(*stack, 10);
	ft_rotate(stack);
	print_list(*stack, 10);
	printf("\nDouble rotation done;\n");
	ft_rotate_rev(stack);
	print_list(*stack, 10);
	ft_rotate_rev(stack);
	print_list(*stack, 10);
	printf("Double reverse rotation done;\n");
	test_success(" Rotate ");
}

void	test_swap(t_list **stack)
{
	printf("Start rotation moves;\n");
	ft_swap(stack);
	print_list(*stack, 10);
	printf("Pointer of stack: %p; stack->next: %p\n", *stack, (*stack)->next);
	ft_swap(stack);
	print_list(*stack, 10);
	printf("Pointer of stack: %p; stack->next: %p\n", *stack, (*stack)->next);
	printf("Double ft_swap done;\n\n");
	ft_swap(stack);
	print_list(*stack, 10);
	printf("Pointer of stack: %p; stack->next: %p\n", *stack, (*stack)->next);
/*	ft_rotate(stack);
	print_list(*stack, 10);
	ft_swap(stack);
	print_list(*stack, 10);*/
	printf("Double ft_swap with rotation done;\n\n");
	test_success("  Swap  ");
}

void	test_push(t_list **stackA, t_list **stackB)
{
	ft_push(stackA, stackB, 'a');
	print_list(*stackA, 10);
	print_list(*stackB, 10);
	write(1, "Ciao\n", 5);
	ft_push(stackB, stackA, 'b');
	print_list(*stackA, 10);
	print_list(*stackB, 10);
	/*printf("This should fail:\n");
	ft_push(stackB, stackA);*/
}

void	test_stack(t_list **stackA, t_list **stackB)
{
/*	test_rotate(&stackA);
	print_list(stackA, 10);
	write(1, "\nBella\n", 6);*/
	test_swap(stackA);
	print_list(*stackA, 10);
/*	test_swap(&stackB);
	print_list(stackB, 10);
	test_push(&stackA, &stackB);
	test_push(&stackA, &stackB);
	test_success("  Push  ");*/
	(void) stackB;
}
