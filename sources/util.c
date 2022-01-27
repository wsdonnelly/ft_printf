/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:12:04 by wdonnell          #+#    #+#             */
/*   Updated: 2022/01/27 13:31:06 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void add_char_to_field(char *str, unsigned char *c, t_pformat *cur)
{
	unsigned int i;

	i = 0;
	while (i < cur->field_width)
	{
		str[i] = ' ';
		i++;
	}
	if (cur->minus)
		str[0] = (char)*c;
	else
		str[cur->field_width - 1] = (char)*c;
}
