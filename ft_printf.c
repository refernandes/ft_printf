/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refernan <refernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 20:47:27 by refernan          #+#    #+#             */
/*   Updated: 2026/06/14 10:06:13 by refernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	parser_format(va_list *args, char spec);

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;
	int		status;

	if (str == NULL)
		return (-1);
	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1])
			status = parser_format(&args, str[++i]);
		else if (str[i] == '%')
			status = -1;
		else
			status = print_char(str[i]);
		if (status == -1)
			return (va_end(args), -1);
		count += status;
		i++;
	}
	va_end(args);
	return (count);
}

static int	parser_format(va_list *args, char spec)
{
	if (spec == 'c')
		return (print_char(va_arg(*args, int)));
	if (spec == 's')
		return (print_str(va_arg(*args, char *)));
	if (spec == 'p')
		return (print_ptr(va_arg(*args, void *)));
	if (spec == 'd' || spec == 'i')
		return (print_nbr(va_arg(*args, int)));
	if (spec == 'u')
		return (print_unsigned(va_arg(*args, unsigned int)));
	if (spec == 'x' || spec == 'X')
		return (print_hex(va_arg(*args, unsigned int), spec));
	if (spec == '%')
		return (print_percent());
	return (-1);
}
