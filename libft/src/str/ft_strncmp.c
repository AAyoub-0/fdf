/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:45:56 by aboumall          #+#    #+#             */
/*   Updated: 2025/02/17 15:55:33 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (((unsigned char)s1[i] == (unsigned char)s2[i]) && (s1[i] && s2[i])
		&& (i < n - 1))
		i++;
	return (((unsigned char)s1[i] - (unsigned char)s2[i]));
}

t_bool	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (null);
	while ((s1[i] == s2[i]) && (s1[i] && s2[i]))
		i++;
	if ((!s1[i] && !s2[i]))
		return (true);
	return (false);
}
