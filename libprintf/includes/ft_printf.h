/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 11:40:39 by wdonnell          #+#    #+#             */
/*   Updated: 2022/02/01 12:24:27 by wdonnell         ###   ########.fr       */
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
	unsigned int					field_width;
	unsigned char		dot;
	unsigned int		precision;
	char	length_modifier[3];
	unsigned int		printed_length;
}				t_pformat;

int	ft_printf(const char *format, ...);
void get_conversion(char c, t_pformat *cur, va_list ap);
//util
ssize_t write_char(char c, size_t len);
size_t putstr_len(char const *s, size_t len);
unsigned int	ft_putnbrLL(long long n);
unsigned int num_digits_base(unsigned long long n, unsigned long long base);
unsigned int	ft_num_digitsLL(long long n);
//printers
void print_char(t_pformat *cur, va_list ap);
void print_string(t_pformat *cur, va_list ap);
void print_pointer(t_pformat *cur, va_list ap);
void print_ouxX(t_pformat *cur, va_list ap, char c);
void print_di(t_pformat *cur, va_list ap);


#endif

//%[$][flags][width][.precision][length modifier]conversion
