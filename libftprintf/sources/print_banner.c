/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_banner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 13:52:57 by wdonnell          #+#    #+#             */
/*   Updated: 2022/02/12 16:31:26 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define A 0x9F96
#define B 0xF9F1
#define C 0xF11F
#define D 0x7997
#define E 0xF71F
#define F 0x171F
#define G 0xF91F
#define H 0x99F9
#define I 0xF66F
#define J 0xF988
#define K 0xD77D
#define L 0xF111
#define M 0x9BBF
#define N 0x9DB9
#define O 0xF99F
#define P 0x1F9F
#define Q 0x7D9F
#define R 0x5FBF
#define S 0xF42F
#define T 0x666F
#define U 0xF999
#define V 0x6999
#define W 0xFDD9
#define X 0x9669
#define Y 0x66F9
#define Z 0xF24F

static void	print_letter(char c, int line, uint16_t *shift)
{
	int						j;
	uint16_t				i;
	char					cc;
	static const uint16_t	alpha[26] = {A, B, C, D, E, F, G, H, I, J, K, L, M, \
							N, O, P, Q, R, S, T, U, V, W, X, Y, Z};

	cc = (char)ft_tolower((int)c);
	i = *shift;
	j = line * 4;
	while (j < (line + 1) * 4)
	{
		if (i & alpha[cc - 'a'])
			ft_putstr("\u2588");
		else
			ft_putchar(' ');
		i <<= 1;
		j++;
	}
	ft_putstr("  ");
}

void	print_banner(t_pformat *cur, va_list ap)
{
	char		*str;
	int			i;
	int			j;
	int			k;
	int			line;
	uint16_t	shift;

	cur->length = 0;
	str = va_arg(ap, char *);
	j = 0;
	i = 0;
	while (str[i])
	{
		shift = 1;
		line = 0;
		while (line < 4)
		{
			j = i;
			k = 0;
			while (str[j] != ' ' && str[j])
			{
				print_letter(str[j], line, &shift);
				j++;
				k++;
			}
			line++;
			shift <<= 4;
			ft_putchar('\n');
		}
		ft_putchar('\n');
		i += k;
		if (str[i] == ' ')
			i++;
	}
}
