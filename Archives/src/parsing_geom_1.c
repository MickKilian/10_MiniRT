/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_geom_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 09:49:27 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/03/23 07:04:16 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

int	parse_sphere(t_rt *rt)
{
	t_vec3	q;
	double	rd;

	if (parse_dbl_vec3(rt->tp_params[++rt->tp_count], &q))
		return (1);
	else if (parse_dbl(rt->tp_params[++rt->tp_count], &rd))
		return (1);
	else if (parse_color(rt->tp_params[++rt->tp_count], &rt->tp_color))
		return (1);
	rt->tp_geom = geom_sphere(sphere(q, rd));
	return (0);
}

int	parse_plane(t_rt *rt)
{
	t_vec3	q;
	t_vec3	dir;

	if (parse_dbl_vec3(rt->tp_params[++rt->tp_count], &q))
		return (1);
	else if (parse_dbl_vec3(rt->tp_params[++rt->tp_count], &dir))
		return (1);
	else if (parse_color(rt->tp_params[++rt->tp_count], &rt->tp_color))
		return (1);
	rt->tp_geom = geom_plane(plane(q, dir));
	return (0);
}

int	parse_cylinder(t_rt *rt)
{
	t_vec3	q;
	t_vec3	dir;
	double	rd;
	double	h;

	if (parse_dbl_vec3(rt->tp_params[++rt->tp_count], &q))
		return (1);
	else if (parse_dbl_vec3(rt->tp_params[++rt->tp_count], &dir))
		return (1);
	else if (parse_dbl(rt->tp_params[++rt->tp_count], &rd))
		return (1);
	else if (parse_dbl(rt->tp_params[++rt->tp_count], &h))
		return (1);
	else if (parse_color(rt->tp_params[++rt->tp_count], &rt->tp_color))
		return (1);
	rt->tp_geom = geom_cylinder(cylinder(q, dir, rd, h));
	return (0);
}

int	parse_cone(t_rt *rt)
{
	t_vec3	q;
	t_vec3	dir;
	double	r_min;
	double	r_max;
	double	h;

	if (parse_dbl_vec3(rt->tp_params[++rt->tp_count], &q))
		return (1);
	else if (parse_dbl_vec3(rt->tp_params[++rt->tp_count], &dir))
		return (1);
	else if (parse_dbl(rt->tp_params[++rt->tp_count], &r_min))
		return (1);
	else if (parse_dbl(rt->tp_params[++rt->tp_count], &r_max))
		return (1);
	else if (parse_dbl(rt->tp_params[++rt->tp_count], &h))
		return (1);
	else if (parse_color(rt->tp_params[++rt->tp_count], &rt->tp_color))
		return (1);
	rt->tp_geom = geom_cone(cone(q, vec3_scale(h, dir), r_min, r_max));
	return (0);
}

int	parse_quad(t_rt *rt)
{
	t_vec3	q;
	t_vec3	u;
	t_vec3	v;

	if (parse_dbl_vec3(rt->tp_params[++rt->tp_count], &q))
		return (1);
	else if (parse_dbl_vec3(rt->tp_params[++rt->tp_count], &u))
		return (1);
	else if (parse_dbl_vec3(rt->tp_params[++rt->tp_count], &v))
		return (1);
	else if (parse_color(rt->tp_params[++rt->tp_count], &rt->tp_color))
		return (1);
	rt->tp_geom = geom_quad(quad(q, u, v));
	return (0);
}
