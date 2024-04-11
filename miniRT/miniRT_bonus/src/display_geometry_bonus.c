/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_geometry_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 03:03:50 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/03/23 09:53:41 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt_bonus.h"

void	display_geometry(t_geometry *geom)
{
	printf("   ***GEOMETRY\n");
	printf("      type : %d\n", geom->type);
	printf("      trans : ");
	display_vec3(geom->trsf.tra);
	printf("\n");
	printf("      rot_axis : ");
	display_vec3(geom->trsf.rot_ax);
	printf("\n");
	printf("      rot_angle : %f\n", rad2deg(geom->trsf.rot_an));
	if (geom->type == SPHERE)
		display_sphere(&geom->sph);
	if (geom->type == CYLINDER)
		display_cylinder(&geom->cyl);
	if (geom->type == DISC)
		display_disc(&geom->dsc);
	if (geom->type == QUAD)
		display_quad(&geom->qud);
}

void	display_sphere(t_sphere *sph)
{
	printf("      ***SPHERE\n");
	printf("         center : ");
	display_vec3(sph->ctr);
	printf("\n");
	printf("         radius : %f\n", sph->rd);
}

void	display_cylinder(t_cylinder *cyl)
{
	printf("      ***CYLINDER\n");
	printf("         center : ");
	display_vec3(cyl->ctr);
	printf("\n");
	printf("         generator : ");
	display_vec3(cyl->gen);
	printf("\n");
	printf("         radius : %f, height : %f\n", cyl->rd, cyl->h);
}

void	display_disc(t_disc *dsc)
{
	printf("      ***DISC\n");
	printf("         center : ");
	display_vec3(dsc->ctr);
	printf("\n");
	printf("         radius : %f\n", dsc->rd);
}

void	display_quad(t_quad *qud)
{
	printf("      ***QUAD\n");
	printf("         center : ");
	display_vec3(qud->ctr);
	printf("\n");
	printf("         u-vec : ");
	display_vec3(qud->u);
	printf("\n");
	printf("         v_vec : ");
	display_vec3(qud->v);
	printf("\n");
}
