/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_format_data_bits.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 21:57:31 by wdonnell          #+#    #+#             */
/*   Updated: 2022/02/02 22:00:25 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

static void	get_flags(const char *format, t_pformat *cur, int *j)
{
	while (ft_strchr("#0-+ ", (int)format[*j]))
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

static void	get_width(const char *format, t_pformat *cur, int *j)
{
	while (ft_strchr("123456789", (int)format[*j]))
	{
		cur->field_width = (unsigned int)ft_atoi(&format[*j]);
		*j += ft_num_digits((int)cur->field_width);
	}
}

static void	get_precision(const char *format, t_pformat *cur, int *j)
{
	if (format[*j] == '.')
	{
		cur->flags |= DOT;
		(*j)++;
		if (ft_strchr("0123456789", (int)format[*j]))
		{
			cur->precision = (unsigned int)ft_atoi(&format[*j]);
			*j += ft_num_digits((int)cur->precision);
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

void get_format_data(const char *format, t_pformat *cur, int *j)
{
	get_flags(format, cur, j);
	get_width(format, cur, j);
	get_precision(format, cur, j);
	get_length_modifier(format, cur, j);
}
