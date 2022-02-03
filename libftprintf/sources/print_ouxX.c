/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ouxX.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 15:36:58 by wdonnell          #+#    #+#             */
/*   Updated: 2022/02/03 15:07:52 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void print_prefix_ouxX(t_pformat *cur, char c, char flag)
{
	

	if (cur->hash)
	{
		if (c == 'p')
			c = 'x';
		//cur->printed_length += write(1, "0", 1);
		if ((c == 'x' || c == 'X' || c == 'b') && !flag)
			return ;
		if (c == 'o' && !flag)
			cur->printed_length++;
		write(1, "0", 1);
		if (c == 'x' || c == 'X')
			write(1, &c, 1);
		else if (c == 'b')
			write (1, "b", 1);
	}
}

static void print_precision_ouxX(t_pformat *cur, int len, char c, unsigned long long n) //ouxX
{
	if (n == 0 && cur->dot && !cur->precision)
	{
		//cur->printed_length--;
		return;
	}
	if (cur->precision > len)
		cur->printed_length += write_char('0', cur->precision - len);
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

static void	print_field_ouxX(t_pformat *cur, int len, char c, unsigned long long n)
{
	int total_len;
	char flag;

	flag = 1;
	if (n == 0)
		flag = 0;
	if (cur->precision > len)
		total_len = cur->precision;
	else 
		total_len = len;
	
	printf("\ntotal len: %d\n", total_len);
	//cur->printed_length += len;

	if (cur->minus) //left
	{
		if (cur->field_width > total_len)
		{
		
			print_prefix_ouxX(cur, c, flag);
			print_precision_ouxX (cur, len, c, n);
			cur->printed_length += write_char(' ', cur->field_width - total_len);
			return ;
		}
		
		print_prefix_ouxX(cur, c, flag);;
		print_precision_ouxX (cur, len, c, n);

	}
	else //right
	{
		if (cur->field_width > total_len)
		{
			if (cur->zero && !cur->dot)
			{
				print_prefix_ouxX(cur, c, flag);
				cur->printed_length += write_char('0', cur->field_width - total_len);
				print_precision_ouxX (cur, len, c, n);
				return ;
			}
			//else if (cur->dot)
			
			cur->printed_length += write_char(' ', cur->field_width - total_len);
			print_prefix_ouxX(cur, c, flag);
			print_precision_ouxX (cur, len, c, n);
			return ;
		}
		print_prefix_ouxX(cur, c, flag);
		print_precision_ouxX (cur, len, c, n);
	}

}

void print_ouxX(t_pformat *cur, va_list ap, char c)
{
	unsigned long long n;
	int len;

	if (cur->space || cur->plus || (cur->hash && c == 'u'))
		return ;
	//get modifier
	if (cur->length_modifier[0] == 'l' || c == 'p')
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
		len = num_digits_base(n, 8, 0);
	else if (c == 'u')
		len = num_digits_base(n, 10, 0);
	else if (c == 'b')
		len = num_digits_base(n, 2, 0);
	else 
		len = num_digits_base(n, 16, 0);
	
	if ((cur->field_width >= cur->precision) && cur->hash && n != 0)
	{
		if (c == 'o')
			len++;
		else if (c == 'x' || c == 'X' || c == 'b' || c == 'p')
			len += 2;
	}
	
	if ((c == 'x' || c == 'X' || c == 'o' || c == 'b' || c == 'p') && n == 0 && cur->dot && !cur->precision)
		len--; //print nothing
	
	cur->printed_length += len;
	//printf("\nlen iz: %d\n", len);
	print_field_ouxX(cur, len, c, n);
}
