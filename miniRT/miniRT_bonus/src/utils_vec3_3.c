/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_vec3_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 03:03:50 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/03/23 07:01:49 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

t_vec3	vec3_unit(t_vec3 v)
{
	t_vec3	v_unit;

	if (vec3_len(v) != 0.0)
		v_unit = vec3_scale(1.0 / vec3_len(v), v);
	else
		v_unit = new_vec3(0.0, 0.0, 0.0);
	return (v_unit);
}

double	vec3_len(t_vec3 v)
{
	return (sqrt(vec3_len_sq(v)));
}

double	vec3_len_sq(t_vec3 v)
{
	return (v.x * v.x + v.y * v.y + v.z * v.z);
}

double	vec3_index(t_vec3 v, int i)
{
	t_vec3	*temp;

	temp = &v;
	return (*((double *)temp + i));
}

bool	vec3_is_nz(t_vec3 vec)
{
	return (fabs(vec.x) < EPSILON && (fabs(vec.y) < EPSILON)
		&& (fabs(vec.z) < EPSILON));
}
