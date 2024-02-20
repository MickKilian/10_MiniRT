/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 07:40:44 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/02/20 23:16:10 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

int	parse_line(t_rt *rt, char *line)
{
	 if (ft_strncmp(line, "R", 1) == 0)
		 return(parse_resolution_params(rt, line, NB_PARAMS_RESOLUTION));
	 if (ft_strncmp(line, "A", 1) == 0)
		 return(parse_ambient_params(rt, line, NB_PARAMS_AMBIENT_LIGHT));
	 if (ft_strncmp(line, "L", 1) == 0)
		 return(parse_light_params(rt, line, NB_PARAMS_LIGHT) || parse_httbl_params(rt, line, POINT, NB_PARAMS_POINT));
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
	 if (ft_strncmp(line, "di", 2) == 0)
		 return(parse_httbl_params(rt, line, DIE, NB_PARAMS_DIE));
	 if (ft_strncmp(line, "sc", 2) == 0)
		 return(parse_httbl_params(rt, line, SAFETY_CONE, NB_PARAMS_SAFETY_CONE));
	return (1);
}

int	parse_httbl_params(t_rt *rt, char *line, t_geom_types geom_type, int nb_params)
{
	char		**params;
	t_geometry	*geom;
	t_material	*mat;
	t_vec3		*color;
	int			ret;
	int			params_count;

	ret = 1;
	geom = ft_calloc(1, sizeof(t_geometry));
	mat = ft_calloc(1, sizeof(t_material));
	color = ft_calloc(1, sizeof(t_vec3));
	params_count = nb_params;
	params = ft_split(line, ' ');
	rt->pars_tot = array_size(params);
	if (geom_type == POINT)
		ret = create_light_point(rt, geom);
	else if (rt->pars_tot < nb_params) {
		free(params);
		return(display_error(ERR_NB_PARAMS_GEOM));
	}
	if (geom_type == SPHERE)
		ret = parse_sphere(params, geom, color);
	else if (geom_type == QUAD)
		ret = parse_quad(params, geom, color);
	else if (geom_type == DISC)
		ret = parse_disc(params, geom, color);
	else if (geom_type == BOX)
		ret = parse_box(params, geom, color);
	else if (geom_type == PLANE)
		ret = parse_plane(params, geom, color);
	else if (geom_type == CYLINDER)
		ret = parse_cylinder(params, geom, color);
	else if (geom_type == CONE)
		ret = parse_cone(params, geom, color);
	else if (geom_type == DIE)
		ret = parse_die(params, geom, color);
	else if (geom_type == SAFETY_CONE)
		ret = parse_safety_cone(rt, params);
	if (rt->pars_tot > params_count)
		ret = parse_more(params, geom, mat, color, &params_count);
	if (ret == 0 && !mat->type)
		*mat = mat_lamber(lamber(rgb2vec(*color)));
	httbl_record(&rt->world, new_httbl(*geom, *mat));
	free(params);
	return (ret);
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
