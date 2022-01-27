/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:25:17 by wdonnell          #+#    #+#             */
/*   Updated: 2022/01/27 13:37:05 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void print_char(t_pformat *cur, va_list ap)
{
	unsigned char c;
	char *temp;

	c = (unsigned char)va_arg(ap, int);

	if (cur->hash || cur->zero || cur->space || cur->plus || cur->dot)
		//undefined
		return ;
	if (cur->field_width)
	{
		temp = ft_strnew(cur->field_width);
		cur->printed_length = cur->field_width; //maybe this could be the same??
		add_char_to_field(temp, &c, cur);
		ft_putstr(temp);
		free (temp);
		return ;
	}
	cur->printed_length = write (1, &c, 1);
}
