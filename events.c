/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 15:26:45 by dzui              #+#    #+#             */
/*   Updated: 2017/02/13 15:26:47 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		my_key_func(int key_code, t_env *world)
{
	ft_putendl(ft_itoa(key_code));
	if (key_code == 65307)
	{
		ft_putendl("Exit");
		exit(0);
	}
	if (key_code == 114)
		world->color = 1;
	if (key_code == 103)
		world->color = 2;
	if (key_code == 98)
		world->color = 3;
	if (key_code == 105)
		world->color = 0;
	event_1(key_code, world);
	event_2(key_code, world);
	if (key_code == 48)
		set_default(world);
	translate(world);
	return (0);
}

void	event_1(int key_code, t_env *world)
{
	if (key_code == 61)
		world->scale += 1;
	if (key_code == 45)
	{
		if (world->scale != 1)
			world->scale -= 1;
	}
	if (key_code == 97)
		world->x_offset -= 2;
	if (key_code == 100)
		world->x_offset += 2;
	if (key_code == 119)
		world->y_offset -= 2;
	if (key_code == 115)
		world->y_offset += 2;
	if (key_code == 91)
		world->scale_z++;
	if (key_code == 93)
		world->scale_z--;
}

void	event_2(int key_code, t_env *world)
{
	if (key_code == 49)
		world->projection = 0;
	if (key_code == 50)
		world->projection = 1;
	if (key_code == 51)
		world->projection = 2;
	if (key_code == 101)
		x_rotation(world, 0.019);
	if (key_code == 113)
		x_rotation(world, -0.019);
	if (key_code == 65361)
		z_rotation(world, 0.019);
	if (key_code == 65363)
		z_rotation(world, -0.019);
	if (key_code == 65362)
		y_rotation(world, -0.019);
	if (key_code == 65364)
		y_rotation(world, 0.019);
}

void	set_default(t_env *world)
{
	int i;
	int j;

	i = 0;
	world->scale = 30;
	world->scale_z = 2;
	world->x_offset = WIDTH / 2;
	world->y_offset = HEIGHT / 2;
	while (i < world->row)
	{
		j = 0;
		while (j < world->col)
		{
			world->pts[i][j] = world->init[i][j];
			j++;
		}
		i++;
	}
}
