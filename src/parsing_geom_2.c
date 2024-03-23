/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_geom_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 09:49:27 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/03/22 18:06:06 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

int	parse_disc(t_rt *rt)
{
	t_vec3	q;
	t_vec3	dir;
	double	rd;

	if (parse_dbl_vec3(rt->tp_params[++rt->tp_count], &q))
		return (1);
	else if (parse_dbl_vec3(rt->tp_params[++rt->tp_count], &dir))
		return (1);
	else if (parse_dbl(rt->tp_params[++rt->tp_count], &rd))
		return (1);
	else if (parse_color(rt->tp_params[++rt->tp_count], &rt->tp_color))
		return (1);
	rt->tp_geom = geom_disc(disc(q, dir, rd));
	return (0);
}

int	parse_box(t_rt *rt)
{
	t_vec3	ctr;
	t_vec3	u;
	t_vec3	v;
	t_vec3	w;

	if (parse_dbl_vec3(rt->tp_params[++rt->tp_count], &ctr))
		return (1);
	else if (parse_dbl_vec3(rt->tp_params[++rt->tp_count], &u))
		return (1);
	else if (parse_dbl_vec3(rt->tp_params[++rt->tp_count], &v))
		return (1);
	else if (parse_dbl_vec3(rt->tp_params[++rt->tp_count], &w))
		return (1);
	else if (parse_color(rt->tp_params[++rt->tp_count], &rt->tp_color))
		return (1);
	rt->tp_geom = geom_box(box(ctr, u, v, w));
	return (0);
}

int	parse_dce(t_rt *rt)
{
	t_vec3	ctr;
	t_vec3	dir_1;
	t_vec3	dir_2;
	t_vec3	dir_3;
	double	size;

	if (parse_dbl_vec3(rt->tp_params[++rt->tp_count], &ctr))
		return (1);
	else if (parse_dbl_vec3(rt->tp_params[++rt->tp_count], &dir_1))
		return (1);
	else if (parse_dbl_vec3(rt->tp_params[++rt->tp_count], &dir_2))
		return (1);
	else if (parse_dbl(rt->tp_params[++rt->tp_count], &size))
		return (1);
	else if (parse_color(rt->tp_params[++rt->tp_count], &rt->tp_color))
		return (1);
	dir_3 = vec3_cross(vec3_unit(dir_1), vec3_unit(dir_2));
	rt->tp_geom = geom_dce(box(ctr, vec3_scale(size / 2, vec3_unit(dir_1)),
				vec3_scale(size / 2, vec3_unit(dir_2)),
				vec3_scale(size / 2, vec3_unit(dir_3))));
	return (0);
}

int	parse_safe_cone(t_rt *rt)
{
	t_vec3	q;
	t_vec3	dir;
	double	h;

	if (parse_dbl_vec3(rt->tp_params[++rt->tp_count], &q))
		return (1);
	else if (parse_dbl_vec3(rt->tp_params[++rt->tp_count], &dir))
		return (1);
	else if (parse_dbl(rt->tp_params[++rt->tp_count], &h))
		return (1);
	rt->tp_geom = geom_safe_cone(safe_cone(q, vec3_unit(dir), h));
	return (0);
}
