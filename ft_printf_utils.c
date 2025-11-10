/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva <csilva@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:33:56 by csilva            #+#    #+#             */
/*   Updated: 2025/11/10 17:12:38 by csilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "Libft/libft.h"

int	ft_putnbr_base(unsigned int n, char *base, int count)
{
	size_t	base_len;

	base_len = ft_strlen(base);
	if (n >= base_len)
		count = ft_putnbr_base(n / base_len, base, count);
	if (ft_putchar_fd(base[n % base_len], 1) == -1)
		return (-1);
	return (++count);
}

int	ft_putaddres(unsigned long n, int count)
{
	char			*base;

	base = "0123456789abcdef";
	if (n >= 16)
		count = ft_putaddres(n / 16, count);
	if (ft_putchar_fd(base[n % 16], 1) == -1)
		return (-1);
	return (++count);
}
