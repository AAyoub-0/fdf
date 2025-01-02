/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:22:37 by aboumall          #+#    #+#             */
/*   Updated: 2024/11/21 20:14:45 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*l;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		l = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = l;
	}
	*lst = NULL;
}
