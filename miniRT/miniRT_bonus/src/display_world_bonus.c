/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_world_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 03:03:50 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/03/21 00:27:00 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt_bonus.h"

void	display_world(t_world *world)
{
	t_httbl	*httbl;
	int		id;

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
	display_geometry(httbl->geom);
	display_material(httbl->mat);
}
