/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:13:42 by wdonnell          #+#    #+#             */
/*   Updated: 2022/01/26 22:05:29 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long	x;

	x = (long)n;
	if (x < 0)
	{
		ft_putchar('-');
		x *= -1;
	}
	if (x / 10)
		ft_putnbr (x / 10);
	ft_putchar (x % 10 + '0');
}
