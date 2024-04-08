/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_material.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 07:40:44 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/03/27 12:19:14 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

int	parse_dielectric(t_rt *rt)
{
	double	idx_refract;

	if (check_nb_params(rt, NB_PARAMS_DIELECTRIC, ERR_PARAMS_DIELECTRIC))
		return (1);
	else if (parse_dbl(rt->tp_params[++rt->tp_count], &idx_refract))
		return (1);
	rt->tp_mat = mat_dielec(dielec(rgb2vec(rt->tp_color), idx_refract));
	return (0);
}

int	parse_metal(t_rt *rt)
{
	double	fuzz;

	if (check_nb_params(rt, NB_PARAMS_METAL, ERR_PARAMS_METAL))
		return (1);
	else if (parse_dbl(rt->tp_params[++rt->tp_count], &fuzz))
		return (1);
	rt->tp_mat = mat_metal(metal(rgb2vec(rt->tp_color), fuzz));
	return (0);
}

int	parse_diff_light(t_rt *rt)
{
	double	ratio;

	if (check_nb_params(rt, NB_PARAMS_DIFF_LIGHT, ERR_PARAMS_DIFF_LIGHT))
		return (1);
	else if (parse_dbl(rt->tp_params[++rt->tp_count], &ratio))
		return (1);
	rt->tp_mat = mat_diff_light(diff_light(ratio, rgb2vec(rt->tp_color)));
	return (0);
}


