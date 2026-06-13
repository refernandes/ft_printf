/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refernan <refernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 20:47:27 by refernan          #+#    #+#             */
/*   Updated: 2026/06/13 12:01:33 by refernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	parser_format(va_list *args, char spec);

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			count += parser_format(&args, str[i + 1]);
			i += 2;
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			count++;
			i++;
		}
	}
	va_end(args);
	return(count);
}
static int	parser_format(va_list *args, char spec)
{
	if (spec == 'c')
		return (print_char(va_arg(*args, int)));
	if (spec == 's')
		return (print_str(va_arg(*args, char *))); 
	if (spec == '%')
		return (print_percent());
	return (0);
}