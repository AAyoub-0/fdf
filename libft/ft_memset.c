/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aayoub <aayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:12:55 by aboumall          #+#    #+#             */
/*   Updated: 2024/11/22 21:33:00 by aayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*tab;

	i = 0;
	tab = (unsigned char *)s;
	while (i < n)
	{
		tab[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
