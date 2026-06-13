/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refernan <refernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 08:30:36 by refernan          #+#    #+#             */
/*   Updated: 2026/06/04 08:31:52 by refernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	size;
	char	*dest;

	if (s == NULL)
		return (NULL);
	size = ft_strlen(s);
	if (start >= size)
		return (ft_calloc(1, sizeof(char)));
	if (len > size - start)
		len = size - start;
	dest = (char *)ft_calloc(len + 1, sizeof(char));
	if (dest == NULL)
		return (NULL);
	ft_memcpy(dest, s + start, len);
	return (dest);
}
