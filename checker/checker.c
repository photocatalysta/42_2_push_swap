/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jsala@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 08:38:27 by jsala             #+#    #+#             */
/*   Updated: 2024/02/17 10:58:45 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	make_move(t_list **stack_a, t_list **stack_b, char *line)
{
	if (!ft_strncmp(line, "sa\n", 5))
		ft_swap_check(stack_a);
	else if (!ft_strncmp(line, "sb\n", 5))
		ft_swap_check(stack_b);
	else if (!ft_strncmp(line, "ra\n", 5))
		ft_rotate_check(stack_a);
	else if (!ft_strncmp(line, "rb\n", 5))
		ft_rotate_check(stack_b);
	else if (!ft_strncmp(line, "rr\n", 5))
		ft_rotate_both_check(stack_a, stack_b);
	else if (!ft_strncmp(line, "rrr\n", 5))
		ft_rotate_rev_both_check(stack_a, stack_b);
	else if (!ft_strncmp(line, "rra\n", 5))
		ft_rotate_rev_check(stack_a);
	else if (!ft_strncmp(line, "rrb\n", 5))
		ft_rotate_rev_check(stack_b);
	else if (!ft_strncmp(line, "pa\n", 5))
		ft_push_check(stack_a, stack_b);
	else if (!ft_strncmp(line, "pb\n", 5))
		ft_push_check(stack_a, stack_b);
}

// This doesn't nead the read part before, check if it works without
void	read_stdin(t_list **stack_a, t_list **stack_b)
{
	int		buff_read;
	char	*buff;
	char	*line;

	buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buff)
		return ;
	buff_read = 1;
	while (buff_read > 0)
	{
		buff_read = read(STDIN_FILENO, buff, BUFFER_SIZE);
		while (ft_strchr(buff, '\n'))
		{
			//line = get_next_line(fd);
			make_move(stack_a, stack_b, line);
			free(line);
			line = NULL;
		}
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0); // This is to be double checked
	stack_a = ft_init_list(argc, argv, stack_a, NULL);
	read_stdin(&stack_a, &stack_b);
	if (is_ordered(stack_a) && stack_b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}
