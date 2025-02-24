/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:45:15 by aboumall          #+#    #+#             */
/*   Updated: 2025/02/21 20:33:12 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

size_t	ft_strlen(const char *tab)
{
	size_t	size;

	size = 0;
	if (!tab)
		return (0);
	while (tab[size])
		size++;
	return (size);
}

size_t	ft_str_char_dist_f(char *str, char c)
{
	size_t	size;

	size = 0;
	if (!str)
		return (0);
	while (str[size] && str[size] != c)
		size++;
	return (size);
}

size_t	ft_str_char_dist_l(char *str, char c)
{
	size_t	size;

	if (!str)
		return (0);
	size = ft_strlen(str);
	while (size > 0 && str[size] != c)
		size--;
	return (size);
}
