/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:12:04 by wdonnell          #+#    #+#             */
/*   Updated: 2022/02/04 11:57:32 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_char(char c, int len)
{
	int	i;
	int	n;

	n = 0;
	i = 0;
	while (i < len)
	{
		n += write (1, &c, 1);
		i++;
	}
	return (n);
}

int	putstr_len(char const *s, int len)
{
	int	n;
	int	i;

	i = 0;
	n = 0;
	if (!s)
		return (0);
	while (i < len)
	{
		ft_putchar(s[i++]);
		n++;
	}
	return (n);
}

int	num_digits_base(unsigned long long n, unsigned long long base, int sum)
{
	if (n == 0)
		return (1);
	if (n / base)
		sum = num_digits_base(n / base, base, sum);
	return (++sum);
}

int	ft_num_digits_s(long long n)
{
	int	num_digits;

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
*/

void	ft_putnbr_s(long long n)
{	
	if (n < 0)
	{
		if (n == LONG_MIN)
		{
			ft_putstr("9223372036854775808");
			return ;
		}
		n = -n;
	}
	if (n / 10)
		ft_putnbr_s(n / 10);
	ft_putchar (n % 10 + '0');
	return ;
}
