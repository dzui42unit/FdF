/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 15:20:55 by dzui              #+#    #+#             */
/*   Updated: 2017/02/13 15:20:57 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	x_rotation(t_env *world, float angle)
{
	int		i;
	int		j;

	i = 0;
	while (i < world->row)
	{
		j = 0;
		while (j < world->col)
		{
			calc_x_rot(&(world->pts[i][j].y), &(world->pts[i][j].z), angle);
			j++;
		}
		i++;
	}
}

void	y_rotation(t_env *world, float angle)
{
	int		i;
	int		j;

	i = 0;
	while (i < world->row)
	{
		j = 0;
		while (j < world->col)
		{
			calc_y_rot(&(world->pts[i][j].x), &(world->pts[i][j].z), angle);
			j++;
		}
		i++;
	}
}

void	z_rotation(t_env *world, float angle)
{
	int		i;
	int		j;

	i = 0;
	while (i < world->row)
	{
		j = 0;
		while (j < world->col)
		{
			calc_z_rot(&(world->pts[i][j].x), &(world->pts[i][j].y), angle);
			j++;
		}
		i++;
	}
}
