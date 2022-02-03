/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_format_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:14:47 by wdonnell          #+#    #+#             */
/*   Updated: 2022/02/03 15:22:27 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void	get_flags(const char *format, t_pformat *cur, int *j)
{
	while (ft_strchr("#0-+ ", (int)format[*j]))
	{
		if (format[*j] == '#')
			cur->hash = 1;
		else if (format[*j] == '0')
			cur->zero = 1;
		else if (format[*j] == '-')
			cur->minus = 1;
		else if (format[*j] == '+')
			cur->plus = 1;
		else if (format[*j] == ' ')
			cur->space = 1;
		(*j)++;
	}
}

static void	get_width(const char *format, t_pformat *cur, int *j, va_list ap)
{
	while (ft_strchr("123456789*", (int)format[*j])) //ADD *
	{
		if (format[*j] == '*')
		{

			cur->field_width = va_arg(ap, int);
			if (cur->field_width < 0)
			{
				cur->minus = 1;
				cur->field_width *= -1;
			}
			(*j)++;
		}
		else
		{
			cur->field_width = ft_atoi(&format[*j]);
			*j += ft_num_digits(cur->field_width);
		}
	}
}

static void	get_precision(const char *format, t_pformat *cur, int *j, va_list ap )
{
	if (format[*j] == '.')
	{
		cur->dot = 1;
		(*j)++;
		if (ft_strchr("0123456789*", (int)format[*j]))//ADD *
		{
			if (format[*j] == '*')
			{
				cur->precision = va_arg(ap, int);
				//A negative precision argument is taken as if the precision were omitted.
				if (cur->field_width < 0)
				{
					cur->precision = 0;
					cur->dot = 0;
				}
				(*j)++;
			}
			else
			{
				cur->precision = ft_atoi(&format[*j]);
				*j += ft_num_digits(cur->precision);
			}
		}
	}
}

static void	get_length_modifier(const char *format, t_pformat *cur, int *j)
{
	int	k;

	k = 0;
	while (ft_strchr("hlL", (int)format[*j]))
	{
		cur->length_modifier[k] = format[*j];
		k++;
		(*j)++;
	}
}

void get_format_data(const char *format, t_pformat *cur, int *j, va_list ap)
{
	get_flags(format, cur, j);
	get_width(format, cur, j, ap);
	get_precision(format, cur, j, ap);
	get_length_modifier(format, cur, j);
}
