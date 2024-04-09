/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geom_map_coord_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 09:42:04 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/04/09 14:59:49 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

void	set_map_coord_con(t_hit_rec *rec, t_vec3 ctr, double h)
{
	double	phi;
	t_vec3	unit_vec;

	unit_vec = vec3_unit(vec3_sub2(new_vec3(rec->p.x, rec->p.y, 0), new_vec3(ctr.x, ctr.y, 0)));
	phi = atan2(-unit_vec.y, unit_vec.x) + PI;
	phi = ft_modulo(phi + rec->mat_rot_an, 2 * PI);
	rec->uv = new_vec3(phi / (2 * PI), (rec->p.z - ctr.z) / h, 0);
	rec->uv_cyl = rec->uv;
}
