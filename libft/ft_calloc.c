/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aayoub <aayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:01:57 by aboumall          #+#    #+#             */
/*   Updated: 2025/01/02 22:08:28 by aayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*array;

	if (nmemb != 0 && size > SIZE_MAX / nmemb)
		return (NULL);
	array = malloc(nmemb * size);
	if (array == NULL)
		return (NULL);
	ft_memset(array, 0, nmemb * size);
	return (array);
}

void    *ft_realloc(void *ptr, size_t size)
{
    void    *new;

    new = malloc(size);
    if (!new)
        return (NULL);
    if (ptr)
    {
        ft_memcpy(new, ptr, size);
        free(ptr);
    }
    return (new);
}
