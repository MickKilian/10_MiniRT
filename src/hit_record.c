/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_record.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:45:23 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/12/08 00:11:47 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ray_tracing.h"

void	set_face_normal(const t_ray r, const t_vec3 outward_normal, t_hit_rec *rec) {
	// Sets the hit record normal vector
	//  Parameter 'outward_normal' should be a unit vector
	
	rec->front_face = vec3_dot(r.dir, outward_normal) < 0;
	if (rec->front_face)
		rec->normal = outward_normal;
	else
		rec->normal = vec3_scale(-1.0, outward_normal);
}
