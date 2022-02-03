/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bits.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 21:38:19 by wdonnell          #+#    #+#             */
/*   Updated: 2022/02/02 22:11:46 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "libft.h"

# define HASH	0x01	//0b00000001
# define ZERO	0x02	//0b00000010
# define MINUS	0x04	//0b00000100
# define PLUS	0x08	//0b00001000
# define SPACE	0x10	//0b00010000
# define DOT	0x20	//0b00100000
//undefined behavior for csp
# define HZSP	0x1B	//0b00011011
typedef struct s_pformat
{
	uint8_t				flags;
	unsigned int		field_width;
	unsigned int		precision;
	char				length_modifier[3];
	unsigned int		printed_length;
}				t_pformat;

int				ft_printf(const char *format, ...);
void			get_format_data(const char *format, t_pformat *cur, int *j);
//util
ssize_t			write_char(char c, size_t len);
size_t			putstr_len(char const *s, size_t len);
void			ft_putnbr_s(long long n);
unsigned int	num_digits_base(unsigned long long n, unsigned long long base, unsigned int sum);
unsigned int	ft_num_digits_s(long long n);
//printers
void			print_percent(t_pformat *cur);
void			print_char(t_pformat *cur, va_list ap);
void			print_string(t_pformat *cur, va_list ap);
void			print_pointer(t_pformat *cur, va_list ap);
void			print_ouxX(t_pformat *cur, va_list ap, char c);
void			print_di(t_pformat *cur, va_list ap);

#endif
