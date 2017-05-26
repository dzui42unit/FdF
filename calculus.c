/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 15:24:48 by dzui              #+#    #+#             */
/*   Updated: 2017/02/13 15:24:50 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		round_number(float number)
{
	int		dec;
	float	floating;
	int		flag;

	flag = 1;
	if (number < 0)
	{
		number *= -1;
		flag = -1;
	}
	dec = number;
	floating = number - (int)number;
	if (floating < 0.5)
		return ((int)(dec * flag));
	return ((int)((dec + 1)) * flag);
}

void	calc_x_rot(float *y, float *z, float angle)
{
	float	y_init;
	float	z_init;

	y_init = *y;
	z_init = *z;
	(*y) = y_init * cosf(angle) + (z_init) * sinf(angle);
	(*z) = (-y_init) * sinf(angle) + z_init * cosf(angle);
}

void	calc_y_rot(float *x, float *z, float angle)
{
	float	x_init;
	float	z_init;

	x_init = *x;
	z_init = *z;
	(*x) = x_init * cosf(angle) + (z_init) * sinf(angle);
	(*z) = (-x_init) * sinf(angle) + z_init * cosf(angle);
}

void	calc_z_rot(float *x, float *y, float angle)
{
	float	y_init;
	float	x_init;

	y_init = (*y);
	x_init = (*x);
	(*x) = x_init * cosf(angle) - y_init * sinf(angle);
	(*y) = x_init * sinf(angle) + y_init * cosf(angle);
}

int		**make_matrix(char **map, t_env *world)
{
	int		j;
	int		k;
	int		len;
	int		**arr;
	char	**split_str;

	arr = (int **)malloc(sizeof(int *) * world->row);
	j = 0;
	while (j < world->row)
	{
		k = -1;
		len = 0;
		split_str = ft_strsplit(map[j], ' ');
		while (split_str[len])
			len++;
		arr[j] = (int *)malloc(sizeof(int) * len);
		while (split_str[++k])
			arr[j][k] = ft_atoi(split_str[k]);
		j++;
	}
	world->col = len;
	return (arr);
}
