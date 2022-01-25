/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 11:40:39 by wdonnell          #+#    #+#             */
/*   Updated: 2022/01/25 16:18:42 by wdonnell         ###   ########.fr       */
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
	char	conversion;
	int		printed_length;
}				t_pformat;

int	ft_printf(const char *format, ...);

#endif

//%[$][flags][width][.precision][length modifier]conversion