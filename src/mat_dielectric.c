/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_dielectric.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 03:19:19 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/04/08 01:27:42 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

t_dielec	dielec(t_vec3 color, double ir)
{
	t_dielec	dielec;

	dielec.color = color;
	dielec.idx_refract = ir;
	return (dielec);
}

t_material	*mat_dielec(t_dielec dielec)
{
	t_material	*mat;

	mat = ft_calloc(1, sizeof(t_material));
	mat->type = DIELECTRIC;
	mat->color = dielec.color;
	mat->light_conc = 0;
	mat->k_d = 0;
	mat->k_s = 0;
	mat->dielec = dielec;
	return (mat);
}
