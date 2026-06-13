/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refernan <refernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 07:27:44 by refernan          #+#    #+#             */
/*   Updated: 2026/06/04 07:36:31 by refernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ptr;
	char	*last_occurrence;

	i = 0;
	ptr = (char *)s;
	last_occurrence = NULL;
	while (ptr[i] != '\0')
	{
		if (ptr[i] == (char)c)
			last_occurrence = &ptr[i];
		i++;
	}
	if (ptr[i] == (char)c)
		last_occurrence = &ptr[i];
	return (last_occurrence);
}
