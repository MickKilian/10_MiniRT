/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_general.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 07:40:44 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/04/09 00:18:32 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

int	parse_line(t_rt *rt, char *line)
{
	rt_re_init(rt);
	rt->tp.params = ft_split(line, ' ');
	rt->tp.avail = array_size(rt->tp.params) - 1;
	if (ft_strcmp(rt->tp.params[rt->tp.count], "R") == 0)
		rt->tp.ret = parse_resolution_params(rt);
	else if (ft_strcmp(rt->tp.params[rt->tp.count], "P") == 0)
		rt->tp.ret = parse_algo_params(rt);
	else if (ft_strcmp(rt->tp.params[rt->tp.count], "A") == 0)
		rt->tp.ret = parse_ambient_params(rt);
	else if (ft_strcmp(rt->tp.params[rt->tp.count], "L") == 0)
		rt->tp.ret = parse_light_params(rt);
	else if (ft_strcmp(rt->tp.params[rt->tp.count], "C") == 0)
		rt->tp.ret = parse_camera_params(rt);
	else
		parse_line_cont(rt);
	while (!rt->tp.ret && rt->tp.count < rt->tp.avail)
		rt->tp.ret = parse_extra(rt);
	if (!rt->tp.ret && rt->tp.geom)
	{
		mat_finalize(rt);
		httbl_create(rt);
	}
	if (rt->tp.ret)
		free_tp(rt->tp);
	if (rt->tp.params)
		free_split_vec(rt->tp.params);
	return (rt->tp.ret);
}

void	parse_line_cont(t_rt *rt)
{
	if (ft_strcmp(rt->tp.params[rt->tp.count], "sp") == 0)
		rt->tp.ret = parse_httbl(rt, SPHERE, NB_PARAMS_SPHERE);
	else if (ft_strcmp(rt->tp.params[rt->tp.count], "qd") == 0)
		rt->tp.ret = parse_httbl(rt, QUAD, NB_PARAMS_QUAD);
	else if (ft_strcmp(rt->tp.params[rt->tp.count], "ds") == 0)
		rt->tp.ret = parse_httbl(rt, DISC, NB_PARAMS_DISC);
	else if (ft_strcmp(rt->tp.params[rt->tp.count], "bx") == 0)
		rt->tp.ret = parse_httbl(rt, BOX, NB_PARAMS_BOX);
	else if (ft_strcmp(rt->tp.params[rt->tp.count], "pl") == 0)
		rt->tp.ret = parse_httbl(rt, PLANE, NB_PARAMS_PLANE);
	else if (ft_strcmp(rt->tp.params[rt->tp.count], "cy") == 0)
		rt->tp.ret = parse_httbl(rt, CYLINDER, NB_PARAMS_CYLINDER);
	else if (ft_strcmp(rt->tp.params[rt->tp.count], "co") == 0)
		rt->tp.ret = parse_httbl(rt, CONE, NB_PARAMS_CONE);
	else if (ft_strcmp(rt->tp.params[rt->tp.count], "di") == 0)
		rt->tp.ret = parse_httbl(rt, DICE, NB_PARAMS_DICE);
	else if (ft_strcmp(rt->tp.params[rt->tp.count], "sc") == 0)
		rt->tp.ret = parse_httbl(rt, SAFE_CONE, NB_PARAMS_SAFE_CONE);
	else
		rt->tp.ret = display_error_plus(ERR_INFO_TYPE,
				rt->tp.params[rt->tp.count]);
}

int	parse_httbl(t_rt *rt, t_geom_types geom_type, int expect)
{
	if (check_nb_params(rt, expect,
			get_error_message(rt->tp.params[rt->tp.count])))
		return (1);
	else
		parse_httbl_cont(rt, geom_type);
	return (rt->tp.ret);
}

void	parse_httbl_cont(t_rt *rt, t_geom_types geom_type)
{
	if (geom_type == SPHERE)
		rt->tp.ret = parse_sphere(rt);
	else if (geom_type == QUAD)
		rt->tp.ret = parse_quad(rt);
	else if (geom_type == DISC)
		rt->tp.ret = parse_disc(rt);
	else if (geom_type == BOX)
		rt->tp.ret = parse_box(rt);
	else if (geom_type == PLANE)
		rt->tp.ret = parse_plane(rt);
	else if (geom_type == CYLINDER)
		rt->tp.ret = parse_cylinder(rt);
	else if (geom_type == CONE)
		rt->tp.ret = parse_cone(rt);
	else if (geom_type == DICE)
		rt->tp.ret = parse_dce(rt);
	else if (geom_type == SAFE_CONE)
		rt->tp.ret = parse_safe_cone(rt);
	else if (geom_type == PENCIL)
		rt->tp.ret = parse_pencil(rt);
	else
		rt->tp.ret = display_error_plus(ERR_GEOM_TYPE,
				ft_itoa(geom_type));
}
