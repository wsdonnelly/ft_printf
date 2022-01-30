/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:12:04 by wdonnell          #+#    #+#             */
/*   Updated: 2022/01/30 16:13:13 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

 //maybe add to lib?
 //or make write blank
int write_char(char c, size_t len)
{
	size_t i;
	int n;

	n = 0;
	i = 0;
	while (i < len)
	{
		n += write (1, &c, 1);
		i++;
	}
	return (n);
}

int putstr_len(char const *s, size_t len)
{
	int n;
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

unsigned int num_digits_base(unsigned long long n, int base)
{
	static unsigned int	sum;

	if (n > 0)
	{
		num_digits_base(n / base, base);
		if (n % base > 9)
			return (++sum);
		else
			return (++sum);
	}
	return (0);
}

/*
** writes to stdout up to signed long long
** does not print sign
** returns number of digits
*/

int	ft_putnbrLL(long long n)
{
	static int	sum;

	if (n < 0)
		n = -n;
	if (n / 10)
		ft_putnbrLL(n / 10);
	ft_putchar (n % 10 + '0');
	return (++sum);

}