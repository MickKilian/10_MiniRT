/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_general.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 07:40:44 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/02/22 05:52:22 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

int	parse_line(t_rt *rt, char *line)
{
	rt->temp_params = ft_split(line, ' ');
	rt->p_avail = array_size(rt->temp_params);
	if (ft_strcmp(rt->temp_params[0], "R") == 0)
		return (parse_resolution_params(rt));
	else if (ft_strcmp(rt->temp_params[0], "A") == 0)
		return (parse_ambient_params(rt));
	else if (ft_strcmp(rt->temp_params[0], "L") == 0)
		return (parse_light_params(rt)
			|| parse_httbl(rt, POINT, 0));
	else if (ft_strcmp(rt->temp_params[0], "C") == 0)
		return (parse_camera_params(rt));
	else if (ft_strcmp(rt->temp_params[0], "sp") == 0)
		return (parse_httbl(rt, SPHERE, NB_PARAMS_SPHERE));
	else if (ft_strcmp(rt->temp_params[0], "qd") == 0)
		return (parse_httbl(rt, QUAD, NB_PARAMS_QUAD));
	else if (ft_strcmp(rt->temp_params[0], "ds") == 0)
		return (parse_httbl(rt, DISC, NB_PARAMS_DISC));
	else if (ft_strcmp(rt->temp_params[0], "bx") == 0)
		return (parse_httbl(rt, BOX, NB_PARAMS_BOX));
	else
		return (parse_line_cont(rt));
	return (1);
}

int	parse_line_cont(t_rt *rt)
{
	if (ft_strcmp(rt->temp_params[0], "pl") == 0)
		return (parse_httbl(rt, PLANE, NB_PARAMS_PLANE));
	else if (ft_strcmp(rt->temp_params[0], "cy") == 0)
		return (parse_httbl(rt, CYLINDER, NB_PARAMS_CYLINDER));
	else if (ft_strcmp(rt->temp_params[0], "co") == 0)
		return (parse_httbl(rt, CONE, NB_PARAMS_CONE));
	else if (ft_strcmp(rt->temp_params[0], "di") == 0)
		return (parse_httbl(rt, DIE, NB_PARAMS_DIE));
	else if (ft_strcmp(rt->temp_params[0], "sc") == 0)
		return (parse_httbl(rt, SAF_CONE, NB_PARAMS_SAF_CONE));
	else
		return (display_error_plus(ERR_INFO_TYPE, rt->temp_params[0]));
	return (1);
}

int	parse_httbl(t_rt *rt, t_geom_types geom_type, int p_expected)
{
	rt->temp_ret = 1;
	rt->p_expected = p_expected;
	if (geom_type == POINT)
	{
		rt->temp_ret = create_light_point(rt);
		if (!rt->temp_ret)
			rt->temp_mat = mat_diff_light(diff_light(rt->light.ratio,
						rt->light.color));
	}
	else
	{
		if (rt->p_avail < rt->p_expected)
		{
			free (rt->temp_params);
			return (display_error(ERR_NB_PARAMS_GEOM));
		}
		rt->temp_ret = parse_httbl_cont(rt, geom_type);
	}
	httbl_record(&rt->world, new_httbl(rt->temp_geom, rt->temp_mat));
	return (rt->temp_ret);
}

int	parse_httbl_cont(t_rt *rt, t_geom_types geom_type)
{
	if (geom_type == SPHERE)
		rt->temp_ret = parse_sphere(rt);
	else if (geom_type == QUAD)
		rt->temp_ret = parse_quad(rt);
	else if (geom_type == DISC)
		rt->temp_ret = parse_disc(rt);
	else if (geom_type == BOX)
		rt->temp_ret = parse_box(rt);
	else if (geom_type == PLANE)
		rt->temp_ret = parse_plane(rt);
	else if (geom_type == CYLINDER)
		rt->temp_ret = parse_cylinder(rt);
	else if (geom_type == CONE)
		rt->temp_ret = parse_cone(rt);
	else if (geom_type == DIE)
		rt->temp_ret = parse_die(rt);
	else if (geom_type == SAF_CONE)
		rt->temp_ret = parse_saf_cone(rt);
	if (rt->p_avail > rt->p_expected)
		rt->temp_ret = parse_extra(rt);
	if (!rt->temp_ret && !rt->temp_mat.type)
		rt->temp_mat = mat_lamber(lamber(rgb2vec(rt->temp_color)));
	free(rt->temp_params);
	return (rt->temp_ret);
}
