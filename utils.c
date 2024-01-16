/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jacopo.sala@student.barcelona.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 22:23:42 by jsala             #+#    #+#             */
/*   Updated: 2024/01/16 22:40:52 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void    ft_print_error(void)
{
    write(2, "Error\n", 6);
}

void    ft_putstr(char *str)
{
    int i;

    if (!str)
        return (NULL);
    i = 0;
    while (str[i])
        write (1, &str[i++], 1);
}

int ft_atoi(char *str)
{
    int val;
    int sign;

    val = 0;
    sign = 1;
    while (*str && *str != '\t' && *str != '\n' && *str != '\r' 
                && *str != ' ' && *str != '\f' && *str != '\v')
        str++;
    if (*str == '+' || *str == '-')
    {
        if (*str == '-')
            sign *= -1;
        str++;
    }
    while (*str)
        val = 10 * val + *str - '0';
    return (val);
}
