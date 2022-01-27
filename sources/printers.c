/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:25:17 by wdonnell          #+#    #+#             */
/*   Updated: 2022/01/27 17:06:35 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void print_char(t_pformat *cur, va_list ap)
{
	unsigned char c;

	c = (unsigned char)va_arg(ap, int);
	if (cur->hash || cur->zero || cur->space || cur->plus || cur->dot || !c)
		//undefined
		return ;
	if (cur->field_width)
	{
		if (cur->minus)
		{
			cur->printed_length += write (1, &c, 1);
			cur->printed_length += write_char(' ', cur->field_width - 1);
			return ;
		}
		cur->printed_length += write_char(' ', cur->field_width - 1);
	}
	cur->printed_length += write (1, &c, 1);
}

void print_string(t_pformat *cur, va_list ap)
{
	char *str;

	str = va_arg(ap, char *);
	if (cur->hash || cur->zero || cur->space || cur->plus || !str)
		//undefined
		return ;
	if (cur->precision > ft_strlen(str))
		cur->precision = ft_strlen(str);
	if (cur->minus)
	{
		if (cur->dot)
			cur->printed_length += putstr_len(str, cur->precision);
		else
			cur->printed_length += putstr_len(str, ft_strlen(str));
		if (cur->field_width > ft_strlen(str))
			cur->printed_length += write_char(' ', cur->field_width - cur->printed_length);
		return ;
	}
	else
	{
		if (cur->dot && cur->field_width)
		{
			cur->printed_length += write_char(' ', cur->field_width - cur->precision);
			cur->printed_length += putstr_len(str, cur->precision);
			return ;
		}
		else if (cur->dot)
		{
			cur->printed_length += putstr_len(str, cur->precision);
			return ;
		}
		cur->printed_length += write_char(' ', cur->field_width - ft_strlen(str));
		cur->printed_length += putstr_len(str, ft_strlen(str));
		
	}
}
