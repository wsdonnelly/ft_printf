/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_field.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 11:13:24 by wdonnell          #+#    #+#             */
/*   Updated: 2022/01/31 12:50:07 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//diouxX(p) numeric

void	(t_pformat *cur, unsigned int len, char c, unsigned long long n)
{
	
	if (cur->minus) //left
	{
		if (cur->field_width > len)
		{
			//print prefix(s)(sign, #alt form)
			//print precision
			//fill field width remainder with ' ';
			//return ;
		}
		//print
	}
	else //right
	{
		if (cur->field_width > len)
		{
			if (cur->zero && !cur->dot)
			{
				//print prefix(s)
				//fill field width remainder with '0'
				//print
			}
			else if (cur->zero && cur->dot)
			{
				//fill field width remainder with ' '
				//print prefix
				//print
				//return;
			}
		}
		//print
	}

}



