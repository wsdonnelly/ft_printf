/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_e.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 09:38:16 by wdonnell          #+#    #+#             */
/*   Updated: 2022/02/13 13:03:30 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>


static void	print_precision_e(t_pformat *cur, long double n, int first_digi_exp)
{
	double	pow;
	double	digit;
	//int		i;
	int		num_digi;

	if (n < 0)
		n = -n;
	pow = 1.0;
//	i = 0;
	num_digi = 0;
//	while (i++ < first_digi_exp)
//		pow *= 10.0;
//	n /= pow;

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

static void	e_left_align(t_pformat *cur, long double n, int len_int_part, int total_len)
{
	int	positive;

	positive = 1;
	if (n < 0)
		positive = 0;
	if (cur->field_width > total_len)
	{
		print_prefix_signed(cur, positive);
		print_precision_e(cur, n, len_int_part - 1);
		cur->length += write_char(' ', cur->field_width - total_len);
		return ;
	}
	print_prefix_signed(cur, positive);
	print_precision_e(cur, n, len_int_part - 1);
}

static void	e_right_align(t_pformat *cur, long double n,  int total_len)
{
	int	positive;

	positive = 1;
	if (n < 0)
		positive = 0;
	if (cur->field_width > total_len)
	{
		if ((cur->flags & ZERO))
		{
			print_prefix_signed(cur, positive);
			cur->length += write_char('0', cur->field_width - total_len);
			print_precision_e(cur, n, 0);
			return ;
		}
		cur->length += write_char(' ', cur->field_width - total_len);
		print_prefix_signed(cur, positive);
		print_precision_e(cur, n, 0);
		return ;
	}
	print_prefix_signed(cur, positive);
	print_precision_e(cur, n,0);
}



void print_e(t_pformat *cur, va_list ap)
{
	long double	n;
	int			len_int_part;
	int			total_len;
	int i = 0;
	double pow = 1.0;
	int exp;

	if (cur->length_modifier[0] == 'L')
		n = (long double)va_arg(ap, long double);
	else
		n = (long double)va_arg(ap, double);
	if (!(cur->flags & DOT))
		cur->precision = 6;
	//convert first
	
	len_int_part = ft_num_digits_s((long)n);
	
	if ((long)n > 0)
	{
		while (i++ < len_int_part - 1)
			pow *= 10;
		n /= pow;
		exp = i - 1;
	}
	else
	{

		pow = 10.0;
		i = 0;
		while (!(long)n)
		{
			n *= pow;
			i++;
		}
		exp = -i;
		
	}
	//printf("i = %d\n", i);
	//printf("pow = %f\n", pow);
	//if (cur->precision > 0)
	//	n = round_double(n, cur->precision - 1);
	//else
	n = round_double(n, cur->precision);
	
	//printf("n : %Lf\n", n);


	total_len = len_int_part + 1 + cur->precision + 1 + 1 + 2;
	
	
		if (cur->flags & MINUS)
			e_left_align(cur, n, len_int_part, total_len);
		else
			e_right_align(cur, n, total_len);


	/*
	cur->length = cur->precision + 1;
	if (cur->precision || cur->flags & HASH)
		cur->length++;
	total_len = cur->length;
	if (cur->field_width >= cur->precision)
		if (cur->flags & (SPACE | PLUS) || n < 0)
			total_len++;
	
	if (cur->flags & MINUS)
		float_left_align(cur, n);
	else
		float_right_align(cur, n);
	*/
	
}
