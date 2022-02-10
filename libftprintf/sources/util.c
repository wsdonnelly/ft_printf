/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:12:04 by wdonnell          #+#    #+#             */
/*   Updated: 2022/02/10 15:50:45 by wdonnell         ###   ########.fr       */
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

int	num_digits_base(unsigned long long n, int base, int sum)
{
	if (n == 0)
		return (1);
	if (n / (unsigned long long)base)
		sum = num_digits_base(n / (unsigned long long)base, base, sum);
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

long double	round_double(long double nb, int precision)
{
	long double	rounder;
	int			i;

	rounder = 0.5;
	i = precision;
	while (i-- > 0)
		rounder /= 10;
	if (nb < 0)
		nb -= rounder;
	else
		nb += rounder;
	return (nb);
}

int	strchr_i(const char *s, int c)
{
	int		i;
	char	*p;
	char	cc;

	cc = (char)c;
	p = (char *)s;
	i = 0;
	if (*p == '\0' && cc != '\0')
		return (-1);
	while (p[i] != cc && p[i] != '\0')
	{
		i++;
		if (p[i] == '\0')
			return (-1);
	}
	return (i);
}
