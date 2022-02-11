/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_format_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 21:57:31 by wdonnell          #+#    #+#             */
/*   Updated: 2022/02/11 12:33:57 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void get_alt_flags(const char *format, int *j, va_list ap)
{
	if (ft_strchr("@", (int)format[*j]))
		ft_putstr((char*)va_arg(ap, char *));
}

static void	get_flags(const char *format, t_pformat *cur, int *j)
{
	while (ft_strchr("@#0-+ ", (int)format[*j]))
	{
		if (format[*j] == '#')
			cur->flags |= HASH;
		else if (format[*j] == '0')
			cur->flags |= ZERO;
		else if (format[*j] == '-')
			cur->flags |= MINUS;
		else if (format[*j] == '+')
			cur->flags |= PLUS;
		else if (format[*j] == ' ')
			cur->flags |= SPACE;
		(*j)++;
	}
}

static void	get_width(const char *format, t_pformat *cur, int *j, va_list ap)
{
	while (ft_strchr("123456789*", (int)format[*j]))
	{
		if (format[*j] == '*')
		{
			cur->field_width = va_arg(ap, int);
			if (cur->field_width < 0)
			{
				cur->flags |= MINUS;
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

static void	get_pre(const char *format, t_pformat *cur, int *j, va_list ap)
{
	if (format[*j] == '.')
	{
		cur->flags |= DOT;
		(*j)++;
		if (ft_strchr("0123456789*", (int)format[*j]))
		{
			while (format[*j] == '0')
				(*j)++;
			if (format[*j] == '*')
			{
				cur->precision = va_arg(ap, int);
				if (cur->precision < 0)
				{
					cur->precision = 0;
					cur->flags ^= DOT;
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

void	get_format_data(const char *format, t_pformat *cur, int *j, va_list ap)
{
	get_alt_flags(format, j, ap);
	get_flags(format, cur, j);
	get_width(format, cur, j, ap);
	get_pre(format, cur, j, ap);
	get_length_modifier(format, cur, j);
}
