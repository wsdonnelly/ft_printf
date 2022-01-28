/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_diouxX.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:25:11 by wdonnell          #+#    #+#             */
/*   Updated: 2022/01/28 15:16:29 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void print_ouxX(t_pformat *cur, va_list ap, char c)
{
	unsigned long long n;


	if (cur->space || cur->plus || (cur->hash && c == 'u'))
		//undefined
		return ;
	n = (unsigned long long)va_arg(ap, unsigned int);
	
	//append to nums
	if (cur->hash)
	{
		if (c == 'x')
			cur->printed_length += write(1, "0x", 2);
		if (c == 'X')
			cur->printed_length += write(1, "0X", 2);
		if (c == 'o')
			cur->printed_length += write(1, "0", 2);
	}
	
	if (c == 'o')
		cur->printed_length += ft_putnbr_base(n, 8, 0);
	else if (c == 'u')
		cur->printed_length += ft_putnbr_base(n, 10, 0);
	else if (c == 'x')
		cur->printed_length += ft_putnbr_base(n, 16, 0);
	else if (c == 'X')
		cur->printed_length += ft_putnbr_base(n, 16, 1);

}
