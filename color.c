/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 15:18:34 by dzui              #+#    #+#             */
/*   Updated: 2017/02/13 15:18:37 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_color_1(t_env *world, int i, int j)
{
	if ((world->init[i][j].z < world->init[i][j + 1].z)
		|| (world->init[i][j].z > world->init[i][j + 1].z))
	{
		if (world->color == 0)
			world->line.color = 0x0646464;
		if (world->color == 1)
			world->line.color = 0x00000FF;
		if (world->color == 2)
			world->line.color = 0x000FF00;
		if (world->color == 3)
			world->line.color = 0x0FF0000;
	}
}

void	set_color_2(t_env *world, int i, int j)
{
	if ((world->init[i][j].z < world->init[i + 1][j].z)
		|| (world->init[i][j].z > world->init[i + 1][j].z))
	{
		if (world->color == 0)
			world->line.color = 0x0646464;
		if (world->color == 1)
			world->line.color = 0x00000FF;
		if (world->color == 2)
			world->line.color = 0x000FF00;
		if (world->color == 3)
			world->line.color = 0x0FF0000;
	}
}

int		get_red(int color)
{
	return ((int)(((color >> 16) & 0xFF)));
}

int		get_green(int color)
{
	return ((int)(((color >> 8) & 0xFF)));
}

int		get_blue(int color)
{
	return ((int)((color) & 0xFF));
}
