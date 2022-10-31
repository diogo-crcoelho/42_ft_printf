/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarvalh <dcarvalh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 01:18:58 by dcarvalh          #+#    #+#             */
/*   Updated: 2022/10/28 16:15:31 by dcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putstr(char *str)
{
	int	i;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
	return (i);
}

static int	check_nbr(unsigned long int nbr, char *base, int base_len, int c)
{
	char	*temp;
	int		ret;
	long	aux_int;

	ret = 0;
	if (c == 3)
	{
		if (nbr == 0)
			return (ft_putstr("(nil)"));
		ret += write(1, "0x", 2);
	}
	if (c < 0)
	{
		aux_int = (long)nbr;
		if (aux_int < 0)
		{
			ret += write (1, "-", 1);
			aux_int *= -1;
		}
		nbr = aux_int;
	}
	temp = ft_itoa_base(nbr, base, base_len, c);
	ret += ft_putstr(temp);
	free (temp);
	return (ret);
}

static void	check_conversion(char c, va_list args, int *ret)
{
	if (c == 'c')
	{
		c = va_arg(args, int);
		*ret += write(1, &c, 1);
	}
	else if (c == 's')
		*ret += ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		*ret += check_nbr(va_arg(args, unsigned long int), HEXAL, 16, 3);
	else if (c == 'd' || c == 'i')
		*ret += check_nbr(va_arg(args, int), HEXAL, 10, -1);
	else if (c == 'u')
		*ret += check_nbr(va_arg(args, int), HEXAL, 10, 0);
	else if (c == 'x')
		*ret += check_nbr(va_arg(args, int), HEXAL, 16, 0);
	else if (c == 'X')
		*ret += check_nbr(va_arg(args, int), HEXAU, 16, 0);
	else if (c == '%')
		*ret += write(1, &c, 1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		ret;

	va_start(args, format);
	i = -1;
	ret = 0;
	while (format[++i])
	{
		if (format[i] == '%')
			check_conversion(format[++i], args, &ret);
		else
		{
			write(1, &format[i], 1);
			ret ++;
		}
	}
	va_end(args);
	return (ret);
}
