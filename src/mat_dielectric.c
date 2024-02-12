/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_dielectric.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 03:19:19 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/12/04 06:03:33 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

t_dielec	dielec(t_vec3 color, double ir)
{
	t_dielec	dielec;

	dielec.albedo = color;
	dielec.idx_refract = ir;
	return (dielec);
}
