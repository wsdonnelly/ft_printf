/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_csp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 22:04:51 by wdonnell          #+#    #+#             */
/*   Updated: 2022/02/10 11:40:19 by wdonnell         ###   ########.fr       */
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
			cur->length += write (1, &c, 1);
			cur->length += write_char(' ', cur->field_width - 1);
			return ;
		}
		cur->length += write_char(' ', cur->field_width - 1);
	}
	cur->length += write (1, &c, 1);
}

void	print_percent(t_pformat *cur, va_list ap)
{
	ap = NULL;
	if (cur->flags & SPACE & DOT)
	{
		cur->length += write (1, "%", 1);
		return ;
	}
	if (cur->field_width)
	{
		if (cur->flags & MINUS)
		{
			cur->length += write (1, "%", 1);
			cur->length += write_char(' ', cur->field_width - 1);
			return ;
		}
		cur->length += write_char(' ', cur->field_width - 1);
	}
	cur->length += write (1, "%", 1);
}

static void	str_align_left(t_pformat *cur, int len, char *str)
{
	if (cur->flags & DOT)
		cur->length += putstr_len(str, cur->precision);
	else
		cur->length += putstr_len(str, len);
	if (cur->field_width > len)
		cur->length += write_char(' ', cur->field_width - cur->length);
	return ;
}

static void	str_align_right(t_pformat *cur, int len, char *str)
{
	if (cur->flags & DOT && cur->field_width)
	{
		cur->length += write_char(' ', cur->field_width - cur->precision);
		cur->length += putstr_len(str, cur->precision);
		return ;
	}
	else if (cur->flags & DOT)
	{
		cur->length += putstr_len(str, cur->precision);
		return ;
	}
	if (cur->field_width > len)
		cur->length += write_char(' ', cur->field_width - len);
	cur->length += putstr_len(str, len);
}

void	print_str(t_pformat *cur, va_list ap)
{
	char	*str;
	int		len;

	str = va_arg(ap, char *);
	if (!str)
	{
		cur->length += write(1, "(null)", 6);
		return ;
	}
	if (cur->flags & HZSP)
		return ;
	len = (int)ft_strlen(str);
	if (cur->precision > len)
		cur->precision = len;
	if (cur->flags & MINUS)
		str_align_left(cur, len, str);
	else
		str_align_right(cur, len, str);
}

void print_pointer(t_pformat *cur, va_list ap)
{
	unsigned long n;

	if (cur->flags & HZSP)
		return ;
	n = (unsigned long)va_arg(ap, void *);
	cur->length = num_digits_base(n, 16, 0) + 2;
	if (cur->field_width > cur->length)
	{
		if (cur->flags & MINUS)
		{
			write (1, "0x", 2);
			ft_putnbr_base(n, 16, 0);
			cur->length += write_char(' ', cur->field_width - cur->length);
			return ;
		}
		cur->length += write_char(' ', cur->field_width - cur->length);
		write (1, "0x", 2);
		ft_putnbr_base(n, 16, 0);
		return ;
	}
	write (1, "0x", 2);
	ft_putnbr_base(n, 16, 0);
}
