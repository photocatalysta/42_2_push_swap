/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jsala@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 08:38:27 by jsala             #+#    #+#             */
/*   Updated: 2024/02/17 08:38:27 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void    make_move(t_list **stackA, t_list **stackB, char *line)
{
	if (line == "sa\n")
		ft_swap(stackA);
	else if (line == "sb\n")
		ft_swap(stackB);
	else if (line == "ra\n")
		ft_rotate(stackA);
	else if (line == "rb\n")
		ft_rotate(stackB);
	else if (line == "rr\n")
		ft_rotate_both(stackA, stackB);
	else if (line == "rrr\n")
		ft_rotate_rev_both(stackA, stackB);
	else if (line == "rra\n")
		ft_rotate_rev(stackA);
	else if (line == "rrb\n")
		ft_rotate_rev(stackB);
	else if (line == "pa\n")
		ft_push(stackA, stackB, 'a');
	else if (line == "pb\n")
		ft_push(stackA, stackB, 'b');
	/// Silence moves!
}

void    read_stdin(int fd)
{
	int     buff_read;
	char    *buff;
	char    *line;
	
	buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buff)
		return (1);
	buff_read = 1;
	while (buff_read > 0)
	{
		buff_read = read(STDIN_FILENO, buff, BUFFER_SIZE);
		while(ft_strchr(buff, '\n'))
		{
			line = get_next_line(); // This doesn't nead the read part before, check if it works without
			make_move(line);
			free(line);
			line = NULL;
		}
	}
}

int main(int argc, char **argv)
{
	int     fd;
	char    *buff;
	t_list	*stackA;
	t_list	*stackB;

	if (argc < 2)
	{
		Something??
	}
	fd = open(STDIN_FILENO, O_RDONLY);
	if (fd == -1)
		return (1);
	stackA = ft_init_list(argc, argv, stackA);
	read_stdin();
	if (is_ordered(stackA) && stackB == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	close(fd);
	return (0);
}