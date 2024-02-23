/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   httbl_box.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 02:57:02 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/02/23 16:39:29 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

t_box	box(const t_vec3 a, const t_vec3 b)
{
	t_box	box;

	box.a = a;
	box.b = b;
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

t_geometry	*geom_die(t_box box)
{
	t_geometry	*geom;

	geom = ft_calloc(1, sizeof(t_geometry));
	geom->type = DIE;
	geom->box = box;
	return (geom);
}
