/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cspOLD.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:25:17 by wdonnell          #+#    #+#             */
/*   Updated: 2022/02/03 16:08:29 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(t_pformat *cur, va_list ap)
{
	unsigned char	c;

	c = (unsigned char)va_arg(ap, int);
	if (cur->hash || cur->zero || cur->space || cur->plus || cur->dot)
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

void	print_string(t_pformat *cur, va_list ap)
{
	char	*str;
	int	len;

	str = va_arg(ap, char *);
	if (!str)
	{
		cur->printed_length += write(1, "(null)", 6);
		return ;
	}
	if (cur->hash || cur->zero || cur->space || cur->plus)
		return ;
	len = (int)ft_strlen(str);
	if (cur->precision > len)
		cur->precision = len;
	if (cur->minus)
	{
		if (cur->dot)
			cur->printed_length += putstr_len(str, cur->precision);
		else
			cur->printed_length += putstr_len(str, len);
		if (cur->field_width > len)
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
		if (cur->field_width > len)
			cur->printed_length += write_char(' ', cur->field_width - len);
		cur->printed_length += putstr_len(str, len);
	}
}

void	print_percent(t_pformat *cur)
{
	if (cur->space || cur->dot)
	{
		cur->printed_length += write (1, "%", 1);
		return ;
	}
	if (cur->field_width)
	{
		if (cur->minus)
		{
			cur->printed_length += write (1, "%", 1);
			cur->printed_length += write_char(' ', cur->field_width - 1);
			return ;
		}
		cur->printed_length += write_char(' ', cur->field_width - 1);
	}
	cur->printed_length += write (1, "%", 1);
}
