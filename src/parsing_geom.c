/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_geom.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 09:49:27 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/02/13 02:41:36 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

int	parse_sphere(char **params, t_geometry *geom, t_vec3 *color)
{
	t_vec3	q;
	double	radius;

	if (parse_dbl_vec3(params[1], &q))
		return (1);
	if (parse_dbl(params[2], &radius))
		return (1);
	if (parse_color(params[3], color))
		return (1);
	*geom = geom_sphere(sphere(q, radius));
	//httbl_record(&rt->world, new_httbl(geom_sphere(sphere(q, radius)), mat_lamber(lamber(rgb2vec(color)))));
	return (0);
}

int	parse_plane(char **params, t_geometry *geom, t_vec3 *color)
{
	t_vec3	q;
	t_vec3	dir;

	if (parse_dbl_vec3(params[1], &q))
		return (1);
	if (parse_dbl_vec3(params[2], &dir))
		return (1);
	if (parse_color(params[3], color))
		return (1);
	*geom = geom_plane(plane(q, dir));
	//httbl_addback(&rt->world, new_httbl(geom_plane(plane(q, dir)), mat_lamber(lamber(rgb2vec(color)))));
	return (0);
}

int	parse_cylinder(char **params, t_geometry *geom, t_vec3 *color)
{
	t_vec3	q;
	t_vec3	dir;
	double	radius;
	double	height;

	if (parse_dbl_vec3(params[1], &q))
		return (1);
	if (parse_dbl_vec3(params[2], &dir))
		return (1);
	if (parse_dbl(params[3], &radius))
		return (1);
	if (parse_dbl(params[4], &height))
		return (1);
	if (parse_color(params[5], color))
		return (1);
	*geom = geom_cylinder(cylinder(q, dir, radius, height));
	//httbl_record(&rt->world, new_httbl(geom_cylinder(cylinder(q, dir, radius, height)), mat_metal(metal(rgb2vec(color), 0))));
	return (0);
}

int	parse_cone(char **params, t_geometry *geom, t_vec3 *color)
{
	t_vec3	q;
	t_vec3	dir;
	double	radius_min;
	double	radius_max;
	double	height;

	if (parse_dbl_vec3(params[1], &q))
		return (1);
	if (parse_dbl_vec3(params[2], &dir))
		return (1);
	if (parse_dbl(params[3], &radius_min))
		return (1);
	if (parse_dbl(params[4], &radius_max))
		return (1);
	if (parse_dbl(params[5], &height))
		return (1);
	if (parse_color(params[6], color))
		return (1);
	*geom = geom_cone(cone(q, dir, radius_min, radius_max, height));
	//httbl_record(&rt->world, new_httbl(geom_cone(cone(q, dir, radius_min, radius_max, height)), mat_lamber(lamber(rgb2vec(color)))));
	return (0);
}

int	parse_quad(char **params, t_geometry *geom, t_vec3 *color)
{
	t_vec3	q;
	t_vec3	u;
	t_vec3	v;

	if (parse_dbl_vec3(params[1], &q))
		return (1);
	if (parse_dbl_vec3(params[2], &u))
		return (1);
	if (parse_dbl_vec3(params[3], &v))
		return (1);
	if (parse_color(params[4], color))
		return (1);
	*geom = geom_quad(quad(q, u, v));
	//httbl_record(&rt->world, new_httbl(geom_quad(quad(q, u, v)), mat_lamber(lamber(rgb2vec(color)))));
	return (0);
}

int	parse_disc(char **params, t_geometry *geom, t_vec3 *color)
{
	t_vec3	q;
	t_vec3	dir;
	double	radius;

	if (parse_dbl_vec3(params[1], &q))
		return (1);
	if (parse_dbl_vec3(params[2], &dir))
		return (1);
	if (parse_dbl(params[3], &radius))
		return (1);
	if (parse_color(params[4], color))
		return (1);
	*geom = geom_disc(disc(q, dir, radius));
	//httbl_record(&rt->world, new_httbl(geom_disc(disc(q, dir, radius)), mat_lamber(lamber(rgb2vec(color)))));
	return (0);
}

int	parse_box(char **params, t_geometry *geom, t_vec3 *color)
{
	t_vec3	q;
	t_vec3	r;

	if (parse_dbl_vec3(params[1], &q))
		return (1);
	if (parse_dbl_vec3(params[2], &r))
		return (1);
	if (parse_color(params[3], color))
		return (1);
	*geom = geom_box(box(q, r));
	//httbl_record(&rt->world, new_httbl(geom_box(box(q, r)), mat_lamber(lamber(rgb2vec(color)))));
	return (0);
}

int	parse_die(char **params, t_geometry *geom, t_vec3 *color)
{
	t_vec3	q;
	t_vec3	r;

	if (parse_dbl_vec3(params[1], &q))
		return (1);
	if (parse_dbl_vec3(params[2], &r))
		return (1);
	if (parse_color(params[3], color))
		return (1);
	*geom = geom_die(box(q, r));
	//httbl_record(&rt->world, new_httbl(geom_die(box(q, r)), mat_lamber(lamber(rgb2vec(color)))));
	return (0);
}

int	parse_safety_cone(t_rt *rt, char **params)
{
	t_vec3	q;
	t_vec3	dir;
	double	height;

	if (parse_dbl_vec3(params[1], &q))
		return (1);
	if (parse_dbl_vec3(params[2], &dir))
		return (1);
	if (parse_dbl(params[3], &height))
		return (1);
	create_safety_cone(&rt->world, q, dir, height);
	return (0);
}
