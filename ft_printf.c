/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuopea <ssuopea@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:47:33 by ssuopea           #+#    #+#             */
/*   Updated: 2025/05/29 15:34:06 by ssuopea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	select_substitution(const char flag, va_list *args);
static int	print_char(char c);
static int	print_string(char *s);

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		printed_total;
	int		printed_last;

	i = 0;
	printed_total = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] != '%')
			printed_last = write(1, str + i, 1);
		else
		{
			printed_last = select_substitution(str[i + 1], &args);
			i++;
		}
		if (printed_last == -1)
			return (-1);
		printed_total += printed_last;
		i++;
	}
	va_end(args);
	return (printed_total);
}

static int	select_substitution(const char flag, va_list *args)
{
	if (flag == 'c')
		return (print_char(va_arg(*args, int)));
	if (flag == 's')
		return (print_string((char *)va_arg(*args, int *)));
	if (flag == 'd' || flag == 'i')
		return (print_base(va_arg(*args, int), "0123456789"));
	if (flag == 'u')
		return (print_base(va_arg(*args, unsigned), "0123456789"));
	if (flag == 'x')
		return (print_base(va_arg(*args, unsigned), "0123456789abcdef"));
	if (flag == 'X')
		return (print_base(va_arg(*args, unsigned), "0123456789ABCDEF"));
	if (flag == 'p')
	{
		write(1, &"0x", 2);
		return (print_base(va_arg(*args, void *), "0123456789abcdef"));
	}
	if (flag == '%')
		return (write(1, &"%", 1));
	return (-1);
}

static int	print_char(char c)
{
	return (write(1, &c, 1));
}

static int	print_string(char *s)
{
	int		last_count;
	int		total_count;
	size_t	i;

	i = 0;
	total_count = 0;
	while (s[i])
	{
		last_count = write(1, s + i, 1);
		if (last_count < 0)
			return (-1);
		total_count += last_count;
		i++;
	}
	return (total_count);
}
