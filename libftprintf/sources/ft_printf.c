/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 22:01:07 by wdonnell          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/02/08 16:10:22 by wdonnell         ###   ########.fr       */
=======
/*   Updated: 2022/02/09 16:22:28 by wdonnell         ###   ########.fr       */
>>>>>>> full
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
static void	get_conversion(char c, t_pformat *cur, va_list ap)
{
	if (c == '%')
		print_percent(cur);
	if (c == 'c')
		print_char(cur, ap);
	if (c == 'p')
		print_pointer(cur, ap);
	else if (c == 's')
		print_str(cur, ap);
	//else if (c == 'p')
		//print_pointer(cur, ap);
	else if (c == 'd' || c == 'i')
		print_di(cur, ap);
<<<<<<< HEAD
	else if (c == 'o' || c == 'u' || c == 'x' \
		|| c == 'X' || c == 'b')
		print_unsigned(cur, ap, c);
=======
	else if (c == 'o' )
		print_octal(cur, ap);
	//else if (c == 'u')
		//print_unsigned(cur, ap);
	//else if (c == 'x' || c == 'X')
	//	print_hex(cur, ap);
	//else if (c == 'b')
	//	print_binary(cur, ap);
>>>>>>> full
	else if (c == 'f')
		print_float(cur, ap);
}
*/
static void	init_pformat(t_pformat *cur)
{
	cur->flags = 0;
	cur->field_width = 0;
	cur->precision = 0;
	ft_bzero(&cur->length_modifier, sizeof(char) * 3);
	cur->length = 0;
}

static int	find_format(va_list ap, const char *format, t_pformat *cur)
{
	int	j;
	int i;

	init_pformat(cur);
	j = 0;
	i = 0;
	get_format_data(format, cur, &j, ap);

	i = strchr_i("%cspdibouxXf", (int)format[j]);
	if (i >= 0)
	{
		dispatch[i](cur, ap);
		return (++j);
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			i;
	int			total;
	t_pformat	cur;

	if (!format)
		return (0);
	va_start(ap, format);
	total = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i += find_format(ap, &format[i + 1], &cur) + 1;
			total += cur.length;
		}
		else
		{
			total += write(1, &format[i], 1);
			i++;
		}
	}
	va_end(ap);
	return (total);
}
