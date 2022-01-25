/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 12:22:57 by wdonnell          #+#    #+#             */
/*   Updated: 2022/01/25 16:03:46 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*str_rev(char *str)
{
	int		i;
	int		len;
	char	temp;

	i = 0;
	len = ft_strlen(str);
	while (i < len / 2)
	{
		temp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = temp;
		i++;
	}
	return (str);
}

static void	fill_num(char *num, int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
	{
		num[0] = '0';
		return ;
	}
	while (n)
	{
		num[i] = (n % 10) + 48;
		n /= 10;
		i++;
	}
	num[i] = '\0';
}

void	ft_putnbr_fd(int n, int fd)
{
	char	*done;
	int		sign;
	char	num[12];

	ft_bzero(num, 12);
	sign = 1;
	if (n < 0)
		sign = -1;
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	n *= sign;
	fill_num(num, n);
	if (sign == -1)
		num[ft_num_digits(n)] = '-';
	done = str_rev(num);
	ft_putstr_fd(done, fd);
}
