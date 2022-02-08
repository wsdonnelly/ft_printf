/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prefix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:53:58 by wdonnell          #+#    #+#             */
/*   Updated: 2022/02/08 16:05:58 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_prefix_signed(t_pformat *cur, int positive)
{
	if (positive)
	{
		if (cur->flags & PLUS)
		{
			cur->length += write(1, "+", 1);
			return ;
		}
		else if (cur->flags & SPACE)
			cur->length += write(1, " ", 1);
	}
	else
		cur->length += write(1, "-", 1);
}

void	print_prefix_unsigned(t_pformat *cur, char c, int positive)
{
	if (cur->flags & HASH)
	{
		if (!positive)
		{
			if (c == 'o' && (cur->flags & DOT) && !cur->precision)
				cur->length += write (1, "0", 1);
			return ;
		}
		cur->length += write(1, "0", 1);
		if (c == 'x' || c == 'X')
			cur->length += write(1, &c, 1);
		else if (c == 'b')
			cur->length += write(1, "b", 1);
	}
}
