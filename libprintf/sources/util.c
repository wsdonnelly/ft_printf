/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:12:04 by wdonnell          #+#    #+#             */
/*   Updated: 2022/01/31 16:18:41 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

 //maybe add to lib?
 //or make write blank
ssize_t write_char(char c, size_t len)
{
	size_t i;
	ssize_t n;

	n = 0;
	i = 0;
	while (i < len)
	{
		n += write (1, &c, 1);
		i++;
	}
	return (n);
}

size_t putstr_len(char const *s, size_t len)
{
	size_t n;
	size_t i;

	i = 0;
	n = 0;
	if (!s)
		return 0;
	while (i < len)
	{
		ft_putchar(s[i++]);
		n++;
	}
	return (n);
}

unsigned int num_digits_base(unsigned long long n, unsigned long long base)
{
	static unsigned int	sum;

	if (n > 0)
	{
		num_digits_base(n / base, base);
			return (++sum);
	}
	else
		return (++sum);
	return (0);
}

unsigned int	ft_num_digitsLL(long long n)
{
	unsigned int	num_digits;

	num_digits = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		num_digits++;
		n /= 10;
	}
	return (num_digits);
}

/*
** writes to stdout up to signed long long
** does not print sign
** returns number of digits
*/

unsigned int	ft_putnbrLL(long long n)
{
	static unsigned int	sum;

	if (n < 0)
		n = -n;
	if (n / 10)
		ft_putnbrLL(n / 10);
	ft_putchar (n % 10 + '0');
	return (++sum);

}
