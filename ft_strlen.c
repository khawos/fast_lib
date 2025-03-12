/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_opti.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedenec <amedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 04:56:20 by amedenec          #+#    #+#             */
/*   Updated: 2025/03/12 05:02:03 by amedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fast_lib.h"

size_t	ft_strlen(const char *s)
{
	const char		*start;
	uintptr_t		chunk;
	const uintptr_t	*ptr;

	start = s;
	while ((uintptr_t)s % sizeof(uintptr_t))
	{
		if (!*s)
			return (s - start);
		s++;
	}
	ptr = (const uintptr_t *)s;
	while (1)
	{
		chunk = *ptr++;
		if (((chunk - 0x0101010101010101ULL)
				& (~chunk & 0x8080808080808080ULL)) != 0)
			break ;
	}
	s = (const char *)(ptr - 1);
	while (*s)
		s++;
	return (s - start);
}
