/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_geom_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 09:49:27 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/04/08 23:56:14 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

int	parse_disc(t_rt *rt)
{
	t_vec3	q;
	t_vec3	dir;
	double	dia;

	if (parse_dbl_vec3(rt->tp.params[++rt->tp.count], &q))
		return (1);
	else if (parse_dbl_vec3(rt->tp.params[++rt->tp.count], &dir))
		return (1);
	else if (parse_dbl_pos(rt->tp.params[++rt->tp.count], &dia))
		return (1);
	else if (parse_color(rt->tp.params[++rt->tp.count], &rt->tp.color))
		return (1);
	rt->tp.geom = geom_disc(disc(q, dir, dia / 2));
	return (0);
}

int	parse_box(t_rt *rt)
{
	t_vec3	ctr;
	t_vec3	u;
	t_vec3	v;
	t_vec3	w;

	if (parse_dbl_vec3(rt->tp.params[++rt->tp.count], &ctr))
		return (1);
	else if (parse_dbl_vec3(rt->tp.params[++rt->tp.count], &u))
		return (1);
	else if (parse_dbl_vec3(rt->tp.params[++rt->tp.count], &v))
		return (1);
	else if (parse_dbl_vec3(rt->tp.params[++rt->tp.count], &w))
		return (1);
	else if (parse_color(rt->tp.params[++rt->tp.count], &rt->tp.color))
		return (1);
	rt->tp.geom = geom_box(box(ctr, u, v, w));
	return (0);
}

int	parse_dce(t_rt *rt)
{
	t_vec3	ctr;
	t_vec3	dir_1;
	t_vec3	dir_2;
	t_vec3	dir_3;
	double	size;

	if (parse_dbl_vec3(rt->tp.params[++rt->tp.count], &ctr))
		return (1);
	else if (parse_dbl_vec3(rt->tp.params[++rt->tp.count], &dir_1))
		return (1);
	else if (parse_dbl_vec3(rt->tp.params[++rt->tp.count], &dir_2))
		return (1);
	else if (parse_dbl_pos(rt->tp.params[++rt->tp.count], &size))
		return (1);
	else if (parse_color(rt->tp.params[++rt->tp.count], &rt->tp.color))
		return (1);
	dir_3 = vec3_cross(vec3_unit(dir_1), vec3_unit(dir_2));
	rt->tp.geom = geom_dce(box(ctr, vec3_scale(size / 2, vec3_unit(dir_1)),
				vec3_scale(size / 2, vec3_unit(dir_2)),
				vec3_scale(size / 2, vec3_unit(dir_3))));
	return (0);
}

int	parse_safe_cone(t_rt *rt)
{
	t_vec3	q;
	t_vec3	dir;
	double	h;

	if (parse_dbl_vec3(rt->tp.params[++rt->tp.count], &q))
		return (1);
	else if (parse_dbl_vec3(rt->tp.params[++rt->tp.count], &dir))
		return (1);
	else if (parse_dbl_pos(rt->tp.params[++rt->tp.count], &h))
		return (1);
	rt->tp.geom = geom_safe_cone(safe_cone(q, vec3_unit(dir), h));
	return (0);
}
