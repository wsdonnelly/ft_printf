/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_diouxX_draft.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:25:11 by wdonnell          #+#    #+#             */
/*   Updated: 2022/01/29 18:47:47 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
void print_ouxX(t_pformat *cur, va_list ap, char c)
{
	unsigned long long n;


	if (cur->space || cur->plus || (cur->hash && c == 'u'))
		//undefined
		return ;
	n = (unsigned long long)va_arg(ap, unsigned int);
	
	//append to nums
	if (cur->hash)
	{
		if (c == 'x')
			cur->printed_length += write(1, "0x", 2);
		if (c == 'X')
			cur->printed_length += write(1, "0X", 2);
		if (c == 'o')
			cur->printed_length += write(1, "0", 1);
	}
	
	if (c == 'o')
		cur->printed_length += ft_putnbr_base(n, 8, 0);
	else if (c == 'u')
		cur->printed_length += ft_putnbr_base(n, 10, 0);
	else if (c == 'x')
		cur->printed_length += ft_putnbr_base(n, 16, 0);
	else if (c == 'X')
		cur->printed_length += ft_putnbr_base(n, 16, 1);

}
*/
void print_octal(t_pformat *cur, va_list ap)
{
	unsigned int n;
	unsigned int len;
	if (cur->space || cur->plus)
		//undefined
		return ;
	n = va_arg(ap, unsigned int);
	len = num_digits_base(n, 8);
	if (cur->hash)
			len++;
	//precision first
	if (cur->precision > len && cur->precision > cur->field_width)
	{
		cur->printed_length += write_char('0', cur->precision - len);
		if (cur->hash)
			cur->printed_length += write(1, "0", 1);
		cur->printed_length += ft_putnbr_base(n, 8, 0);
		return ;
	}
	else if (cur->precision > len && cur->precision < cur->field_width)
	{
		if (!cur->minus)
			cur->printed_length += write_char(' ', cur->field_width - cur->precision);
		cur->printed_length += write_char('0', cur->precision - len);
		if (cur->hash)
			cur->printed_length += write(1, "0", 1);
		cur->printed_length += ft_putnbr_base(n, 8, 0);
		if (cur->minus)
			cur->printed_length += write_char(' ', cur->field_width - cur->precision);
		return ;
	}
	//left align
	if (cur->minus)//override zero
	{
		if (cur->hash)
			cur->printed_length += write(1, "0", 1);
		cur->printed_length += ft_putnbr_base(n, 8, 0);
		if (cur->field_width > len)
			cur->printed_length += write_char(' ', cur->field_width - len);
		return ;
	
	}
	else if (cur->zero && !cur->minus) //same as above make funk
	{
		if (cur->field_width > len)
			cur->printed_length += write_char('0', cur->field_width - len);
		if (cur->hash)
			cur->printed_length += write(1, "0", 1);
		cur->printed_length += ft_putnbr_base(n, 8, 0);
		return ;
	}
	//right align
	if (cur->field_width > len)
		cur->printed_length += write_char(' ', cur->field_width - len);
	if (cur->hash)
			cur->printed_length += write(1, "0", 1);
	cur->printed_length += ft_putnbr_base(n, 8, 0);
}

/*

if (cur->dot && !cur->zero)
{
	if (cur->field_width > precision)
		if (cur->minus)
			print_precision(cur, len, c)
			cur->printed_length += write_char(' ', cur->field_width - len);
		else
			cur->printed_length += write_char(' ', cur->field_width - len);
			print_precision(cur, len, c)
}
else if (!cur->dot && cur->zero)
{
	if (cur->field_width > precision)
		if (cur->minus)
			print_precision(cur, len, c)
			cur->printed_length += write_char('0', cur->field_width - len);
		else
			cur->printed_length += write_char('0', cur->field_width - len);
			print_precision(cur, len, c)
}

*/