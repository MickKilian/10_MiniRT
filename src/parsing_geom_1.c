/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_geom_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 09:49:27 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/04/08 06:33:26 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

int	parse_sphere(t_rt *rt)
{
	t_vec3	q;
	double	dia;

	if (parse_dbl_vec3(rt->tp_params[++rt->tp_count], &q))
		return (1);
	else if (parse_dbl_pos(rt->tp_params[++rt->tp_count], &dia))
		return (1);
	else if (parse_color(rt->tp_params[++rt->tp_count], &rt->tp_color))
		return (1);
	rt->tp_geom = geom_sphere(sphere(q, dia / 2));
	return (0);
}

int	parse_plane(t_rt *rt)
{
	t_vec3	q;
	t_vec3	dir;

	if (parse_dbl_vec3(rt->tp_params[++rt->tp_count], &q))
		return (1);
	else if (parse_dbl_vec3_n1_1_norm(rt->tp_params[++rt->tp_count], &dir))
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
	double	dia;
	double	h;

	if (parse_dbl_vec3(rt->tp_params[++rt->tp_count], &q))
		return (1);
	else if (parse_dbl_vec3_n1_1_norm(rt->tp_params[++rt->tp_count], &dir))
		return (1);
	else if (parse_dbl_pos(rt->tp_params[++rt->tp_count], &dia))
		return (1);
	else if (parse_dbl_pos(rt->tp_params[++rt->tp_count], &h))
		return (1);
	else if (parse_color(rt->tp_params[++rt->tp_count], &rt->tp_color))
		return (1);
	rt->tp_geom = geom_cylinder(cylinder(q, dir, dia / 2, h));
	return (0);
}

int	parse_cone(t_rt *rt)
{
	t_vec3	q;
	t_vec3	dir;
	double	d_min;
	double	d_max;
	double	h;

	if (parse_dbl_vec3(rt->tp_params[++rt->tp_count], &q))
		return (1);
	else if (parse_dbl_vec3_n1_1_norm(rt->tp_params[++rt->tp_count], &dir))
		return (1);
	else if (parse_dbl_pos(rt->tp_params[++rt->tp_count], &d_min))
		return (1);
	else if (parse_dbl_pos(rt->tp_params[++rt->tp_count], &d_max))
		return (1);
	else if (parse_dbl_pos(rt->tp_params[++rt->tp_count], &h))
		return (1);
	else if (parse_color(rt->tp_params[++rt->tp_count], &rt->tp_color))
		return (1);
	rt->tp_geom = geom_cone(cone(q, vec3_scale(h, dir), d_min / 2, d_max / 2));
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
