/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_vec3_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 03:03:50 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/03/23 06:58:31 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

t_vec3	new_vec3(double x, double y, double z)
{
	t_vec3	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_vec3	vec3_add2(t_vec3 v1, t_vec3 v2)
{
	t_vec3	v_res;

	v_res.x = v1.x + v2.x;
	v_res.y = v1.y + v2.y;
	v_res.z = v1.z + v2.z;
	return (v_res);
}

t_vec3	vec3_add3(t_vec3 v1, t_vec3 v2, t_vec3 v3)
{
	t_vec3	v_res;

	v_res = vec3_add2(vec3_add2(v1, v2), v3);
	return (v_res);
}

t_vec3	vec3_sub2(t_vec3 v1, t_vec3 v2)
{
	t_vec3	v_res;

	v_res.x = v1.x - v2.x;
	v_res.y = v1.y - v2.y;
	v_res.z = v1.z - v2.z;
	return (v_res);
}

t_vec3	vec3_prd(t_vec3 v1, t_vec3 v2)
{
	t_vec3	v_res;

	v_res.x = v1.x * v2.x;
	v_res.y = v1.y * v2.y;
	v_res.z = v1.z * v2.z;
	return (v_res);
}
