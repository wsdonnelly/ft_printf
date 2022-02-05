/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:15:47 by wdonnell          #+#    #+#             */
/*   Updated: 2022/02/05 15:16:55 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include<stdio.h>

void print_float(t_pformat *cur, va_list ap)
{
	int num_digi = 0;
	int first_digi_exp = 0;
	double digit;
	int max_digi = 100;
	double pow;
	int i;
	long double n;
	
	n = (long double)va_arg(ap, double);

	if (!(cur->flags & DOT))
		cur->precision = 6;
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	first_digi_exp = ft_num_digits_s((int)n) - 1;
	pow = 1;
	i = 0;
	while (i++ < first_digi_exp)
		pow *= 10.0;
	n /= pow;
	//while (n > 0.0 && num_digi < max_digi)
	while (num_digi < max_digi)
	{
		digit = (int)n;	
		ft_putchar('0' + (char)digit);
		num_digi++;
		n -= digit;
		n *= 10.0;
		if (!first_digi_exp--)
		{
			ft_putchar('.');
			num_digi = 0;
			max_digi = cur->precision;
		}
	}
}

/*
void print_float(double n, int precision)
{
	int num_digi = 0;
	int first_digi_exp = 0;
	double digit;
	int max_digi = 100;
	int pow;
	int i;

	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	first_digi_exp = ft_num_digits_s((int)n) - 1;
	pow = 1;
	i = 0;
	while (i++ < first_digi_exp)
		pow *= 10;
	n /= pow;
	while (n > 0.0 && num_digi < max_digi)
	{
		digit = (int)n;
		ft_putchar('0' + (char)digit);
		num_digi++;
		n -= digit;
		n *= 10.0;
		if (!first_digi_exp--)
		{
			ft_putchar('.');
			num_digi = 0;
			max_digi = precision;
		}
	}
}
*/
