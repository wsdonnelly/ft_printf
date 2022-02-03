/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 11:40:39 by wdonnell          #+#    #+#             */
/*   Updated: 2022/02/03 15:13:21 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "libft.h"

typedef struct s_pformat
{
	unsigned char		hash;
	unsigned char		zero;
	unsigned char		minus;
	unsigned char		plus;
	unsigned char		space;
	int		field_width;
	unsigned char		dot;
	int		precision;
	char				length_modifier[3];
	int		printed_length;
}				t_pformat;

int				ft_printf(const char *format, ...);
void get_format_data(const char *format, t_pformat *cur, int *j, va_list ap);
//util
int			write_char(char c, int len);
int			putstr_len(char const *s, int len);
void			ft_putnbr_s(long long n);
int	num_digits_base(unsigned long long n, unsigned long long base, int sum);
int	ft_num_digits_s(long long n);
//printers
void			print_percent(t_pformat *cur);
void			print_char(t_pformat *cur, va_list ap);
void			print_string(t_pformat *cur, va_list ap);
void			print_pointer(t_pformat *cur, va_list ap);
void			print_ouxX(t_pformat *cur, va_list ap, char c);
void			print_di(t_pformat *cur, va_list ap);

#endif

//%[$][flags][width][.precision][length modifier]conversion
