/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometries.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 05:39:27 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/02/15 23:40:32 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

t_geometry	geom_plane(t_plane pln)
{
	t_geometry	geom;

	geom.type = PLANE;
	geom.pln = pln;
	return (geom);
}

t_geometry	geom_quad(t_quad qud)
{
	t_geometry	geom;

	geom.type = QUAD;
	geom.qud = qud;
	return (geom);
}

t_geometry	geom_disc(t_disc dsc)
{
	t_geometry	geom;

	geom.type = DISC;
	geom.dsc = dsc;
	return (geom);
}

t_geometry	geom_box(t_box box)
{
	t_geometry	geom;

	geom.type = BOX;
	geom.box = box;
	return (geom);
}

t_geometry	geom_die(t_box box)
{
	t_geometry	geom;

	geom.type = DIE;
	geom.box = box;
	return (geom);
}

t_geometry	geom_sphere(t_sphere sph)
{
	t_geometry	geom;

	geom.type = SPHERE;
	geom.sph = sph;
	return (geom);
}

t_geometry	geom_cylinder(t_cylinder cyl)
{
	t_geometry	geom;

	geom.type = CYLINDER;
	geom.trans = cyl.base_center;
	geom.theta = new_vec3(-atan2(cyl.generator.y, cyl.generator.z),
			atan2(cyl.generator.x, cyl.generator.z),
			0);
	geom.cyl = cyl;
	geom.cyl.base_center = new_vec3(0, 0, 0);
	geom.cyl.generator = new_vec3(0, 0, 1.0);
	return (geom);
}

t_geometry	geom_cone(t_cone con)
{
	t_geometry	geom;

	geom.type = CONE;
	geom.trans = con.base_center;
	geom.theta = new_vec3(-atan2(con.generator.y, con.generator.z),
			atan2(con.generator.x, con.generator.z),
			0);
	geom.con = con;
	geom.con.base_center = new_vec3(0, 0, 0);
	geom.con.tip = new_vec3(0, 0, -con.radius_min / (con.radius_max - con.radius_min) * con.height);
	geom.con.generator = new_vec3(0, 0, 1.0);
	return (geom);
}
