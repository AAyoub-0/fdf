/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aayoub <aayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:07:25 by aboumall          #+#    #+#             */
/*   Updated: 2024/11/22 21:32:57 by aayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	copy_f(unsigned char *dest,
	const unsigned char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
}

static void	copy_b(unsigned char *dest,
	const unsigned char *src, size_t n)
{
	size_t	i;

	i = n;
	while (i > 0)
	{
		dest[i - 1] = src[i - 1];
		i--;
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (!dest && !src)
		return (NULL);
	if (dest < src)
		copy_f((unsigned char *)dest, (const unsigned char *)src, n);
	else
		copy_b((unsigned char *)dest, (const unsigned char *)src, n);
	return (dest);
}
