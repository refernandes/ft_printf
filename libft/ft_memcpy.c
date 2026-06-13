/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refernan <refernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 22:44:54 by renan             #+#    #+#             */
/*   Updated: 2026/06/04 09:22:27 by refernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *to, const void *from, size_t size)
{
	unsigned char		*dest;
	unsigned char		*src;
	size_t				i;

	i = 0;
	if (to == NULL && from == NULL)
		return (NULL);
	dest = (unsigned char *)to;
	src = (unsigned char *)from;
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
	return (to);
}
