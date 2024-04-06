/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_patterns.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:23:39 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/04/06 11:40:20 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

bool	checkboard_zone(t_vec3 uv, double scale)
{
	uv = vec3_scale(2 * scale, uv);
	return ((int)(floor(uv.x) + floor(uv.y)) % 2);
}

bool	long_zone(t_vec3 uv, double scale)
{
	uv = vec3_scale(2 * scale, uv);
	return ((int)(floor(uv.x)) % 2);
}

bool	lat_zone(t_vec3 uv, double scale)
{
	uv = vec3_scale(2 * scale, uv);
	return ((int)(floor(uv.y)) % 2);
}

bool	spiral_zone(t_vec3 uv, double scale)
{
	uv = vec3_scale(2 * scale, uv);
	return ((int)floor(uv.x + uv.y) % 2);
}

t_vec3	spiral_colors(t_vec3 uv, double scale)
{
	(void)scale;
	return (new_vec3(ft_abs(uv.x - 0.5), uv.y, 1 - uv.y));
}

t_vec3	gradient_color_spiral(t_vec3 uv, double scale, t_itv itv)
{
	if (itv.min < 0)
	{
		itv.min += 360;
		itv.max += 360;
	}
	return (rgb2vec(hsv2rgb(vec2hsv(new_vec3(ft_modulo(
				ft_abs(2 * ft_modulo((uv.x + scale * uv.y), 1) - 1)
				* (itv.max - itv.min) / 360 + itv.min / 360 , 1), 1, 1)))));
}

t_vec3	spiral_3_colors(t_vec3 uv, double b, double scale)
{
	t_vec3	col_1;
	t_vec3	col_2;
	t_vec3	col_3;

	col_1 = rgb2vec(new_vec3(64, 149, 213));
	col_2 = rgb2vec(new_vec3(231, 190, 66));
	col_3 = rgb2vec(new_vec3(205, 43, 38));
	return (shaded_3_colors(col_1, col_2, col_3, b, ft_abs(2 * ft_modulo((uv.x + scale * uv.y), 1) - 1)));
}

t_vec3	pattern_color(bool zone_pattern, t_vec3 color_even, t_vec3 color_odd)
{
	if (zone_pattern != 0)
		return (color_odd);
	else
		return (color_even);
}

t_vec3	spiral_pattern(t_vec3 uv, double scale, t_vec3 color_even, t_vec3 color_odd)
{
	if (spiral_zone(uv, scale) != 0)
		return (color_odd);
	else
		return (color_even);
}
