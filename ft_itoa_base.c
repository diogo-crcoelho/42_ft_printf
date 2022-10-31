/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarvalh <dcarvalh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:04:36 by dcarvalh          #+#    #+#             */
/*   Updated: 2022/10/26 00:29:43 by dcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	digit_count(unsigned long num, int base_len)
{
	int	i;

	i = 0;
	if (num <= 0)
		i ++;
	while (num)
	{
		num /= base_len;
		i ++;
	}
	return (i);
}

char	*ft_itoa_base(unsigned long num, char *base, int base_len, int n)
{
	char		*res;
	int			size;

	if (!n)
		num = (unsigned int)num;
	size = digit_count(num, base_len);
	res = (char *)malloc(size + 1);
	if (!res)
		return (NULL);
	res[size] = 0;
	if (num == 0)
		res[0] = 48;
	while (num > 0)
	{		
		res[--size] = base[num % base_len];
		num /= base_len;
	}
	return (res);
}
