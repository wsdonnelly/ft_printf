/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_csp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:25:17 by wdonnell          #+#    #+#             */
/*   Updated: 2022/01/31 16:19:31 by wdonnell         ###   ########.fr       */
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
	size_t len;

	str = va_arg(ap, char *);
	if (cur->hash || cur->zero || cur->space || cur->plus || !str)
		//undefined
		return ;
	len = ft_strlen(str);
	if (cur->precision > len)
		cur->precision = (unsigned int)len;
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

void print_pointer(t_pformat *cur, va_list ap)
{
	unsigned long long p;
	unsigned int len;

	p = (unsigned long long)va_arg(ap, void *);
	len = num_digits_base(p, 16);
	//possible fix to mimic gcc printf behavior regarding %.p<NULL>
	if (cur->hash || cur->zero || cur->space || cur->plus || cur->dot)
		//undefined
		return ;
	else if (cur->minus && cur->field_width > len)
	{
		cur->printed_length += write(1, "0x", 2);
		cur->printed_length += ft_putnbr_base(p, 16, 1);
		cur->printed_length += write_char(' ', cur->field_width - len - 2);
		return ;
	}
	else if (cur->field_width > len)
	{
		cur->printed_length += write_char(' ', cur->field_width - len - 2);
		cur->printed_length += write(1, "0x", 2);
		cur->printed_length += ft_putnbr_base(p, 16, 1);
		return ;
	}
	cur->printed_length += write(1, "0x", 2);
	cur->printed_length += ft_putnbr_base(p, 16, 1);
}
