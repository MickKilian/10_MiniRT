/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 07:40:44 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/02/12 06:51:31 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

int	parse_line(t_rt *rt, char *line)
{
	 if (ft_strncmp(line, "A", 1) == 0)
		 return(parse_ambient_params(rt, line, NB_PARAMS_AMBIENT_LIGHT));
	 if (ft_strncmp(line, "L", 1) == 0)
		 return(parse_light_params(rt, line, NB_PARAMS_LIGHT));
	 if (ft_strncmp(line, "C", 1) == 0)
		 return(parse_camera_params(rt, line, NB_PARAMS_CAMERA));
	 if (ft_strncmp(line, "sp", 2) == 0)
		 return(parse_httbl_params(rt, line, SPHERE, NB_PARAMS_SPHERE));
	 if (ft_strncmp(line, "qd", 2) == 0)
		 return(parse_httbl_params(rt, line, QUAD, NB_PARAMS_QUAD));
	 if (ft_strncmp(line, "ds", 2) == 0)
		 return(parse_httbl_params(rt, line, DISC, NB_PARAMS_DISC));
	 if (ft_strncmp(line, "bx", 2) == 0)
		 return(parse_httbl_params(rt, line, BOX, NB_PARAMS_BOX));
	 if (ft_strncmp(line, "pl", 2) == 0)
		 return(parse_httbl_params(rt, line, PLANE, NB_PARAMS_PLANE));
	 if (ft_strncmp(line, "cy", 2) == 0)
		 return(parse_httbl_params(rt, line, CYLINDER, NB_PARAMS_CYLINDER));
	 if (ft_strncmp(line, "co", 2) == 0)
		 return(parse_httbl_params(rt, line, CONE, NB_PARAMS_CONE));
	 if (ft_strncmp(line, "dc", 2) == 0)
		 return(parse_httbl_params(rt, line, DIE, NB_PARAMS_DIE));
	 if (ft_strncmp(line, "sc", 2) == 0)
		 return(parse_httbl_params(rt, line, SAFETY_CONE, NB_PARAMS_SAFETY_CONE));
	return (1);
}

int	parse_httbl_params(t_rt *rt, char *line, t_geom_types geom_type, int nb_params)
{
	char	**params;

	params = ft_split(line, ' ');
	if (array_size(params) != nb_params) {
		free(params);
		return(display_error(ERR_NB_PARAMS_GEOM));
	}
	if (geom_type == SPHERE)
		return(parse_sphere(rt, params));
	if (geom_type == QUAD)
		return(parse_quad(rt, params));
	if (geom_type == DISC)
		return(parse_disc(rt, params));
	if (geom_type == BOX)
		return(parse_box(rt, params));
	if (geom_type == PLANE)
		return(parse_plane(rt, params));
	if (geom_type == CYLINDER)
		return(parse_cylinder(rt, params));
	if (geom_type == CONE)
		return(parse_cone(rt, params));
	if (geom_type == DIE)
		return(parse_die(rt, params));
	if (geom_type == SAFETY_CONE)
		return(parse_safety_cone(rt, params));
	free(params);
	return (1);
}

int	parse_dbl_vec3(char* str, t_vec3 *vec)
{
	char	**params;
	int		i;

	i = 0;
	params = ft_split(str, ',');
	while (params && params[i]) {
		if (!is_double(params[i++])) {
			free(params);
			return(display_error(ERR_FLOAT));
		}
	}
	if (array_size(params) != 3)
	{
		free(params);
		return(display_error(ERR_NB_COMPS_VEC));
	}
	vec->x = str2dbl(params[0]);
	vec->y = str2dbl(params[1]);
	vec->z = str2dbl(params[2]);
	free(params);
	return (0);
}

int	parse_dbl(char* str, double	*num)
{
	if (!is_double(str))
		return (display_error(ERR_FLOAT));
	*num = str2dbl(str);
	return (0);
}

int	parse_color(char* str, t_vec3 *color)
{
	char	**params;
	int		i;

	i = 0;
	params = ft_split(str, ',');
	while (params && params[i]) {
		if (!is_ulong(params[i++])) {
			free(params);
			return(display_error(ERR_INT));
		}
	}
	if (array_size(params) != 3)
	{
		free(params);
		return(display_error(ERR_NB_COMPS_COLOR));
	}
	color->x = ft_min(255, ft_atoi(params[0]));
	color->y = ft_min(255, ft_atoi(params[1]));
	color->z = ft_min(255, ft_atoi(params[2]));
	free(params);
	return (0);
}
