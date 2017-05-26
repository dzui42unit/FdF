/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 15:16:56 by dzui              #+#    #+#             */
/*   Updated: 2017/02/13 15:16:58 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_env *world)
{
	world->line.dx = fabs(world->p2.x - world->p1.x);
	world->line.dy = fabs(world->p2.y - world->p1.y);
	world->line.sign_x = world->p1.x < world->p2.x ? 1 : -1;
	world->line.sign_y = world->p1.y < world->p2.y ? 1 : -1;
	world->line.error1 = world->line.dx - world->line.dy;
	while (world->p1.x != world->p2.x || world->p1.y != world->p2.y)
	{
		put_pixel_img(world, world->p1.x, world->p1.y, world->line.color);
		world->line.error2 = world->line.error1 * 2;
		if (world->line.error2 > -(world->line.dy))
		{
			world->line.error1 -= world->line.dy;
			world->p1.x += world->line.sign_x;
		}
		if (world->line.error2 < world->line.dx)
		{
			world->line.error1 += world->line.dx;
			world->p1.y += world->line.sign_y;
		}
	}
}

void	draw_picture_1(t_env *world)
{
	int i;
	int	j;

	i = -1;
	while (++i < world->row)
	{
		j = 0;
		while (j < world->col - 1)
		{
			world->line.color = 0x00FFFFFF;
			set_color_1(world, i, j);
			world->p1 = world->trans[i][j++];
			world->p2 = world->trans[i][j];
			draw_line(world);
		}
	}
}

void	draw_picture_2(t_env *world)
{
	int i;
	int	j;

	j = -1;
	while (++j < world->col)
	{
		i = 0;
		while (i < world->row - 1)
		{
			world->line.color = 0x00FFFFFF;
			set_color_2(world, i, j);
			world->p1 = world->trans[i++][j];
			world->p2 = world->trans[i][j];
			draw_line(world);
		}
	}
}

void	put_pixel_img(t_env *world, int x, int y, int color)
{
	char	*px;
	int		p;

	if ((x > 0 && x < WIDTH) && (y > 0 && y < HEIGHT))
	{
		px = mlx_get_data_addr(world->image, &p, &p, &p);
		p = WIDTH * y * 4 + x * 4;
		px[p + 0] = get_red(color);
		px[p + 1] = get_green(color);
		px[p + 2] = get_blue(color);
	}
}

void	img_clear(t_env *world)
{
	char	*px;
	int		p;

	px = mlx_get_data_addr(world->image, &p, &p, &p);
	ft_bzero(px, 4 * WIDTH * HEIGHT);
}
