/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:40:16 by aboumall          #+#    #+#             */
/*   Updated: 2025/02/24 17:35:28 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	s_size;
	size_t	d_size;

	s_size = ft_strlen(s);
	if (len > s_size)
		len = s_size;
	if (start >= s_size)
		return (ft_strdup("\0"));
	if (len < ft_strlen(s + start))
		d_size = len + 1;
	else
		d_size = s_size - start + 1;
	dst = (char *)malloc(d_size * sizeof(char));
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, s + start, d_size);
	return (dst);
}

char	*ft_better_substr(char *s, int start, int len)
{
	char	*result;
	int		i;

	result = ft_calloc(len + 1, sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (s[start] && start < len)
	{
		result[i] = s[start];
		start++;
		i++;
	}
	return (result);
}
