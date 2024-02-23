/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   httbl_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 19:21:16 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/02/23 14:58:38 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

t_httbl	*new_httbl(const t_geometry geom, const t_material mat)
{
	t_httbl	*new_httbl;

	new_httbl = ft_calloc(1, sizeof(t_httbl));
	printf("first creates : \n");
	display_vec3(new_httbl->geom.theta);
	printf("\n");
	display_vec3(geom.theta);
	printf("\n");
	if (!new_httbl)
		return (NULL);
	new_httbl->next = NULL;
	new_httbl->geom = geom;
	new_httbl->mat = mat;
	return (new_httbl);
}
