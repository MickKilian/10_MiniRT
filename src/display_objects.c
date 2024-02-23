/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_objects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 03:03:50 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/02/23 14:11:13 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

void	display_world(t_world *world)
{
	t_httbl	*httbl;
	int	id;

	id = 0;
	httbl = world->httbl_head;
	while (httbl)
	{
		display_httbl(httbl, id);
		httbl = httbl->next;
		id++;
	}
}

void	display_httbl(t_httbl *httbl, int id)
{
	printf("***OBJECT : %d\n", id);
	display_geometry(&httbl->geom);
	display_material(&httbl->mat);

}

void	display_geometry(t_geometry *geom)
{
	printf("   ***GEOMETRY\n");
	printf("      type : %d\n", geom->type);
	printf("      trans : ");
	display_vec3(geom->trans);
	printf("\n");
	printf("      theta : ");
	display_vec3(geom->theta);
	printf("\n");
	if (geom->type == SPHERE)
		display_sphere(&geom->sph);
}

void	display_material(t_material *mat)
{
	printf("   ***MATERIAL\n");
	printf("      type : %d\n", mat->type);
}

void	display_sphere(t_sphere *sph)
{
	printf("      ***SPHERE\n");
	printf("         center : ");
	display_vec3(sph->center);
	printf("\n");
	printf("         radius : %f\n", sph->radius);
}
