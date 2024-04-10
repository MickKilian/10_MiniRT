/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_metal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 03:22:09 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/04/09 20:54:41 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

t_metal	metal(t_vec3 color, double fuzz, double ratio)
{
	t_metal	metal;

	metal.color = color;
	metal.fuzz = fuzz;
	metal.ratio = ratio;
	return (metal);
}

t_material	*mat_metal(t_temp tp, t_metal metal)
{
	t_material	*mat;

	if (tp.mat)
		free(tp.mat);
	mat = ft_calloc(1, sizeof(t_material));
	mat->type = METAL;
	mat->color = metal.color;
	mat->light_conc = pow(1 - metal.fuzz, 4) * 248 + 2;
	mat->k_d = 1 - metal.ratio;
	mat->k_s = metal.ratio;
	mat->metal = metal;
	return (mat);
}
