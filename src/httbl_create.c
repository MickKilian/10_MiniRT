/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   httbl_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 19:21:16 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/12/08 02:28:49 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

t_httbl	*new_httbl(const t_geometry geom, const t_material mat)
{
	t_httbl	*new_httbl;

	new_httbl = ft_calloc(1, sizeof(t_httbl));
	if (!new_httbl)
		return (NULL);
	new_httbl->next = NULL;
	new_httbl->geom = geom;
	new_httbl->mat = mat;
	return (new_httbl);
}

//t_httbl	*new_httbl_plane(t_plane pln)
//{
//	t_httbl	*new_httbl;
//
//	new_httbl = ft_calloc(1, sizeof(t_httbl));
//	if (!new_httbl)
//		return (NULL);
//	new_httbl->next = NULL;
//	new_httbl->geom_type = PLANE;
//	new_httbl->pln = pln;
//	assign_default_mat(new_httbl);
//	return (new_httbl);
//}
//
//t_httbl	*new_httbl_sphere(t_sphere sph)
//{
//	t_httbl	*new_httbl;
//
//	new_httbl = ft_calloc(1, sizeof(t_httbl));
//	if (!new_httbl)
//		return (NULL);
//	new_httbl->next = NULL;
//	new_httbl->geom_type = SPHERE;
//	new_httbl->sph = sph;
//	assign_default_mat(new_httbl);
//	return (new_httbl);
//}
//
//t_httbl	*new_httbl_cylinder(t_cylinder cyl)
//{
//	t_httbl	*new_httbl;
//
//	new_httbl = ft_calloc(1, sizeof(t_httbl));
//	if (!new_httbl)
//		return (NULL);
//	new_httbl->next = NULL;
//	new_httbl->geom_type = CYLINDER;
//	new_httbl->cyl = cyl;
//	assign_default_mat(new_httbl);
//	return (new_httbl);
//}
