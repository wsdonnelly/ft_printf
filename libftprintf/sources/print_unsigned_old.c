/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 15:36:58 by wdonnell          #+#    #+#             */
/*   Updated: 2022/02/08 19:26:41 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_precision_u(t_pformat *cur, int len, char c, unsigned long long n)
{
	if (n == 0 && (cur->flags & DOT) && !cur->precision)
		return ;
	if (cur->precision > cur->length)
		cur->length += write_char('0', cur->precision - cur->length);
	if (c == 'b')
		ft_putnbr_base(n, 2, 0);
	else if (c == 'o')
		ft_putnbr_base(n, 8, 0);
	else if (c == 'u')
		ft_putnbr_base(n, 10, 0);
	else if (c == 'x')
		ft_putnbr_base(n, 16, 0);
	else if (c == 'X')
		ft_putnbr_base(n, 16, 1);
}

static void	unsigned_left_algin(t_pformat *cur, char c, int prefix_len, unsigned long long n, int flag)
{
	if (cur->field_width >= cur->precision)
	{
		print_prefix_unsigned(cur, c, flag);
		print_precision_u(cur, c, n);
		if (cur->length > cur->precision)
			write_char(' ', cur->field_width - cur->length - prefix_len);
		else
			write_char(' ', cur->field_width - cur->precision - prefix_len);
		return ;
	}
	print_prefix_unsigned(cur, c, flag);
	print_precision_u(cur, c, n);
}

static void	unsigned_right_align(t_pformat *cur,char c, int prefix_len, unsigned long long n, int flag)
{
	if (cur->field_width >= cur->precision)
	{
		if ((cur->flags & ZERO) && !(cur->flags & DOT))
		{
			print_prefix_unsigned(cur, c, flag);
			write_char('0', cur->field_width - cur->length - prefix_len);
			print_precision_u(cur, c, n);
			return ;
		}
		if (cur->length > cur->precision)
			write_char(' ', cur->field_width - cur->length - prefix_len);
		else
			write_char(' ', cur->field_width - cur->precision - prefix_len);
		print_prefix_unsigned(cur, c, flag);
		print_precision_u(cur, len, c, n);
		return ;
	}
	print_prefix_unsigned(cur, c, flag);
	print_precision_u(cur, c, n);
}

static void	print_field_unsigned(t_pformat *cur, char c, unsigned long long n)
{
	char	flag;
	int prefix_len;

	prefix_len = 0;
	flag = 1;
	if (n == 0)
		flag = 0;
	if ((cur->flags & HASH) && n != 0)
	{
		if (c == 'o' && cur->len > cur->precision)
			prefix_len++;
		else if (c == 'x' || c == 'X' || c == 'b')
			prefix_len += 2;
	}
	if (cur->flags & MINUS)
		unsigned_left_algin(cur, c, prefix_len, n, flag);
	else
		unsigned_right_align(cur, c, prefix_len, n, flag);
}

void	print_unsigned(t_pformat *cur, va_list ap, char c)
{
	unsigned long long	n;

	if ((cur->flags & SPACE & PLUS) || (cur->flags & HASH && c == 'u'))
		return ;
	get_modifier_u(cur, ap, &n);
	if (c == 'o')
		cur->length  = num_digits_base(n, 8, 0);
	else if (c == 'u')
		cur->length  = num_digits_base(n, 10, 0);
	else if (c == 'b')
		cur->length  = num_digits_base(n, 2, 0);
	else
		cur->length  = num_digits_base(n, 16, 0);
	if (n == 0 && cur->flags & DOT && !cur->precision)
		cur->length--;
	print_field_unsigned(cur, c, n);
}
