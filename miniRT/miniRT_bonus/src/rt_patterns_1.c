/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_patterns_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:23:39 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/04/09 19:25:48 by mbourgeo         ###   ########.fr       */
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
