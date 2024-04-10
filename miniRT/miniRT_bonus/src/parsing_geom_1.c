/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_geom_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 09:49:27 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/04/09 01:36:16 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

int	parse_sphere(t_rt *rt)
{
	t_vec3	q;
	double	dia;

	if (parse_dbl_vec3(rt->tp.params[++rt->tp.count], &q))
		return (1);
	else if (parse_dbl_pos(rt->tp.params[++rt->tp.count], &dia))
		return (1);
	else if (parse_color(rt->tp.params[++rt->tp.count], &rt->tp.color))
		return (1);
	rt->tp.geom = geom_sphere(sphere(q, dia / 2));
	return (0);
}

int	parse_plane(t_rt *rt)
{
	t_vec3	q;
	t_vec3	dir;

	if (parse_dbl_vec3(rt->tp.params[++rt->tp.count], &q))
		return (1);
	else if (parse_dbl_vec3_n1_1_norm(rt->tp.params[++rt->tp.count], &dir))
		return (1);
	else if (parse_color(rt->tp.params[++rt->tp.count], &rt->tp.color))
		return (1);
	rt->tp.geom = geom_plane(plane(q, dir));
	return (0);
}

int	parse_cylinder(t_rt *rt)
{
	t_vec3	q;
	t_vec3	dir;
	double	dia;
	double	h;

	if (parse_dbl_vec3(rt->tp.params[++rt->tp.count], &q))
		return (1);
	else if (parse_dbl_vec3_n1_1_norm(rt->tp.params[++rt->tp.count], &dir))
		return (1);
	else if (parse_dbl_pos(rt->tp.params[++rt->tp.count], &dia))
		return (1);
	else if (parse_dbl_pos(rt->tp.params[++rt->tp.count], &h))
		return (1);
	else if (parse_color(rt->tp.params[++rt->tp.count], &rt->tp.color))
		return (1);
	rt->tp.geom = geom_cylinder(cylinder(q, dir, dia / 2, h));
	return (0);
}

int	parse_cone(t_rt *rt)
{
	t_vec3	q;
	t_vec3	dir;
	double	d_max;
	double	d_min;
	double	h;

	if (parse_dbl_vec3(rt->tp.params[++rt->tp.count], &q))
		return (1);
	else if (parse_dbl_vec3_n1_1_norm(rt->tp.params[++rt->tp.count], &dir))
		return (1);
	else if (parse_dbl_pos(rt->tp.params[++rt->tp.count], &d_max))
		return (1);
	else if (parse_dbl_pos(rt->tp.params[++rt->tp.count], &d_min))
		return (1);
	else if (parse_dbl_pos(rt->tp.params[++rt->tp.count], &h))
		return (1);
	else if (parse_color(rt->tp.params[++rt->tp.count], &rt->tp.color))
		return (1);
	else if (d_min == d_max)
		return (display_error(ERR_DIAS_CONE));
	else if (d_min > d_max)
		return (display_error(ERR_DIAS_ORDER_CONE));
	rt->tp.geom = geom_cone(cone(q, vec3_scale(h, dir), d_max / 2, d_min / 2));
	return (0);
}

int	parse_quad(t_rt *rt)
{
	t_vec3	q;
	t_vec3	u;
	t_vec3	v;

	if (parse_dbl_vec3(rt->tp.params[++rt->tp.count], &q))
		return (1);
	else if (parse_dbl_vec3(rt->tp.params[++rt->tp.count], &u))
		return (1);
	else if (parse_dbl_vec3(rt->tp.params[++rt->tp.count], &v))
		return (1);
	else if (parse_color(rt->tp.params[++rt->tp.count], &rt->tp.color))
		return (1);
	rt->tp.geom = geom_quad(quad(q, u, v));
	return (0);
}
