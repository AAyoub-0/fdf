/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:52:55 by aboumall          #+#    #+#             */
/*   Updated: 2025/01/22 14:11:45 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void    print_point2d(t_point2d *point)
{
    if (!point)
    {
        printf("Point[%p] NULL\n", point);
        return ;
    }
    printf("Point[%p]\n{\n", point);
    printf("%10s : %d\n", "x", point->x);
    printf("%10s : %d\n", "y", point->y);
    printf("}\n");
}

void    print_point3d(t_point *point)
{
    if (!point)
    {
        printf("Point[%p] NULL\n", point);
        return ;
    }
    printf("Point[%p]\n{\n", point);
    printf("%10s : %.2f\n", "x", point->x);
    printf("%10s : %.2f\n", "y", point->y);
    printf("%10s : %.2f\n", "z", point->z);
    printf("%10s : %d\n", "color", point->color);
    printf("}\n");
}