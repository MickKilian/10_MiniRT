/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   httbl_safe_cone.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 02:57:02 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/03/21 07:55:26 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

t_safe_cone	safe_cone(t_vec3 b_ctr, t_vec3 gen, double h)
{
	t_safe_cone	sfc;

	sfc.b_ctr = b_ctr;
	sfc.gen = gen;
	sfc.h = h;
	sfc.r_max = h / 4;
	sfc.r_min = h / 20;
	sfc.r_step = (sfc.r_max - sfc.r_min) / 5;
	return (sfc);
}

t_geometry	*geom_safe_cone(t_safe_cone sfc)
{
	t_geometry	*geom;

	geom = ft_calloc(1, sizeof(t_geometry));
	geom->type = SAFE_CONE;
	geom->sfc = sfc;
	return (geom);
}
