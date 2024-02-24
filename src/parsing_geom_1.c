/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_geom_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 09:49:27 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/02/23 21:40:49 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

int	parse_sphere(t_rt *rt)
{
	t_vec3	q;
	double	radius;

	if (parse_dbl_vec3(rt->temp_params[1], &q))
		return (1);
	if (parse_dbl(rt->temp_params[2], &radius))
		return (1);
	if (parse_color(rt->temp_params[3], &rt->temp_color))
		return (1);
	rt->temp_geom = geom_sphere(sphere(q, radius));
	return (0);
}

int	parse_plane(t_rt *rt)
{
	t_vec3	q;
	t_vec3	dir;

	if (parse_dbl_vec3(rt->temp_params[1], &q))
		return (1);
	if (parse_dbl_vec3(rt->temp_params[2], &dir))
		return (1);
	if (parse_color(rt->temp_params[3], &rt->temp_color))
		return (1);
	rt->temp_geom = geom_plane(plane(q, dir));
	return (0);
}

int	parse_cylinder(t_rt *rt)
{
	t_vec3	q;
	t_vec3	dir;
	double	radius;
	double	height;

	if (parse_dbl_vec3(rt->temp_params[1], &q))
		return (1);
	if (parse_dbl_vec3(rt->temp_params[2], &dir))
		return (1);
	if (parse_dbl(rt->temp_params[3], &radius))
		return (1);
	if (parse_dbl(rt->temp_params[4], &height))
		return (1);
	if (parse_color(rt->temp_params[5], &rt->temp_color)) {
		return (1);
	}
	rt->temp_geom = geom_cylinder(cylinder(q, dir, radius, height));
	return (0);
}

int	parse_cone(t_rt *rt)
{
	t_vec3	q;
	t_vec3	dir;
	double	radius_min;
	double	radius_max;
	double	height;

	if (parse_dbl_vec3(rt->temp_params[1], &q))
		return (1);
	if (parse_dbl_vec3(rt->temp_params[2], &dir))
		return (1);
	if (parse_dbl(rt->temp_params[3], &radius_min))
		return (1);
	if (parse_dbl(rt->temp_params[4], &radius_max))
		return (1);
	if (parse_dbl(rt->temp_params[5], &height))
		return (1);
	if (parse_color(rt->temp_params[6], &rt->temp_color))
		return (1);
	rt->temp_geom = geom_cone(cone(q, dir, radius_min, radius_max, height));
	return (0);
}

int	parse_quad(t_rt *rt)
{
	t_vec3	q;
	t_vec3	u;
	t_vec3	v;

	if (parse_dbl_vec3(rt->temp_params[1], &q))
		return (1);
	if (parse_dbl_vec3(rt->temp_params[2], &u))
		return (1);
	if (parse_dbl_vec3(rt->temp_params[3], &v))
		return (1);
	if (parse_color(rt->temp_params[4], &rt->temp_color))
		return (1);
	rt->temp_geom = geom_quad(quad(q, u, v));
	return (0);
}
