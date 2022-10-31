/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarvalh <dcarvalh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 01:11:10 by dcarvalh          #+#    #+#             */
/*   Updated: 2022/10/26 00:22:18 by dcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "limits.h"

# define HEXAL "0123456789abcdef"
# define HEXAU "0123456789ABCDEF"

char	*ft_putnbr_base(int num, int base_len);
char	*ft_putunbr_base(unsigned long num, int base_len, int n);
char	*ft_itoa_base(unsigned long num, char *base, int base_len, int n);
int		ft_printf(const char *format, ...);

#endif