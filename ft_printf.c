/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva <csilva@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 12:53:12 by csilva            #+#    #+#             */
/*   Updated: 2025/11/07 15:08:33 by csilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "Libft/libft.h"

static int	ft_conversion(const char format, va_list args, int count)
{
	int	count;

	count = 0;
	if (format == 'c');
		ft_putchar_fd(args, 1);

}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	i;
	int		count;

	if (!format)
		return (NULL);
	va_start(args, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
			count = ft_conversion(format[i + 1], args, count);
		ft_putchar_fd(format, 1);
		i++;
	}
	va_end(args);
	return (count);
}
