/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 11:51:51 by wdonnell          #+#    #+#             */
/*   Updated: 2022/01/31 15:19:24 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void init_pformat(t_pformat *cur)
{
	cur->hash = 0;
	cur->zero = 0;
	cur->minus = 0;
	cur->plus = 0;
	cur->space = 0;
	cur->field_width = 0;
	cur->dot = 0;
	cur->precision = 0;
	ft_bzero(&cur->length_modifier, sizeof(char) * 3);
	cur->printed_length = 0;
}

static int find_format(va_list ap, const char *format, t_pformat *cur)
//static int find_format(const char *format, t_pformat *cur)
{
	int j;
	int k;
	//init cur
	init_pformat(cur);
	//loop through string and fill struct w/ data
	j = 0;
	if (format[j] == '%')
	{
		cur->printed_length = (unsigned int)write(1, "%", 1);
		return (++j);
	}
	while (ft_strchr("#0-+ ", (int)format[j]))
	{
		//set flags
		if (format[j] == '#')
			cur->hash = 1;
		else if (format[j] == '0')
			cur->zero = 1;
		else if (format[j] == '-')
			cur->minus = 1;
		else if (format[j] == '+')
			cur->plus = 1;
		else if (format[j] == ' ')
			cur->space = 1;
		j++;
	}
	while (ft_strchr("123456789", (int)format[j]))
	{
		//set width
		cur->field_width = (unsigned int)ft_atoi(&format[j]);
		//increment
		j += ft_num_digits((int)cur->field_width);
	}
	if (format[j] == '.')
	{
		//set dot
		cur->dot = 1;
		j++;
		if (ft_strchr("123456789", (int)format[j]))
		{
			//set precision
			cur->precision = (unsigned int)ft_atoi(&format[j]);
			//increment
			j += ft_num_digits((int)cur->precision);
		}
		//precision stays 0
	}
	k = 0;
	while (ft_strchr("hlL", (int)format[j]))
	{
		//set length modifier
		cur->length_modifier[k] = format[j];
		//increment
		k++;
		j++;
	}
	if (ft_strchr("cspdiouxXf", (int)format[j]))
	{
		//set conversion
		//cur->conversion = format[j];//skip this

		get_conversion(format[j], cur, ap);

		//increment
		//j++;
		//go to next section of program
		//typedef next_part(t_pformat *cur, va_list ap);
		//dispatch[](t_pformat *cur, va_list ap);
		return (++j);
	}
	//error
	return (j);

}
/*
static void struct_tester(t_pformat *cur)
{
	printf("hash: %d\n",cur->hash);
	printf("zero: %d\n",cur->zero);
	printf("minus: %d\n",cur->minus);
	printf("plus: %d\n",cur->plus);
	printf("space: %d\n",cur->space);
	printf("field_width(int): %d\n",cur->field_width);
	printf("dot: %d\n",cur->dot);
	printf("precision(int): %d\n",cur->precision);
	printf("length_modifier(str): %s\n",cur->length_modifier);
	
	printf("printed_length(int): %d\n",cur->printed_length);
}
*/
int ft_printf(const char *format, ...)
{
	va_list ap;
	int i;
	int total;
	t_pformat cur;

	if (!format)
		//error
		return (0);
	va_start(ap, format);
	total = 0;
	i = 0;
	while(format[i])
	{
		if (format[i] == '%')
		{
			//start printing format
			i += find_format(ap, &format[i + 1], &cur) + 1;
			//i += find_format(&format[i + 1], &cur) + 1;
			//add to total printed
			total += cur.printed_length;
			
		}
		else
		{
			total += write(1, &format[i], 1);
			i++;
		}
	}
	va_end(ap);
	//struct_tester(&cur);
	return (total);
}
