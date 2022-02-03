/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_csp_bits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 22:04:51 by wdonnell          #+#    #+#             */
/*   Updated: 2022/02/02 22:21:15 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(t_pformat *cur, va_list ap)
{
	unsigned char	c;

	c = (unsigned char)va_arg(ap, int);
	if (cur->flags & (HZSP | DOT))
	//if (cur->flags & HZSP || cur->flags & DOT)
		return ;
	if (cur->field_width)
	{
		if (cur->flags & MINUS)
		{
			cur->printed_length += write (1, &c, 1);
			cur->printed_length += write_char(' ', cur->field_width - 1);
			return ;
		}
		cur->printed_length += write_char(' ', cur->field_width - 1);
	}
	cur->printed_length += write (1, &c, 1);
}