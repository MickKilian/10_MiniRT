/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 22:51:59 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/04/08 06:56:06 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

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


t_vec3	val2rgb(int rgb)
{
	t_vec3	col;

	col.x = ((rgb >> 16) & 0xFF);
	col.y = ((rgb >> 8) & 0xFF);
	col.z = (rgb & 0xFF);
	return (col);
}

t_vec3	hsv2rgb(t_vec3 hsv)
{
	double	m;
	double	n;
	double	z;
	int		k;
	t_vec3	col;

	m = 255 * hsv.z;
	n = m * (1 - hsv.y);
	z = (m - n) * (1 - ft_abs(ft_modulo((hsv.x / 60), 2) - 1));
	z += n;
	k = hsv.x / 60 + 1;
	col.x = (k == 1 || k == 6) * m + (k == 3 || k == 4) * n
		+ (k == 2 || k == 5) * z;
	col.y = (k == 2 || k == 3) * m + (k == 5 || k == 6) * n
		+ (k == 1 || k == 4) * z;
	col.z = (k == 4 || k == 5) * m + (k == 1 || k == 2) * n
		+ (k == 3 || k == 6) * z;
	return (col);
}

t_vec3	mix_colors(t_vec3 col_1, t_vec3 col_2, double a)
{
	a = fmin(ft_abs(a), 1);
	return (vec3_add2(vec3_scale(a, col_1), vec3_scale(1 - a, col_2)));
}

t_vec3	limit_color_vec(t_vec3 col)
{
	double	factor;

	factor = ft_max3(col.x, col.y, col.z);
	if (factor > 1)
		return (vec3_scale(1 / factor, col));
	else
		return (col);
}
