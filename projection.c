/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 15:23:08 by dzui              #+#    #+#             */
/*   Updated: 2017/02/13 15:23:10 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		make_points(t_env *w)
{
	int		i;
	int		j;

	i = 0;
	while (i < w->row)
	{
		j = 0;
		while (j < w->col)
		{
			w->pts[i][j].x = ((j + 1) - w->col / 2);
			w->pts[i][j].y = ((i + 1) - w->row / 2);
			w->pts[i][j].z = w->matrix[i][j];
			w->init[i][j] = w->pts[i][j];
			j++;
		}
		i++;
	}
}

t_point		trans_point_iso(t_point p, t_env *w)
{
	t_point	p_new;
	float	x;
	float	y;

	x = w->scale * p.x * 0.866 + w->scale * (p.y * 0.866);
	x = round_number(x);
	p_new.x = x + w->x_offset;
	y = w->scale_z * p.z + w->scale * (p.x * 0.5) - w->scale * (p.y * 0.5);
	y = round_number(y);
	p_new.y = w->y_offset - y;
	return (p_new);
}

t_point		trans_point_cab(t_point p, t_env *w)
{
	t_point	p_new;
	float	x;
	float	y;

	x = w->scale * p.x * 0.707 + w->scale * (p.y);
	x = round_number(x);
	p_new.x = x + w->x_offset;
	y = w->scale_z * p.z + w->scale * (p.x * 0.707);
	y = round_number(y);
	p_new.y = w->y_offset - y;
	return (p_new);
}

t_point		trans_point_plan(t_point p, t_env *w)
{
	t_point	p_new;
	float	x;
	float	y;

	x = w->scale * p.x * 0.707 + w->scale * (p.y * 0.707);
	x = round_number(x);
	p_new.x = x + w->x_offset;
	y = w->scale_z * p.z + w->scale * (p.x * 0.707) - w->scale * (p.y * 0.707);
	y = round_number(y);
	p_new.y = w->y_offset - y;
	return (p_new);
}

void		translate(t_env *w)
{
	int		i;
	int		j;

	i = 0;
	while (i < w->row)
	{
		j = 0;
		while (j < w->col)
		{
			if (w->projection == 0)
				w->trans[i][j] = trans_point_iso(w->pts[i][j], w);
			if (w->projection == 1)
				w->trans[i][j] = trans_point_cab(w->pts[i][j], w);
			if (w->projection == 2)
				w->trans[i][j] = trans_point_plan(w->pts[i][j], w);
			j++;
		}
		i++;
	}
}
