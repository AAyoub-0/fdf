/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:27:51 by aboumall          #+#    #+#             */
/*   Updated: 2025/02/25 14:52:08 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static int	is_toolarge(ssize_t result, char next_digit)
{
	if (result > INT_MAX / 10 || (result == INT_MAX / 10 && (next_digit
				- '0') > INT_MAX % 10))
		return (0);
	if (result < INT_MIN / 10 || (result == INT_MIN / 10
			&& (next_digit - '0') > -(INT_MIN % 10)))
		return (0);
	return (1);
}

static int	is_valid(int n)
{
	if (n == '-')
		return (0);
	return (1);
}

int	ft_atoi(const char *nptr)
{
	ssize_t	result;
	int		i;
	int		sign;

	i = 0;
	result = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		if (!is_valid(nptr[i + 1]))
			return (0);
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		if (is_toolarge(result, nptr[i]) <= 0)
			return (is_toolarge(result, nptr[i]));
		result = result * 10 + nptr[i] - '0';
		i++;
	}
	return (result * sign);
}

void	ft_set_error(int *err)
{
	*err = 1;
}

int	ft_atoi_error(char *nptr, int *error)
{
	ssize_t	result;
	int		i;
	int		sign;

	i = 0;
	result = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-')
	{
		sign *= -1;
		if (!is_valid(nptr[i + 1]))
			return (ft_set_error(error), EXIT_FAILURE);
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		if (is_toolarge(result, nptr[i]) <= 0)
			return (ft_set_error(error), EXIT_FAILURE);
		result = result * 10 + nptr[i] - '0';
		i++;
	}
	return (result * sign);
}
