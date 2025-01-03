/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aayoub <aayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:27:51 by aboumall          #+#    #+#             */
/*   Updated: 2025/01/02 21:48:44 by aayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_toolarge(long int result, int n)
{
	if (result > (LONG_MAX - (n - '0')) / 10)
		return (-1);
	if (-result > (LONG_MAX - (n - '0')) / 10)
		return (0);
	return (1);
}

static int	is_valid(int n)
{
	if (n == '-' || n == '+' || !ft_isdigit(n))
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

unsigned int ft_atoi_base(const char *nptr, const char *base)
{
	unsigned int    result;
	int             i;
	int             j;

	i = 0;
	result = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	while (nptr[i] == '0')
		i++;
	while (nptr[i])
	{
		j = 0;
		while (base[j] && base[j] != nptr[i])
			j++;
		if (!base[j])
			break ;
		result = result * ft_strlen(base) + j;
		i++;
	}
	return (result);
}
