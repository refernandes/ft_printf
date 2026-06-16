/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refernan <refernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 12:42:40 by refernan          #+#    #+#             */
/*   Updated: 2026/06/15 21:21:50 by refernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_nbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (print_str("-2147483648"));
	if (n < 0)
	{
		print_char('-');
		count++;
		n = -n;
	}
	if (n >= 10)
		count += print_nbr(n / 10);
	print_char((n % 10) + '0');
	return (count + 1);
}

int	print_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += print_unsigned(n / 10);
	print_char((n % 10) + '0');
	return (count + 1);
}

int	print_hex(unsigned int n, char str)
{
	int		count;
	char	*base;

	if (str == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	count = 0;
	if (n >= 16)
		count += print_hex(n / 16, str);
	print_char(base[n % 16]);
	return (count + 1);
}
