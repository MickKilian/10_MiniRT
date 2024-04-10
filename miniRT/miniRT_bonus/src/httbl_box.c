/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   httbl_box.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 02:57:02 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/03/21 07:54:20 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

t_box	box(t_vec3 ctr, t_vec3 u, t_vec3 v, t_vec3 w)
{
	t_box	box;

	box.ctr = ctr;
	box.u = u;
	box.v = v;
	box.w = w;
	return (box);
}

t_geometry	*geom_box(t_box box)
{
	t_geometry	*geom;

	geom = ft_calloc(1, sizeof(t_geometry));
	geom->type = BOX;
	geom->box = box;
	return (geom);
}
