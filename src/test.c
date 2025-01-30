/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:08:16 by ayoub             #+#    #+#             */
/*   Updated: 2025/01/30 18:20:53 by ayoub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	unit_test_point3d_create(void)
{
	t_point3d	*point;

	point = init_point3d(1, 2, 3, RED);
	if (point->x == 1 && point->y == 2 && point->z == 3 && point->color == RED)
		ft_putendl_fd("Point3d creation test: \033[0;32mOK\033[0m", 2);
	else
		ft_putendl_fd("Point3d creation test: \033[0;31mKO\033[0m", 2);
	free(point);
}

void	unit_test_point2d_create(void)
{
	t_point2d	*point;

	point = init_point2d(1, 2);
	if (point->x == 1 && point->y == 2)
		ft_putendl_fd("Point2d creation test: \033[0;32mOK\033[0m", 2);
	else
		ft_putendl_fd("Point2d creation test: \033[0;31mKO\033[0m", 2);
	free(point);
}

void	unit_test_point3d_print(void)
{
	t_point3d	*point;

	point = init_point3d(1, 2, 3, RED);
	print_point(point, true);
	free(point);
}

void	unit_test_point2d_print(void)
{
	t_point2d	*point;

	point = init_point2d(1, 2);
	print_point(point, false);
	free(point);
}

void	unit_test_map_init_map(void)
{
	t_map	*map;

	map = init_map();
	if (map->pts_3d == NULL)
		ft_putendl_fd("Map creation test: \033[0;32mOK\033[0m", 2);
	else
		ft_putendl_fd("Map creation test: \033[0;31mKO\033[0m", 2);
	free(map);
}

void	unit_test_map_parse_map_wrong_fd(void)
{
	t_map	*map;

	map = init_map();
	if (parse_map(map, 0) == false)
		ft_putendl_fd("Map parsing test: \033[0;32mOK\033[0m", 2);
	else
		ft_putendl_fd("Map parsing test: \033[0;31mKO\033[0m", 2);
	free(map);
}

void	print_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			print_point(&map->pts_3d[i][j], true);
			j++;
		}
		i++;
	}
}

void	unit_test_map_parse_map_good_fd(void)
{
	t_map	*map;
	int	fd;

	fd = open("maps/42.fdf", O_RDONLY);
	map = init_map();
	if (parse_map(map, fd) == true)
		ft_putendl_fd("Map parsing test: \033[0;32mOK\033[0m", 2);
	else
		ft_putendl_fd("Map parsing test: \033[0;31mKO\033[0m", 2);
	// print_map(map);
	free(map);
	close(fd);
}

void	exec_tests(void)
{
	// points tests
	// unit_test_point3d_create();
	// unit_test_point2d_create();
	// unit_test_point3d_print();
	// unit_test_point2d_print();
	
	// map tests
	// unit_test_map_init_map();
	// unit_test_map_parse_map_wrong_fd();
	// unit_test_map_parse_map_good_fd();
}
