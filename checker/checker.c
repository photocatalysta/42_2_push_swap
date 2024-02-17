/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jsala@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 08:38:27 by jsala             #+#    #+#             */
/*   Updated: 2024/02/17 10:39:37 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	make_move(t_list **stackA, t_list **stackB, char *line)
{
	if (!ft_strncmp(line, "sa\n", 5))
		ft_swap_check(stackA);
	else if (!ft_strncmp(line, "sb\n", 5))
		ft_swap_check(stackB);
	else if (!ft_strncmp(line, "ra\n", 5))
		ft_rotate_check(stackA);
	else if (!ft_strncmp(line, "rb\n", 5))
		ft_rotate_check(stackB);
	else if (!ft_strncmp(line, "rr\n", 5))
		ft_rotate_both_check(stackA, stackB);
	else if (!ft_strncmp(line, "rrr\n", 5))
		ft_rotate_rev_both_check(stackA, stackB);
	else if (!ft_strncmp(line, "rra\n", 5))
		ft_rotate_rev_check(stackA);
	else if (!ft_strncmp(line, "rrb\n", 5))
		ft_rotate_rev_check(stackB);
	else if (!ft_strncmp(line, "pa\n", 5))
		ft_push_check(stackA, stackB);
	else if (!ft_strncmp(line, "pb\n", 5))
		ft_push_check(stackA, stackB);
}

void	read_stdin(t_list **stackA, t_list **stackB)
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
		while(ft_strchr(buff, '\n'))
		{
			//line = get_next_line(fd); // This doesn't nead the read part before, check if it works without
			make_move(stackA, stackB, line);
			free(line);
			line = NULL;
		}
	}
}

int	main(int argc, char **argv)
{
	t_list	*stackA;
	t_list	*stackB;

	stackA = NULL;
	stackB = NULL;
	if (argc < 2)
		return (0); // This is to be double checked
	stackA = ft_init_list(argc, argv, stackA, NULL);
	read_stdin(&stackA, &stackB);
	if (is_ordered(stackA) && stackB == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}
