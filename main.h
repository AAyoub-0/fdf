/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aayoub <aayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 20:08:18 by aayoub            #+#    #+#             */
/*   Updated: 2025/01/02 02:10:13 by aayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H


#include <fcntl.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "./libft/libft.h"
#include "./minilibx/mlx.h"

typedef struct s_point
{
    int     x;
    int     y;
    int     z;
    int     color;
}               t_point;

typedef struct s_map
{
    int     **map;
    int     width;
    int     height;
}               t_map;

char    *read_ligne(char *buffer, int fd);

#endif