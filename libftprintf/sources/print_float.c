/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:15:47 by wdonnell          #+#    #+#             */
/*   Updated: 2022/02/07 15:23:15 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long double	rounder(long double nb,  int precision)
{
	long double	rounder;
	 int	i;

	rounder = 0.5;
	i = precision;
	while (i-- > 0)
		rounder /= 10;
	if (nb < 0)
		nb -= rounder;
	else
		nb += rounder;
	return (nb);
}

static void print_precision_f(t_pformat *cur, long double n, int first_digi_exp)
{
	double pow;
	double digit;
	int i;
	int num_digi;

	if (n < 0)
		n = -n;
	pow = 1.0;
	i = 0;
	num_digi = 0;
	while (i++ < first_digi_exp)
		pow *= 10.0;
	n /= pow;
	while (num_digi <= cur->precision)
	{
		digit = (int)n;
		ft_putchar('0' + (char)digit);
		n -= digit;
		n *= 10.0;
		if (!first_digi_exp--)
			if (cur->precision || cur->flags & HASH)
				ft_putchar('.');
		if (first_digi_exp < 0)
			num_digi++;
	}
}

static void	print_field_f(t_pformat *cur, int len, int len_int_part, long double n)
{
	int	total_len;
	int	positive;

	positive = 1;
	if (n < 0)
		positive = 0;
	total_len = len;
	if (cur->field_width >= cur->precision)
		if (cur->flags & (SPACE | PLUS) || n < 0)
			total_len++;
	if (cur->flags & MINUS)
	{
		if (cur->field_width > total_len)
		{
			print_prefix_signed(cur, positive);
			print_precision_f(cur, n, len_int_part - 1);
			cur->printed_length += write_char(' ', cur->field_width - total_len);
			return ;
		}
		print_prefix_signed(cur, positive);
		print_precision_f(cur, n, len_int_part - 1);
	}
	else //right
	{
		if (cur->field_width > total_len)
		{
			if ((cur->flags & ZERO))
			{
				
				print_prefix_signed(cur, positive);
				cur->printed_length += write_char('0', cur->field_width - total_len);
				print_precision_f(cur, n, len_int_part - 1);
				return ;
			}
			cur->printed_length += write_char(' ', cur->field_width - total_len);
			print_prefix_signed(cur, positive);
			print_precision_f(cur, n, len_int_part - 1);
			return ;
		}
		print_prefix_signed(cur, positive);
		print_precision_f(cur, n, len_int_part - 1);
	}
}

void print_float(t_pformat *cur, va_list ap)
{
	long double n;
	int len_int_part;
	
	//get_modifier
	if (cur->length_modifier[0] == 'L')
		n = (long double)va_arg(ap, long double);
	else
		n = (long double)va_arg(ap, double);
	if (!(cur->flags & DOT))
		cur->precision = 6;
	n = rounder(n, cur->precision);
	//get printed len
	len_int_part = ft_num_digits_s((long)n);
	if (cur->precision || cur->flags & HASH)
		cur->printed_length = len_int_part + cur->precision + 1;
	else
		cur->printed_length = len_int_part;
	print_field_f (cur, cur->printed_length, len_int_part, n);
}

