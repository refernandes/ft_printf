/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refernan <refernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 12:42:08 by refernan          #+#    #+#             */
/*   Updated: 2026/06/15 21:21:47 by refernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_ptr_hex(unsigned long n)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_put_ptr_hex(n / 16);
	print_char("0123456789abcdef"[n % 16]);
	return (count + 1);
}

int	print_ptr(void *ptr)
{
	unsigned long	n;
	int				count;

	if (ptr == NULL)
		return (print_str("(nil)"));
	n = (unsigned long)ptr;
	count = print_str("0x");
	return (count + ft_put_ptr_hex(n));
}
