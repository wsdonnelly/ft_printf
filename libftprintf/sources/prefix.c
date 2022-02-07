/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prefix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:53:58 by wdonnell          #+#    #+#             */
/*   Updated: 2022/02/07 16:15:55 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_prefix_signed(t_pformat *cur, int positive)
{
	if (positive)
	{
		if (cur->flags & PLUS)
		{
			cur->printed_length += write(1, "+", 1);
			return ;
		}
		else if (cur->flags & SPACE)
			cur->printed_length += write(1, " ", 1);
	}
	else
		cur->printed_length += write(1, "-", 1);
}

void print_prefix_unsigned(t_pformat *cur, char c, int positive)
{
	if (c == 'p')
		c = 'x';
	if (cur->flags & HASH)
	{
		if (!positive)
		{
			if (c == 'o'&& (cur->flags & DOT) && !cur->precision)
				cur->printed_length+= (int)write(1, "0", 1);
			return ;
		}
		cur->printed_length+= (int)write(1, "0", 1);
		if (c == 'x' || c == 'X')
			cur->printed_length+= (int)write(1, &c, 1);
		else if (c == 'b')
			cur->printed_length+= (int)write (1, "b", 1);
	}
}
