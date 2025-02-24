/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:17:22 by aboumall          #+#    #+#             */
/*   Updated: 2025/02/24 17:33:15 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_bool	check_extension(char *file)
{
	if (!file || ft_strcmp(file + ft_strlen(file) - 4, FDF_EXT))
		return (true);
	else
		return (false);
}

char	*sub_argv(char *av)
{
	char	*result;

	result = NULL;
	if (ft_strnstr(av, "/", ft_strlen(av)))
	{
		result = ft_better_substr(av, ft_str_char_dist_l(av, '/') + 1,
				ft_str_char_dist_f(av, '.'));
		if (!result)
			return (NULL);
	}
	else
	{
		result = ft_better_substr(av, 0, ft_str_char_dist_l(av, '.'));
		if (!result)
			return (NULL);
	}
	return (result);
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	exit_if(t_bool cond, t_mlx *mlx, int fd_out, ...)
{
	va_list	args;
	void	*ptr;

	if (cond == true)
	{
		if (mlx)
			free_window(mlx, fd_out);
		va_start(args, fd_out);
		ptr = va_arg(args, void *);
		while (ptr != NULL)
		{
			free(ptr);
			ptr = va_arg(args, void *);
		}
		va_end(args);
		exit(fd_out);
	}
}
