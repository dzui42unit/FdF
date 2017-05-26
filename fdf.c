/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 15:15:25 by dzui              #+#    #+#             */
/*   Updated: 2017/02/13 15:15:30 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	t_env	world;
	char	*file;
	char	**map;
	int		fd;

	map = (char**)malloc(sizeof(char*) * 1000);
	ft_bzero(map, 1000);
	fd = open(argv[argc - 1], O_RDONLY);
	world.row = 0;
	ft_error(argc, fd);
	while (get_next_line(fd, &file) > 0)
	{
		map[world.row] = ft_strdup(file);
		world.row++;
	}
	map[world.row] = 0;
	world.matrix = make_matrix(map, &world);
	create_window(&world);
	close(fd);
	return (0);
}

void	ft_error(int argc, int fd)
{
	if (argc != 2)
	{
		ft_putendl("Invalid number of arguments");
		exit(0);
	}
	if (fd == -1)
	{
		ft_putendl("File missing");
		exit(0);
	}
}

void	create_window(t_env *world)
{
	int i;

	i = 0;
	set_basic(world);
	world->pts = (t_point **)malloc(sizeof(t_point) * world->row);
	world->trans = (t_point **)malloc(sizeof(t_point) * world->row);
	world->init = (t_point **)malloc(sizeof(t_point) * world->row);
	while (i < world->row)
	{
		world->pts[i] = (t_point *)malloc(sizeof(t_point) * world->col);
		world->trans[i] = (t_point *)malloc(sizeof(t_point) * world->col);
		world->init[i++] = (t_point *)malloc(sizeof(t_point) * world->col);
	}
	make_points(world);
	translate(world);
	world->mlx = mlx_init();
	world->win = mlx_new_window(world->mlx, WIDTH, HEIGHT, "fdf");
	world->image = mlx_new_image(world->mlx, WIDTH, HEIGHT);
	mlx_hook(world->win, 2, 3, my_key_func, world);
	mlx_loop_hook(world->mlx, &main_activity, world);
	mlx_loop(world->mlx);
}

void	set_basic(t_env *world)
{
	world->scale = 30;
	world->scale_z = 2;
	world->x_offset = WIDTH / 2;
	world->y_offset = HEIGHT / 2;
	world->projection = 0;
	world->color = 0;
}

int		main_activity(t_env *world)
{
	img_clear(world);
	draw_picture_1(world);
	draw_picture_2(world);
	mlx_put_image_to_window(world->mlx, world->win, world->image, 0, 0);
	ft_draw_controls(world);
	return (0);
}

void	ft_draw_controls(t_env *world)
{
	mlx_string_put(world->mlx, world->win, 10, HEIGHT - 70, 0x00FFFF00, "W/A/S/D to move image");
	mlx_string_put(world->mlx, world->win, 10, HEIGHT - 60, 0x00FFFF00, "-/+ to scale image");
	mlx_string_put(world->mlx, world->win, 10, HEIGHT - 50, 0x00FFFF00, "R/G/B - to change colors");
	mlx_string_put(world->mlx, world->win, 10, HEIGHT - 40, 0x00FFFF00, "Q/E - for x axis rotation");
	mlx_string_put(world->mlx, world->win, 10, HEIGHT - 30, 0x00FFFF00, "arrow up/arrow down - for z axis rotation");
	mlx_string_put(world->mlx, world->win, 10, HEIGHT - 20, 0x00FFFF00, "arrow left/arrow right - for y axis rotation");
	mlx_string_put(world->mlx, world->win, 10, HEIGHT - 10, 0x00FFFF00, "ESC - for exit");
}
