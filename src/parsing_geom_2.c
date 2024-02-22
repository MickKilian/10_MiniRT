/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_geom_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 09:49:27 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/02/22 05:57:14 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

int	parse_disc(t_rt *rt)
{
	t_vec3	q;
	t_vec3	dir;
	double	radius;

	if (parse_dbl_vec3(rt->temp_params[1], &q))
		return (1);
	if (parse_dbl_vec3(rt->temp_params[2], &dir))
		return (1);
	if (parse_dbl(rt->temp_params[3], &radius))
		return (1);
	if (parse_color(rt->temp_params[4], &rt->temp_color))
		return (1);
	rt->temp_geom = geom_disc(disc(q, dir, radius));
	return (0);
}

int	parse_box(t_rt *rt)
{
	t_vec3	q;
	t_vec3	r;

	if (parse_dbl_vec3(rt->temp_params[1], &q))
		return (1);
	if (parse_dbl_vec3(rt->temp_params[2], &r))
		return (1);
	if (parse_color(rt->temp_params[3], &rt->temp_color))
		return (1);
	rt->temp_geom = geom_box(box(q, r));
	return (0);
}

int	parse_die(t_rt *rt)
{
	t_vec3	q;
	t_vec3	r;

	if (parse_dbl_vec3(rt->temp_params[1], &q))
		return (1);
	if (parse_dbl_vec3(rt->temp_params[2], &r))
		return (1);
	if (parse_color(rt->temp_params[3], &rt->temp_color))
		return (1);
	rt->temp_geom = geom_die(box(q, r));
	return (0);
}

int	parse_saf_cone(t_rt *rt)
{
	t_vec3	q;
	t_vec3	dir;
	double	height;

	if (parse_dbl_vec3(rt->temp_params[1], &q))
		return (1);
	if (parse_dbl_vec3(rt->temp_params[2], &dir))
		return (1);
	if (parse_dbl(rt->temp_params[3], &height))
		return (1);
	create_saf_cone(&rt->world, q, dir, height);
	return (0);
}

int	create_light_point(t_rt *rt)
{
	rt->temp_geom = geom_point(point(rt->light.pos));
	return (0);
}
