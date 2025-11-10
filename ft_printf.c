/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva <csilva@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 12:53:12 by csilva            #+#    #+#             */
/*   Updated: 2025/11/10 17:10:41 by csilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "ft_printf.h"

static int	ft_conversion(const char format, va_list args, int scount)
{
	if (format == 'c')
		scount += ft_putchar_fd(va_arg(args, int), 1);
	else if (format == 's')
		scount += ft_putstr_fd(va_arg(args, char *), 1);
	else if (format == 'p')
	{
		scount += ft_putstr_fd("0x", 1);
		scount = ft_putaddres(va_arg(args, unsigned long), scount);
	}
	else if (format == 'd' || format == 'i')
		scount += ft_putnbr_fd(va_arg(args, int), 1, scount);
	else if (format == 'u')
		scount = ft_putnbr_base(va_arg(args, unsigned int), "0123456789",
				scount);
	else if (format == 'x')
		scount = ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef",
				scount);
	else if (format == 'X')
		scount = ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF",
				scount);
	else if (format == '%')
		scount += ft_putchar_fd('%', 1);
	else
		return (-1);
	return (scount);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	i;
	int		count;

	if (!format)
		return (-1);
	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			count = ft_conversion(format[i + 1], args, count);
			if (count <= -1)
				return (-1);
			i += 2;
		}
		else
			count += ft_putchar_fd(format[i++], 1);
	}
	va_end(args);
	return (count);
}

/* int	main(void)
{
	printf("\n%d\n", ft_printf("Meu nome e %c", 'c'));
	printf("\n%d\n", printf("Meu nome e %c", 'c'));

	printf("\n%d\n", ft_printf("Meu nome e %s", "Caio"));
	printf("\n%d\n", printf("Meu nome e %s", "Caio"));

	printf("\n%d\n", ft_printf("Meu nome e %p", "Caio"));
	printf("\n%d\n", printf("Meu nome e %p", "Caio"));

	printf("\n%d\n", ft_printf("%d", 12345));
	printf("\n%d\n", printf("%d", 12345));

	printf("\n%d\n", ft_printf("%i", 1995));
	printf("\n%d\n", printf("%i", 1995));

	printf("\n%d\n", ft_printf("%u", 199));
	printf("\n%d\n", printf("%u", 199));

	printf("\n%d\n", ft_printf("%x", -2147483647));
	printf("\n%d\n", printf("%x", -2147483647));

	printf("\n%d\n", ft_printf("%X", -2147483647));
	printf("\n%d\n", printf("%X", -2147483647));

	printf("\n%d\n", ft_printf("%%"));
	printf("\n%d\n", printf("%%"));
} */
