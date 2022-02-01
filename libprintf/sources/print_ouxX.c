/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ouxX.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 15:36:58 by wdonnell          #+#    #+#             */
/*   Updated: 2022/01/31 13:30:31 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void print_prefix_ouxX(t_pformat *cur, char c)
{
	if (cur->hash)
	{
		cur->printed_length += write(1, "0", 1);
		if (c == 'x' || c == 'X')
			cur->printed_length += write(1, &c, 1);
	}
}

static void print_precision_ouxX(t_pformat *cur, unsigned int len, char c, unsigned long long n) //ouxX
{
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

static void	print_field_ouxX(t_pformat *cur, unsigned int len, char c, unsigned long long n)
{
	unsigned int total_len;

	total_len = len + cur->precision;
	if (cur->minus) //left
	{
		if (cur->field_width > total_len)
		{
			print_prefix_ouxX(cur, c);
			print_precision_ouxX (cur, len, c, n);
			cur->printed_length += write_char(' ', cur->field_width - total_len);
			return ;
		}
		print_prefix_ouxX(cur, c);
		print_precision_ouxX (cur, len, c, n);

	}
	else //right
	{
		if (cur->field_width > total_len)
		{
			if (cur->zero && !cur->dot)
			{
				print_prefix_ouxX(cur, c);
				cur->printed_length += write_char('0', cur->field_width - total_len);
				print_precision_ouxX (cur, len, c, n);
				return ;
			}
			else if (cur->dot)
			{
				cur->printed_length += write_char(' ', cur->field_width - total_len);
				print_prefix_ouxX(cur, c);
				print_precision_ouxX (cur, len, c, n);
				return ;
			}
			
		}
		print_prefix_ouxX(cur, c);
		print_precision_ouxX (cur, len, c, n);
	}

}

void print_ouxX(t_pformat *cur, va_list ap, char c)
{
	unsigned long long n;
	unsigned int len;

	if (cur->space || cur->plus || (cur->hash && c == 'u'))
		return ;
	//get modifier
	if (cur->length_modifier[0] == 'l')
	{
		if (cur->length_modifier[1] == 'l')
			n = va_arg(ap, unsigned long long);
		else
			n = (unsigned long long)va_arg(ap, unsigned long);
	}
	else
		n = (unsigned long long)va_arg(ap, unsigned int);
	//get len
	if (c == 'o')
		len = num_digits_base(n, 8);
	else if (c == 'u')
		len = num_digits_base(n, 10);
	else 
		len = num_digits_base(n, 16);
	if (cur->field_width > cur->precision)
	{
		if ((c == 'o' || c == 'u') && cur->hash)
			len++;
		else if ((c == 'x' || c == 'X') && cur->hash)
			len += 2;
	}
	print_field_ouxX(cur, len, c, n);
}
