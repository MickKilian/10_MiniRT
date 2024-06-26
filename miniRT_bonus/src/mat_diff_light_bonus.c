/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_diff_light_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 00:07:15 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/04/10 15:29:48 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt_bonus.h"

t_diff_light	diff_light(double ratio, t_vec3 color)
{
	t_diff_light	diff_light;

	diff_light.color = color;
	diff_light.ratio = ratio;
	return (diff_light);
}

t_material	*mat_diff_light(t_temp tp, t_diff_light diff_light)
{
	t_material	*mat;

	if (tp.mat)
		free(tp.mat);
	mat = ft_calloc(1, sizeof(t_material));
	mat->type = DIFF_LIGHT;
	mat->color = diff_light.color;
	mat->light_conc = 0;
	mat->k_d = 0;
	mat->k_s = 0;
	mat->diff_light = diff_light;
	return (mat);
}
