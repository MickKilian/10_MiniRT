/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   httbl_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 19:21:16 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/02/12 10:35:56 by mbourgeo         ###   ########.fr       */
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
