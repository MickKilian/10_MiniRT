/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geom_basic_rotate_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 09:42:04 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/03/23 09:40:42 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt_bonus.h"

t_vec3	rot_v(t_vec3 orig, t_vec3 axis, double theta)
{
	t_vec3	rot;
	double	c;
	double	s;

	if (vec3_len(axis) == 0 || theta == 0)
		return (orig);
	c = cos(theta);
	s = sin(theta);
	rot.x = (axis.x * axis.x * (1.0 - c) + 1.0 * c) * orig.x
		+ (axis.y * axis.x * (1.0 - c) - axis.z * s) * orig.y
		+ (axis.z * axis.x * (1.0 - c) + axis.y * s) * orig.z;
	rot.y = (axis.x * axis.y * (1.0 - c) + axis.z * s) * orig.x
		+ (axis.y * axis.y * (1.0 - c) + 1.0 * c) * orig.y
		+ (axis.z * axis.y * (1.0 - c) - axis.x * s) * orig.z;
	rot.z = (axis.x * axis.z * (1.0 - c) - axis.y * s) * orig.x
		+ (axis.y * axis.z * (1.0 - c) + axis.x * s) * orig.y
		+ (axis.z * axis.z * (1.0 - c) + 1.0 * c) * orig.z;
	return (rot);
}

void	rot_1v(t_trsf trsf, t_vec3 *u1)
{
	*u1 = rot_v(*u1, trsf.rot_ax, trsf.rot_an);
}

void	rot_2v(t_trsf trsf, t_vec3 *u1, t_vec3 *u2)
{
	*u1 = rot_v(*u1, trsf.rot_ax, trsf.rot_an);
	*u2 = rot_v(*u2, trsf.rot_ax, trsf.rot_an);
}

void	rot_3v(t_trsf trsf, t_vec3 *u1, t_vec3 *u2, t_vec3 *u3)
{
	*u1 = rot_v(*u1, trsf.rot_ax, trsf.rot_an);
	*u2 = rot_v(*u2, trsf.rot_ax, trsf.rot_an);
	*u3 = rot_v(*u3, trsf.rot_ax, trsf.rot_an);
}

t_ray	rot_r(t_ray r, t_vec3 v, double a)
{
	return (new_ray(rot_v(r.orig, v, a), rot_v(r.dir, v, a)));
}
