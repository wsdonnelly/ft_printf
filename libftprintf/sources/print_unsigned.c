/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 15:36:58 by wdonnell          #+#    #+#             */
/*   Updated: 2022/02/08 13:11:59 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
static void print_precision_ouxX(t_pformat *cur, int len, char c, unsigned long long n) 
{
	if (n == 0 && (cur->flags & DOT) && !cur->precision)
		return;
	if (cur->precision > len)
		cur->length += write_char('0', cur->precision - len);
	if (c == 'b')
		ft_putnbr_base(n, 2, 0);
	else if (c == 'o')
		ft_putnbr_base(n, 8, 0);
	else if (c == 'u')
		 ft_putnbr_base(n, 10, 0);
	else if (c == 'x' || c == 'p')
		ft_putnbr_base(n, 16, 0);
	else if (c == 'X')
		ft_putnbr_base(n, 16, 1);
}

static void unsigned_left_algin(t_pformat *cur, int len, int total_len, char c, unsigned long long n, int flag)
{
	if (cur->field_width > total_len)
	{
		print_prefix_unsigned(cur, c, flag);
		print_precision_ouxX (cur, len, c, n);
		cur->length += write_char(' ', cur->field_width - total_len);
		return ;
	}
	print_prefix_unsigned(cur, c, flag);
	print_precision_ouxX (cur, len, c, n);
}

static void unsigned_right_align(t_pformat *cur, int len, int total_len, char c, unsigned long long n, int flag)
{
	if (cur->field_width > total_len)
	{
		if ((cur->flags & ZERO) && !(cur->flags & DOT))
		{
			print_prefix_unsigned(cur, c, flag);
			cur->length += write_char('0', cur->field_width - total_len);
			print_precision_ouxX (cur, len, c, n);
			return ;
		}
		cur->length += write_char(' ', cur->field_width - total_len);
		print_prefix_unsigned(cur, c, flag);
		print_precision_ouxX (cur, len, c, n);
		return ;
	}
	print_prefix_unsigned(cur, c, flag);
	print_precision_ouxX (cur, len, c, n);
}

static void	print_field_unsigned(t_pformat *cur, int len, char c, unsigned long long n)
{
	int total_len = 0;
	char flag;

	flag = 1;
	if (n == 0)
		flag = 0;
	
	if ((cur->flags & HASH) && n != 0)
	{
		if (c == 'o')
		{
			len++;
			total_len++;
		}
		else if (c == 'x' || c == 'X' || c == 'b' || c == 'p')
			total_len += 2;
	}
	if (cur->precision > len)
		total_len = cur->precision;
	else 
		total_len = len;
	if (cur->flags & MINUS)
		unsigned_left_algin(cur, len , total_len, c, n, flag);
	else
		unsigned_right_align(cur, len, total_len, c, n, flag);
}


static int get_len_unsigned(t_pformat *cur, unsigned long long n, char c)
{
	int len;

	if (c == 'o')
		len = num_digits_base(n, 8, 0);
	else if (c == 'u')
		len = num_digits_base(n, 10, 0);
	else if (c == 'b')
		len = num_digits_base(n, 2, 0);
	else 
		len = num_digits_base(n, 16, 0);
	if (n == 0 && cur->flags & DOT && !cur->precision)
		len--; 
	cur->length += len;
	return (len);
}

void print_unsigned(t_pformat *cur, va_list ap, char c)
{
	unsigned long long n;
	int len;

	if ((cur->flags & SPACE & PLUS) || (cur->flags & HASH && c == 'u'))
		return ;
	if (cur->length_modifier[0] == 'l' || c == 'p')
	{
		if (cur->length_modifier[1] == 'l')
			n = va_arg(ap, unsigned long long);
		else
			n = (unsigned long long)va_arg(ap, unsigned long);
	}
	else if (cur->length_modifier[0] == 'h')
	{
		if (cur->length_modifier[1] == 'h')
			n = (unsigned char)va_arg(ap, unsigned int);
		else
			n = (unsigned short)va_arg(ap, unsigned int);
	}
	else
		n = (unsigned long long)va_arg(ap, unsigned int);
	len = get_len_unsigned(cur, n, c);
	print_field_unsigned(cur, len, c, n);
}


