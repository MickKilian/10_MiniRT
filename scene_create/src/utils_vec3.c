/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_vec3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 03:03:50 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/03/16 03:31:26 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/scene_create.h"

t_vec3	new_vec3(double x, double y, double z)
{
	t_vec3	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_vec3	vec3_add2(const t_vec3 v1, const t_vec3 v2)
{
	t_vec3	v_res;

	v_res.x = v1.x + v2.x;
	v_res.y = v1.y + v2.y;
	v_res.z = v1.z + v2.z;
	return (v_res);
}

t_vec3	vec3_add3(const t_vec3 v1, const t_vec3 v2, const t_vec3 v3)
{
	t_vec3	v_res;

	v_res = vec3_add2(vec3_add2(v1, v2), v3);
	return (v_res);
}

t_vec3	vec3_substract2(const t_vec3 v1, const t_vec3 v2)
{
	t_vec3	v_res;

	v_res.x = v1.x - v2.x;
	v_res.y = v1.y - v2.y;
	v_res.z = v1.z - v2.z;
	return (v_res);
}

t_vec3	vec3_prod_comp_by_comp(const t_vec3 v1, const t_vec3 v2)
{
	t_vec3	v_res;

	v_res.x = v1.x * v2.x;
	v_res.y = v1.y * v2.y;
	v_res.z = v1.z * v2.z;
	return (v_res);
}

int	vec3_update(t_vec3 *vec, double x, double y, double z)
{
	vec->x = x;
	vec->y = y;
	vec->z = z;
	return (0);
}

t_vec3	vec3_identity_number(double t)
{
	t_vec3	v;

	v.x = t;
	v.y = t;
	v.z = t;
	return (v);
}

t_vec3	vec3_scale(double t, t_vec3 v)
{
	v.x *= t;
	v.y *= t;
	v.z *= t;
	return (v);
}

double	vec3_dot(const t_vec3 v1, const t_vec3 v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

t_vec3	vec3_cross(const t_vec3 v1, const t_vec3 v2)
{
	t_vec3	v_res;

	v_res.x = v1.y * v2.z - v1.z * v2.y;
	v_res.y = v1.z * v2.x - v1.x * v2.z;
	v_res.z = v1.x * v2.y - v1.y * v2.x;
	return (v_res);
}

t_vec3	vec3_unit(const t_vec3 v)
{
	t_vec3	v_unit;

	if (vec3_length(v) != 0.0)
		v_unit = vec3_scale(1.0 / vec3_length(v), v);
	else
		v_unit = new_vec3(0.0, 0.0, 0.0);
	return (v_unit);
}

double	vec3_length(const t_vec3 v)
{
	return (sqrt(vec3_length_squared(v)));
}

double	vec3_length_squared(const t_vec3 v)
{
	return (v.x * v.x + v.y * v.y + v.z * v.z);
}

double	vec3_index(t_vec3 v, int i)
{
	t_vec3	*temp = &v;

	return (*((double *)temp + i));
}

bool	vec3_is_nearzero(const t_vec3 vec)
{
		return (fabs(vec.x) < EPSILON) && (fabs(vec.y) < EPSILON) && (fabs(vec.z) < EPSILON);
}

t_vec3	vec3_cos(t_vec3 theta)
{
	return (new_vec3(cos(theta.x), cos(theta.y), cos(theta.z)));
}

t_vec3	vec3_sin(t_vec3 theta)
{
	return (new_vec3(sin(theta.x), sin(theta.y), sin(theta.z)));
}
