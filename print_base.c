/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuopea <ssuopea@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:54:46 by ssuopea           #+#    #+#             */
/*   Updated: 2025/05/29 13:59:51 by ssuopea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	invalid_base(char *base);
static void	store_radix(char *base, long *radix);
static void	handle_negatives(long *temp);
static long	expo(long base, long exponent);

void	print_base(int nbr, char *base)
{
	long	radix;
	long	pos;
	long	multiple;
	long	temp;

	if (invalid_base(base))
		return ;
	temp = nbr;
	pos = 1;
	store_radix(base, &radix);
	handle_negatives(&temp);
	while (temp >= expo(radix, pos))
		pos++;
	while (pos > 1)
	{
		multiple = radix - 1;
		while (temp < expo(radix, pos - 1) * multiple && multiple != 0)
			multiple--;
		write(1, &base[multiple], 1);
		temp -= expo(radix, pos - 1) * multiple;
		pos--;
	}
	write(1, &base[temp], 1);
}

static int	invalid_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = 1;
		if (base[i] == '+' || base[i] == '-')
			return (1);
		while (base[i + j])
		{
			if (base[i] == base [i + j])
				return (1);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (1);
	return (0);
}

static void	store_radix(char *base, long *radix)
{
	long	i;

	i = 0;
	while (base[i])
		i++;
	*radix = i;
}

static long	expo(long base, long exponent)
{
	long	out;

	out = base;
	while (exponent - 1)
	{
		out *= base;
		exponent--;
	}
	return (out);
}

static void	handle_negatives(long *temp)
{
	if (*temp < 0)
	{
		write(1, "-", 1);
		*temp = -*temp;
	}
}
