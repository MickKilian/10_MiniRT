/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_patterns.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:23:39 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/04/08 11:02:20 by mbourgeo         ###   ########.fr       */
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

t_vec3	gradient_color_spiral(t_vec3 uv, double scale, t_vec3 col)
{
	t_vec3	hsv;
	t_itv	itv;

	hsv = vec2hsv(col);
	itv = itv_span(hsv.x, hsv.x, 60);
	if (itv.min < 0)
	{
		itv.min += 360;
		itv.max += 360;
	}
	return (rgb2vec(hsv2rgb(new_vec3(ft_modulo(
				ft_abs(2 * ft_modulo((uv.x + scale * uv.y), 1) - 1)
				* (itv.max - itv.min) + itv.min, 360), hsv.y, hsv.z))));
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
