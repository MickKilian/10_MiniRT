/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ray_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 09:56:22 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/03/22 20:18:32 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt_bonus.h"

t_vec3	hit_pt(t_ray r, double t)
{
	return (vec3_add2(r.orig, vec3_scale(t, r.dir)));
}

t_ray	new_ray(t_vec3 orig, t_vec3 dir)
{
	t_ray	r;

	r.orig = orig;
	r.dir = dir;
	return (r);
}
