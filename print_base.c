/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuopea <ssuopea@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:54:46 by ssuopea           #+#    #+#             */
/*   Updated: 2025/05/29 17:11:46 by ssuopea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_reverse(char *buffer, int len)
{
	char	out[24];
	int		index_out;

	index_out = 0;
	while (index_out <= len)
	{
		out[index_out] = buffer[len - index_out - 1];
		index_out++;
	}
	return (write(1, out, len));
}

int	print_base(int nbr, char *base)
{
	char	buffer[24];
	int		i;
	int		positive;
	long	temp;

	if (nbr == 0)
		return (write(1, "0", 1));
	i = 0;
	positive = 1;
	temp = nbr;
	if (temp < 0)
	{
		positive = 0;
		temp = -temp;
	}
	while (temp > 0)
	{
		buffer[i++] = base[temp % ft_strlen(base)];
		temp /= ft_strlen(base);
	}
	if (!positive)
		buffer[i++] = '-';
	return (write_reverse(buffer, i--));
}
