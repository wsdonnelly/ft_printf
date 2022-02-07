/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 16:16:57 by wdonnell          #+#    #+#             */
/*   Updated: 2022/02/07 15:25:08 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_precision_di(t_pformat *cur, int len, long long n)
{
	//if (n == 0 && cur->dot && !cur->precision)
	if (n == 0 && (cur->flags & DOT) && !cur->precision)//repeted later?
		return ;
	if (cur->precision > len)
		cur->printed_length += write_char('0', cur->precision - len);
	ft_putnbr_s(n);
}

static void	print_field_di(t_pformat *cur, int len, long long n)
{
	int	total_len;
	int	positive;

	positive = 1;
	if (n < 0)
		positive = 0;
	if (cur->precision > len)
		total_len = cur->precision;
	else
		total_len = len;
	if (cur->field_width >= cur->precision)
		//if (cur->space || cur->plus || n < 0)
		if (cur->flags & (SPACE | PLUS) || n < 0)
			total_len++;
	//if (cur->minus) //left
	if (cur->flags & MINUS)
	{
		if (cur->field_width > total_len)
		{
			print_prefix_signed(cur, positive);
			print_precision_di (cur, len, n);
			cur->printed_length += write_char(' ', cur->field_width - total_len);
			return ;
		}
		print_prefix_signed(cur, positive);
		print_precision_di(cur, len, n);
	}
	else //right
	{
		if (cur->field_width > total_len)
		{
			//printf("HERE<<<<<\n");
			//if (cur->zero && !cur->dot)
			if ((cur->flags & ZERO) && !(cur->flags & DOT))
			{
				
				print_prefix_signed(cur, positive);
				cur->printed_length += write_char('0', cur->field_width - total_len);
				print_precision_di(cur, len, n);
				return ;
			}
			cur->printed_length += write_char(' ', cur->field_width - total_len);
			print_prefix_signed(cur, positive);
			print_precision_di(cur, len, n);
			return ;
		}
		print_prefix_signed(cur, positive);
		print_precision_di(cur, len, n);
	}
}

void	print_di(t_pformat *cur, va_list ap)
{
	int	len;
	long long		n;

	//if (cur->hash)
	if (cur->flags & HASH)
		return ;
	//get modifier
	if (cur->length_modifier[0] == 'l')
	{
		if (cur->length_modifier[1] == 'l')
			n = va_arg(ap, long long);
		else
			n = (long long)va_arg(ap, long);
	}
	else if (cur->length_modifier[0] == 'h')
	{
		if (cur->length_modifier[1] == 'h')
			n = (char)va_arg(ap, int);
		else
			n = (short)va_arg(ap, int);
	}
	else
		n = (long long)va_arg(ap, int);
	//get len
	len = ft_num_digits_s(n);
	//if (n == 0 && cur->dot && !cur->precision)
	if (n == 0 && cur->flags & DOT && !cur->precision)
		len--;
	cur->printed_length += len;
	print_field_di(cur, len, n);
}
