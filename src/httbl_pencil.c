/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   httbl_pencil.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 02:57:02 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/03/21 07:54:54 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

t_pencil	pencil(t_vec3 b_ctr, t_vec3 gen, double l)
{
	t_pencil	pnc;

	pnc.b_ctr = b_ctr;
	pnc.gen = gen;
	pnc.l = l;
	pnc.w = l * 0.08 / 3.2;
	return (pnc);
}

t_geometry	*geom_pencil(t_pencil pnc)
{
	t_geometry	*geom;

	geom = ft_calloc(1, sizeof(t_geometry));
	geom->type = PENCIL;
	geom->pnc = pnc;
	return (geom);
}
