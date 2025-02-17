/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:14:09 by aboumall          #+#    #+#             */
/*   Updated: 2025/02/17 17:17:24 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	ft_free_2dm_char(char **tab, size_t size)
{
	size_t	i;

	if (!tab)
		return ;
	i = 0;
	while (i < size)
	{
		if (tab[i])
			free(tab[i]);
		tab[i] = NULL;
	}
	free(tab);
}
