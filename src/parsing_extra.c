/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_extra.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 07:40:44 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/02/23 16:45:33 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

int	parse_extra(t_rt *rt)
{
	int	ret;

	if (ft_strcmp(rt->temp_params[rt->p_count], "ttr") == 0)
		ret = parse_transform(rt);
	if (ft_strcmp(rt->temp_params[rt->p_count], "die") == 0)
		ret = parse_dielectric(rt);
	if (ft_strcmp(rt->temp_params[rt->p_count], "met") == 0)
		ret = parse_metal(rt);
	if (ft_strcmp(rt->temp_params[rt->p_count], "dif") == 0)
		ret = parse_diff_light(rt);
	return (ret);
}

int	parse_transform(t_rt *rt)
{
	t_vec3	rot;

	if (parse_dbl_vec3(rt->temp_params[rt->p_count + 1], &rt->temp_geom->trans))
		return (1);
	if (parse_dbl_vec3(rt->temp_params[rt->p_count + 2], &rot))
		return (1);
	rt->temp_geom->theta = deg2rad_vec3(rot);
	rt->p_count += 3;
	return (0);
}

int	parse_dielectric(t_rt *rt)
{
	double	idx_refract;

	if (parse_dbl(rt->temp_params[rt->p_count + 1], &idx_refract))
		return (1);
	rt->temp_mat = mat_dielec(dielec(rt->temp_color, idx_refract));
	return (0);
}

int	parse_metal(t_rt *rt)
{
	double	fuzz;

	if (parse_dbl(rt->temp_params[rt->p_count + 1], &fuzz))
		return (1);
	rt->temp_mat = mat_metal(metal(rt->temp_color, fuzz));
	return (0);
}

int	parse_diff_light(t_rt *rt)
{
	double	ratio;

	if (parse_dbl(rt->temp_params[rt->p_count + 1], &ratio))
		return (1);
	rt->temp_mat = mat_diff_light(diff_light(ratio, rt->temp_color));
	return (0);
}
