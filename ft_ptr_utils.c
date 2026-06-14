/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refernan <refernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 12:42:08 by refernan          #+#    #+#             */
/*   Updated: 2026/06/14 11:32:59 by refernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_ptr_hex(unsigned long n);

int	print_ptr(void *ptr)
{
	unsigned long	n;
	int				count;
	int				status;

	if (ptr == NULL)
		return (print_str("(nil)"));
	n = (unsigned long)ptr;
	count = print_str("0x");
	if (count == -1)
		return (-1);
	status = ft_put_ptr_hex(n);
	if (status == -1)
		return (-1);
	return (count + status);
}

static int	ft_put_ptr_hex(unsigned long n)
{
	int	count;
	int	status;

	count = 0;
	if (n >= 16)
	{
		status = ft_put_ptr_hex(n / 16);
		if (status == -1)
			return (-1);
		count += status;
	}
	if (write(1, &"0123456789abcdef"[n % 16], 1) == -1)
		return (-1);
	return (count + 1);
}