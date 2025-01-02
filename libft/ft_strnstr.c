/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aayoub <aayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:47:29 by aboumall          #+#    #+#             */
/*   Updated: 2024/11/22 21:50:45 by aayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		while (big[i + j] == little[j] && (little[j] && big[i + j])
			&& (i + j < len))
			j++;
		if (little[j] == '\0')
			return ((char *)&big[i]);
		else
			j = 0;
		i++;
	}
	return (NULL);
}
