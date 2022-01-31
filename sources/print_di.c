/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 16:16:57 by wdonnell          #+#    #+#             */
/*   Updated: 2022/01/31 14:28:17 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
static void print_prefix_di(t_pformat *cur, int positive)
{
	if (positive)
	{
		if (cur->plus)
		{
			cur->printed_length += write(1, "+", 1);
			return;
		}
		else if (cur->space)
			cur->printed_length += write(1, " ", 1);
	}
	else
		cur->printed_length += write(1, "-", 1);

}

static void print_precision_di(t_pformat *cur, unsigned int len, long long n)
{
	if (cur->precision > len)
		cur->printed_length += write_char('0', cur->precision - len);
	cur->printed_length += ft_putnbrLL(n);
	
	
}

static void	print_field_di(t_pformat *cur, unsigned int len, long long n)
{
	unsigned int total_len;
	int positive;

	positive = 1;
	if (n < 0)
		positive = 0;
	if (cur->precision > len)
		total_len = cur->precision;
	else
		total_len = cur->precision + len;
	printf("precision: %d\n", cur->precision);
	printf("total len: %d\n", total_len);
	if (cur->minus) //left
	{
		if (cur->field_width > total_len)
		{
			print_prefix_di(cur, positive);
			print_precision_di (cur, len, n);
			cur->printed_length += write_char(' ', cur->field_width - total_len);
			return ;
		}
		print_prefix_di(cur, positive);
		print_precision_di(cur, len, n);

	}
	else //right
	{
		printf("cfw: %d\n", cur->field_width );
		if (cur->field_width > total_len)
		{
			if (cur->zero && !cur->dot)
			{
				print_prefix_di(cur, positive);
				cur->printed_length += write_char('0', cur->field_width - total_len);
				print_precision_di(cur, len,  n);
				return ;
			}
			//else if (cur->dot)
			
			cur->printed_length += write_char(' ', cur->field_width - total_len);
			print_prefix_di(cur,  positive);
			print_precision_di(cur, len,  n);
			return ;


			
		}
		print_prefix_di(cur,  positive);
		print_precision_di(cur, len,  n);
	}

}

void print_di(t_pformat *cur, va_list ap)
{
	unsigned int len;
	long long n;
	
	if (cur->hash)
		//undefined
		return ;
	//get modifier
	if (cur->length_modifier[0] == 'l')
	{
		if (cur->length_modifier[1] == 'l')
			n = va_arg(ap, long long);
		else
			n = (long long)va_arg(ap, long);
	}
	else
		n = (long long)va_arg(ap, int);
	//get len
	len = ft_num_digitsLL(n);
	
	if (cur->field_width > cur->precision)
		if (cur->space || cur->plus || n < 0)
			len++;
	print_field_di(cur, len, n);
}
