/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ouxX.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 15:36:58 by wdonnell          #+#    #+#             */
/*   Updated: 2022/01/30 15:17:09 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
static void print_prefix(t_pformat *cur, char c)
{
	cur->printed_length += write(1, "0", 1);
	if (c == 'x' || c == 'X')
		cur->printed_length += write(1, &c, 1);
}

static void print_precision(t_pformat *cur, unsigned int len, char c, unsigned long long n) //ouxX
{
	/*
	if (cur->hash)
	{
		cur->printed_length += write(1, "0", 1);
		if (c == 'x' || c == 'X')
			cur->printed_length += write(1, &c, 1);
	}
	*/
	if (cur->precision > len)
		cur->printed_length += write_char('0', cur->precision - len);
	if (c == 'o')
		cur->printed_length += ft_putnbr_base(n, 8, 0);
	else if (c == 'u')
		cur->printed_length += ft_putnbr_base(n, 10, 0);
	else if (c == 'x')
		cur->printed_length += ft_putnbr_base(n, 16, 0);
	else if (c == 'X')
		cur->printed_length += ft_putnbr_base(n, 16, 1);
	
}

static void print_field(t_pformat *cur, unsigned int len, char c, unsigned long long n)
{
	if (cur->dot && !cur->zero)
	{
		if (cur->field_width > cur->precision)
		{
			if (cur->minus)
			{
				if (cur->hash)
					print_prefix(cur, c);
				print_precision(cur, len, c, n);
				cur->printed_length += write_char(' ', cur->field_width - cur->precision);
			}
			else
			{
				if (cur->hash)
					print_prefix(cur, c);
				cur->printed_length += write_char(' ', cur->field_width - cur->precision);
				print_precision(cur, len, c, n);
			}
		}
		else
		{
			if (cur->hash)
					print_prefix(cur, c);
			print_precision(cur, len, c, n);
		}

	}
	else if (!cur->dot && cur->zero)
	{
		if (cur->field_width > cur->precision)
		{
			if (cur->minus)//left minus overrides zero
			{
				if (cur->hash)
					print_prefix(cur, c);
				print_precision(cur, len, c, n);
				cur->printed_length += write_char(' ', cur->field_width - cur->precision);
			}
			else //zero padded
			{
				if (cur->hash)
					print_prefix(cur, c);
				cur->printed_length += write_char('0', cur->field_width - cur->precision);
				print_precision(cur, len, c, n);
			}
		}
	}
	else if (cur->dot && cur->zero)
	{
		if (cur->field_width > cur->precision)
		{
			if (cur->minus)//left minus overrides zero
			{
				if (cur->hash)
					print_prefix(cur, c);
				print_precision(cur, len, c, n);
				cur->printed_length += write_char(' ', cur->field_width - cur->precision);
			}
			else //zero padded
			{
				cur->printed_length += write_char(' ', cur->field_width - cur->precision);
				if (cur->hash)
					print_prefix(cur, c);
				print_precision(cur, len, c, n);
			}
		}
		else
		{
			if (cur->hash)
				print_prefix(cur, c);
			print_precision(cur, len, c, n);
		}
	}
	else
	{
		if (cur->field_width > cur->precision)
		{
			if (cur->minus)//left minus overrides zero
			{
				if (cur->hash)
					print_prefix(cur, c);
				print_precision(cur, len, c, n);
				cur->printed_length += write_char(' ', cur->field_width - cur->precision);
			}
			else //zero padded
			{
				cur->printed_length += write_char(' ', cur->field_width - cur->precision);
				if (cur->hash)
					print_prefix(cur, c);
				print_precision(cur, len, c, n);
			}
		}
		else
		{
			if (cur->hash)
				print_prefix(cur, c);
			print_precision(cur, len, c, n);
		}
	}	
	
}

void print_ouxX(t_pformat *cur, va_list ap, char c)
{
	unsigned long long n;
	unsigned int len;

	if (cur->space || cur->plus || (cur->hash && c == 'u'))
		//undefined
		return ;
	
	if (cur->length_modifier[0] == 'l')
	{
		if (cur->length_modifier[1] == 'l')
			n = va_arg(ap, unsigned long long);
		else
			n = (unsigned long long)va_arg(ap, unsigned long);
	}
	else
		n = (unsigned long long)va_arg(ap, unsigned int);
	if (c == 'o')
		len = num_digits_base(n, 8);
	else if (c == 'u')
		len = num_digits_base(n, 10);
	else 
		len = num_digits_base(n, 16);
	if ((c == 'o' || c == 'u') && cur->hash)
		len++;
	else if ((c == 'x' || c == 'X') && cur->hash)
		len += 2;
	if (cur->precision <= len)
		cur->precision = len;
	print_field(cur, len, c, n);

		

}