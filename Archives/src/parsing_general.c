/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_general.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 07:40:44 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/03/28 01:58:25 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

int	parse_line(t_rt *rt, char *line)
{
	rt_re_init(rt);
	rt->tp_params = ft_split(line, ' ');
	rt->tp_avail = array_size(rt->tp_params) - 1;
	if (ft_strcmp(rt->tp_params[rt->tp_count], "R") == 0)
		rt->tp_ret = parse_resolution_params(rt);
	else if (ft_strcmp(rt->tp_params[rt->tp_count], "P") == 0)
		rt->tp_ret = parse_algo_params(rt);
	else if (ft_strcmp(rt->tp_params[rt->tp_count], "A") == 0)
		rt->tp_ret = parse_ambient_params(rt);
	else if (ft_strcmp(rt->tp_params[rt->tp_count], "L") == 0)
		rt->tp_ret = parse_light_params(rt);
	else if (ft_strcmp(rt->tp_params[rt->tp_count], "C") == 0)
		rt->tp_ret = parse_camera_params(rt);
	else
		parse_line_cont(rt);
	while (!rt->tp_ret && rt->tp_count < rt->tp_avail)
		rt->tp_ret = parse_extra(rt);
	if (!rt->tp_ret && rt->tp_geom)
	{
		mat_finalize(rt);
		httbl_create(rt);
	}
	if (rt->tp_params)
		free_split_vec(rt->tp_params);
	return (rt->tp_ret);
}

void	parse_line_cont(t_rt *rt)
{
	if (ft_strcmp(rt->tp_params[rt->tp_count], "sp") == 0)
		rt->tp_ret = parse_httbl(rt, SPHERE, NB_PARAMS_SPHERE);
	else if (ft_strcmp(rt->tp_params[rt->tp_count], "qd") == 0)
		rt->tp_ret = parse_httbl(rt, QUAD, NB_PARAMS_QUAD);
	else if (ft_strcmp(rt->tp_params[rt->tp_count], "ds") == 0)
		rt->tp_ret = parse_httbl(rt, DISC, NB_PARAMS_DISC);
	else if (ft_strcmp(rt->tp_params[rt->tp_count], "bx") == 0)
		rt->tp_ret = parse_httbl(rt, BOX, NB_PARAMS_BOX);
	else if (ft_strcmp(rt->tp_params[rt->tp_count], "pl") == 0)
		rt->tp_ret = parse_httbl(rt, PLANE, NB_PARAMS_PLANE);
	else if (ft_strcmp(rt->tp_params[rt->tp_count], "cy") == 0)
		rt->tp_ret = parse_httbl(rt, CYLINDER, NB_PARAMS_CYLINDER);
	else if (ft_strcmp(rt->tp_params[rt->tp_count], "co") == 0)
		rt->tp_ret = parse_httbl(rt, CONE, NB_PARAMS_CONE);
	else if (ft_strcmp(rt->tp_params[rt->tp_count], "di") == 0)
		rt->tp_ret = parse_httbl(rt, DICE, NB_PARAMS_DICE);
	else if (ft_strcmp(rt->tp_params[rt->tp_count], "sc") == 0)
		rt->tp_ret = parse_httbl(rt, SAFE_CONE, NB_PARAMS_SAFE_CONE);
	else
		rt->tp_ret = display_error_plus(ERR_INFO_TYPE,
				rt->tp_params[rt->tp_count]);
}

int	parse_httbl(t_rt *rt, t_geom_types geom_type, int expect)
{
	if (check_nb_params(rt, expect,
			get_error_message(rt->tp_params[rt->tp_count])))
		return (1);
	else
		parse_httbl_cont(rt, geom_type);
	return (rt->tp_ret);
}

void	parse_httbl_cont(t_rt *rt, t_geom_types geom_type)
{
	if (geom_type == SPHERE)
		rt->tp_ret = parse_sphere(rt);
	else if (geom_type == QUAD)
		rt->tp_ret = parse_quad(rt);
	else if (geom_type == DISC)
		rt->tp_ret = parse_disc(rt);
	else if (geom_type == BOX)
		rt->tp_ret = parse_box(rt);
	else if (geom_type == PLANE)
		rt->tp_ret = parse_plane(rt);
	else if (geom_type == CYLINDER)
		rt->tp_ret = parse_cylinder(rt);
	else if (geom_type == CONE)
		rt->tp_ret = parse_cone(rt);
	else if (geom_type == DICE)
		rt->tp_ret = parse_dce(rt);
	else if (geom_type == SAFE_CONE)
		rt->tp_ret = parse_safe_cone(rt);
	else if (geom_type == PENCIL)
		rt->tp_ret = parse_pencil(rt);
	else
		rt->tp_ret = display_error_plus(ERR_GEOM_TYPE,
				ft_itoa(geom_type));
}
