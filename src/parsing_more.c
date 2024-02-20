/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_more.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 07:40:44 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/02/20 23:26:46 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

int	parse_more(char **params, t_geometry *geom, t_material *mat, t_vec3 *color, int *params_count)
{
	int	ret;

	if (ft_strncmp(params[*params_count], "ttr", 3) == 0)
		ret = parse_transform(params, geom, params_count);
	if (ft_strncmp(params[*params_count], "die", 3) == 0)
		ret = parse_dielectric(params, mat, color, params_count);
	if (ft_strncmp(params[*params_count], "met", 3) == 0)
		ret = parse_metal(params, mat, color, params_count);
	if (ft_strncmp(params[*params_count], "dif", 3) == 0)
		ret = parse_diff_light(params, mat, color, params_count);
	return (ret);
}

int	parse_transform(char **params, t_geometry *geom,  int *params_count)
{
	t_vec3	rot;

	if (parse_dbl_vec3(params[*params_count + 1], &geom->trans))
		return (1);
	if (parse_dbl_vec3(params[*params_count + 2], &rot))
		return (1);
	geom->theta = deg2rad_vec3(rot);
	display_vec3(geom->theta);
	printf("\n");
	*params_count += 3;
	return (0);
}

int	parse_dielectric(char **params, t_material *mat, t_vec3 *color, int *params_count) {
	double	idx_refract;

	if (parse_dbl(params[*params_count + 1], &idx_refract))
		return (1);
	*mat = mat_dielec(dielec(*color, idx_refract));
	return (0);
}

int	parse_metal(char **params, t_material *mat, t_vec3 *color, int *params_count) {
	double	fuzz;

	if (parse_dbl(params[*params_count + 1], &fuzz))
		return (1);
	*mat = mat_metal(metal(*color, fuzz));
	return (0);
}

int	parse_diff_light(char **params, t_material *mat, t_vec3 *color, int *params_count) {
	double	ratio;

	if (parse_dbl(params[*params_count + 1], &ratio))
		return (1);
	*mat = mat_diff_light(diff_light(ratio, *color));
	return (0);
}
