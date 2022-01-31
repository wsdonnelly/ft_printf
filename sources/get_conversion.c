/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:17:04 by wdonnell          #+#    #+#             */
/*   Updated: 2022/01/31 13:52:13 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void get_conversion(char c, t_pformat *cur, va_list ap)
{

	if (c == 'c')
		print_char(cur, ap);
	else if (c == 's')
		print_string(cur, ap);
	else if (c == 'p')
		print_pointer(cur, ap);
	else if (c == 'd' || c == 'i')
		print_di(cur, ap);
	else if (c == 'o' || c == 'u' || c == 'x' || c == 'X')
		print_ouxX(cur, ap, c);
	//else if (c == 'f')
		//print_double(cur, ap);
	
}
