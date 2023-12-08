/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometries.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 05:39:27 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/12/08 03:10:23 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ray_tracing.h"

t_geometry	geom_plane(t_plane pln)
{
	t_geometry	geom;

	geom.type = PLANE;
	geom.offset = new_vec3(0.0, 0.0, 0.0);
	geom.theta = new_vec3(0, 0, 0);
	geom.pln = pln;
	return (geom);
}

t_geometry	geom_quad(t_quad qud)
{
	t_geometry	geom;

	geom.type = QUAD;
	geom.offset = new_vec3(0.0, 0.0, 0.0);
	geom.theta = new_vec3(0, 0, 0);
	geom.qud = qud;
	return (geom);
}

t_geometry	geom_disc(t_disc dsc)
{
	t_geometry	geom;

	geom.type = DISC;
	geom.offset = new_vec3(0.0, 0.0, 0.0);
	geom.theta = new_vec3(0, 0, 0);
	geom.dsc = dsc;
	return (geom);
}

t_geometry	geom_box(t_box box)
{
	t_geometry	geom;

	geom.type = BOX;
	geom.offset = new_vec3(0.0, 0.0, 0.0);
	geom.theta = new_vec3(0, 0, 0);
	geom.box = box;
	return (geom);
}

t_geometry	geom_sphere(t_sphere sph)
{
	t_geometry	geom;

	geom.type = SPHERE;
	geom.offset = new_vec3(0.0, 0.0, 0.0);
	geom.theta = new_vec3(0, 0, 0);
	geom.sph = sph;
	return (geom);
}

t_geometry	geom_cylinder(t_cylinder cyl)
{
	t_geometry	geom;

	geom.type = CYLINDER;
	geom.offset = new_vec3(0.0, 0.0, 0.0);
	geom.theta = new_vec3(0, 0, 0);
	geom.cyl = cyl;
	return (geom);
}
