/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_convert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 22:51:59 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/12/08 11:19:38 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

t_vec3	vec2rgb(const t_vec3 color)
{
	t_vec3	color_rgb;

	color_rgb.x = (int)(255.999 * color.x);
	color_rgb.y = (int)(255.999 * color.y);
	color_rgb.z = (int)(255.999 * color.z);
	return (color_rgb);
}

t_vec3	rgb2vec(const t_vec3 color)
{
	t_vec3	color_rgb;

	color_rgb.x = (double)(color.x / 255);
	color_rgb.y = (double)(color.y / 255);
	color_rgb.z = (double)(color.z / 255);
	return (color_rgb);
}

t_vec3	lin2gam_vec(const t_vec3 lin)
{
	t_vec3	gamma;

	gamma.x = lin2gam_double(lin.x);
	gamma.y = lin2gam_double(lin.y);
	gamma.z = lin2gam_double(lin.z);
	return (gamma);
}

double	rgb2val(const t_vec3 color)
{
	double	val;

	val = 0 << 24 | (int)color.x << 16
		| (int)color.y << 8 | (int)color.z;
	return (val);
}

/*
int	val2rgb(t_vec3 *color)
{
	color->rgb[0] = ((color->val >> 24) & 0xFF);
	color->rgb[1] = ((color->val >> 16) & 0xFF);
	color->rgb[2] = ((color->val >> 8) & 0xFF);
	color->rgb[3] = ((color->val) & 0xFF);
	return (0);
}

int	thsv2rgb(t_vec3 *c)
{
	double	m;
	double	n;
	double	z;
	int		k;

	m = 255 * c->thsv[3];
	n = m * (1 - c->thsv[2]);
	z = (m - n) * (1 - ft_abs(ft_modulo((c->thsv[1] / 60), 2) - 1));
	z += n;
	k = c->thsv[1] / 60 + 1;
	c->rgb[0] = c->thsv[0];
	c->rgb[1] = (k == 1 || k == 6) * m + (k == 3 || k == 4) * n
		+ (k == 2 || k == 5) * z;
	c->rgb[2] = (k == 2 || k == 3) * m + (k == 5 || k == 6) * n
		+ (k == 1 || k == 4) * z;
	c->rgb[3] = (k == 4 || k == 5) * m + (k == 1 || k == 2) * n
		+ (k == 3 || k == 6) * z;
	rgb2val(c);
	return (0);
}
*/
