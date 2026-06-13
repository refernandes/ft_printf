/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refernan <refernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 08:32:31 by refernan          #+#    #+#             */
/*   Updated: 2026/06/06 12:37:43 by refernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*dest;
	size_t		size_s1;
	size_t		size_s2;

	if (s1 == NULL || s2 == NULL)
		return (0);
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	dest = (char *)malloc((size_s1 + size_s2 + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	ft_strlcpy(dest, s1, size_s1 + 1);
	ft_strlcpy(dest + size_s1, s2, size_s2 + 1);
	return (dest);
}
