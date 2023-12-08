/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 07:40:44 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/12/08 10:26:48 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ray_tracing.h"

int	parse_line(t_rt *rt, char *line)
{
	 if (ft_strncmp(line, "A", 1) == 0)
		 return(parse_ambient_params(rt, line));
	 if (ft_strncmp(line, "L", 1) == 0)
		 return(parse_light_params(rt, line));
	 if (ft_strncmp(line, "C", 1) == 0)
		 return(parse_camera_params(rt, line));
	 if (ft_strncmp(line, "sp", 2) == 0)
		 return(parse_httbl_params(rt, line, SPHERE));
	 if (ft_strncmp(line, "pl", 2) == 0)
		 return(parse_httbl_params(rt, line, PLANE));
	 if (ft_strncmp(line, "cy", 2) == 0)
		 return(parse_httbl_params(rt, line, CYLINDER));
	return (1);
}

int	parse_httbl_params(t_rt *rt, char *line, t_geom_types geom_type)
{
	char	**params;

	params = ft_split(line, ' ');
	if (geom_type == SPHERE)
		return(parse_sphere(rt, params));
	if (geom_type == PLANE)
		return(parse_plane(rt, params));
	if (geom_type == CYLINDER)
		return(parse_cylinder(rt, params));
	free(params);
	return (1);
}
