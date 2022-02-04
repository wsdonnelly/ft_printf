/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_csp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 22:04:51 by wdonnell          #+#    #+#             */
/*   Updated: 2022/02/04 13:44:41 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(t_pformat *cur, va_list ap)
{
	unsigned char	c;

	c = (unsigned char)va_arg(ap, int);
	if (cur->flags & HZSP)
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

void	print_percent(t_pformat *cur)
{
	if (cur->flags & SPACE & DOT)
	{
		cur->printed_length += write (1, "%", 1);
		return ;
	}
	if (cur->field_width)
	{
		if (cur->flags & MINUS)
		{
			cur->printed_length += write (1, "%", 1);
			cur->printed_length += write_char(' ', cur->field_width - 1);
			return ;
		}
		cur->printed_length += write_char(' ', cur->field_width - 1);
	}
	cur->printed_length += write (1, "%", 1);
}

void	print_string(t_pformat *cur, va_list ap)
{
	char	*str;
	int		len;

	str = va_arg(ap, char *);
	if (!str)
	{
		cur->printed_length += write(1, "(null)", 6);
		return ;
	}
	if (cur->flags & HZSP)
		return ;
	len = (int)ft_strlen(str);
	if (cur->precision > len)
		cur->precision = len;
	if (cur->flags & MINUS)
	{
		if (cur->flags & DOT)
			cur->printed_length += putstr_len(str, cur->precision);
		else
			cur->printed_length += putstr_len(str, len);
		if (cur->field_width > len)
			cur->printed_length += write_char(' ', cur->field_width - cur->printed_length);
		return ;
	}
	else
	{
		if (cur->flags & DOT && cur->field_width)
		{
			cur->printed_length += write_char(' ', cur->field_width - cur->precision);
			cur->printed_length += putstr_len(str, cur->precision);
			return ;
		}
		else if (cur->flags & DOT)
		{
			cur->printed_length += putstr_len(str, cur->precision);
			return ;
		}
		if (cur->field_width > len)
			cur->printed_length += write_char(' ', cur->field_width - len);
		cur->printed_length += putstr_len(str, len);
	}
}


