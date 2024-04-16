/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_colors_1_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 22:51:59 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/04/10 11:10:22 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt_bonus.h"

t_vec3	vec2rgb(const t_vec3 col)
{
	t_vec3	col_rgb;

	col_rgb.x = (int)(255.999 * col.x);
	col_rgb.y = (int)(255.999 * col.y);
	col_rgb.z = (int)(255.999 * col.z);
	return (col_rgb);
}

t_vec3	vec2hsv(t_vec3 col)
{
	t_vec3	hsv;
	double	cmin;
	double	cmax;
	double	delta;

	cmin = ft_min3(col.x, col.y, col.z);
	cmax = ft_max3(col.x, col.y, col.z);
	delta = cmax - cmin;
	if (delta == 0)
		hsv.x = 0;
	else if (cmax == col.x)
		hsv.x = 60 * ft_modulo((col.y - col.z) / delta, 6);
	else if (cmax == col.y)
		hsv.x = 60 * (((col.z - col.x) / delta) + 2);
	else
		hsv.x = 60 * (((col.x - col.y) / delta) + 4);
	if (cmax == 0)
		hsv.y = 0;
	else
		hsv.y = delta / cmax;
	hsv.z = cmax;
	return (hsv);
}

t_vec3	rgb2vec(const t_vec3 col)
{
	t_vec3	col_rgb;

	col_rgb.x = (double)(col.x / 255);
	col_rgb.y = (double)(col.y / 255);
	col_rgb.z = (double)(col.z / 255);
	return (col_rgb);
}

t_vec3	lin2gam_vec(const t_vec3 lin)
{
	t_vec3	gamma;

	gamma.x = lin2gam_double(lin.x);
	gamma.y = lin2gam_double(lin.y);
	gamma.z = lin2gam_double(lin.z);
	return (gamma);
}

double	rgb2val(const t_vec3 col)
{
	double	val;

	val = 0 << 24 | (int)col.x << 16
		| (int)col.y << 8 | (int)col.z;
	return (val);
}
