/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 03:03:50 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/12/07 06:15:54 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ray_tracing.h"

t_vec3	new_vec3(double x, double y, double z)
{
	t_vec3	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

//int	edit_vec3(t_vec3 *v, double x, double y, double z)
//{
//	v->x = x;
//	v->y = y;
//	v->z = z;
//	return (0);
//}

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

//int	/unitvec_add_in(t_vec3 *v3, const t_vec3 *v1, const t_vec3 *v2)
//{
//	v3->x = v1->x + v2->x;
//	v3->y = v1->y + v2->y;
//	v3->z = v1->z + v2->z;
//	return (0);
//}

t_vec3	vec3_substract2(const t_vec3 v1, const t_vec3 v2)
{
	t_vec3	v_res;

	v_res.x = v1.x - v2.x;
	v_res.y = v1.y - v2.y;
	v_res.z = v1.z - v2.z;
	return (v_res);
}

//int	vec_substract_in(t_vec3 *v3, const t_vec3 *v1, const t_vec3 *v2)
//{
//	v3->x = v1->x - v2->x;
//	v3->y = v1->y - v2->y;
//	v3->z = v1->z - v2->z;
//	return (0);
//}

t_vec3	vec3_prod_comp_by_comp(const t_vec3 v1, const t_vec3 v2)
{
	t_vec3	v_res;

	v_res.x = v1.x * v2.x;
	v_res.y = v1.y * v2.y;
	v_res.z = v1.z * v2.z;
	return (v_res);
}

//int	vec_prod_2vec_comp_by_comp_in(t_vec3 *v3, const t_vec3 *v1, const t_vec3 *v2)
//{
//	v3->x = v1->x * v2->x;
//	v3->y = v1->y * v2->y;
//	v3->z = v1->z * v2->z;
//	return (0);
//}

t_vec3	vec3_identity_number(double t)
{
	t_vec3	v;

	v.x = t;
	v.y = t;
	v.z = t;
	return (v);
}

//int	vec_identity_number_in(t_vec3 *v, double t)
//{
//	v->x = t;
//	v->y = t;
//	v->z = t;
//	return (0);
//}

//t_vec3	vec3_prod_number(const t_vec3 *v, double t)
//{
//	t_vec3	v_res;
//
//	v_res.x = v->x * t;
//	v_res.y = v->y * t;
//	v_res.z = v->z * t;
//	return (v_res);
//}

//int	vec_prod_number_in(t_vec3 *v, double t)
//{
//	v->x *= t;
//	v->y *= t;
//	v->z *= t;
//	return (0);
//}

t_vec3	vec3_scale(double t, t_vec3 v)
{
	v.x *= t;
	v.y *= t;
	v.z *= t;
	return (v);
}

//int	vec_number_prod_in(double t, t_vec3 *v)
//{
//	vec_prod_number_in(v, t);
//	return (0);
//}

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

//int	vec_cross_in(t_vec3 *v3, const t_vec3 *v1, const t_vec3 *v2)
//{
//	v3->x = v1->y * v2->z - v1->z * v2->y;
//	v3->y = v1->z * v2->x - v1->x * v2->z;
//	v3->z = v1->x * v2->y - v1->y * v2->x;
//	return (0);
//}

t_vec3	vec3_unit(const t_vec3 v)
{
	t_vec3	v_unit;

	if (vec3_length(v) != 0.0)
		v_unit = vec3_scale(1.0 / vec3_length(v), v);
	else
		v_unit = new_vec3(0.0, 0.0, 0.0);
	return (v_unit);
}

//int	vec_unit_in(t_vec3 *v)
//{
//	if (vec_length(v))
//		vec_scale_in(vec3_length(v), v);
//	return (0);
//}

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

int	display_vec3(const t_vec3 v)
{
	printf("(%f, %f, %f)", v.x, v.y, v.z);
	return (0);
}

//compute a vec from 2 points
//t_vec3	vec3_2points(const t_vec3 orig, const t_vec3 end)
//{
//	t_vec3	vec;
//
//	vec.x = end.x - orig.x;
//	vec.y = end.y - orig.y;
//	vec.z = end.z - orig.z;
//	return (vec);
//}

bool	near_zero(const t_vec3 vec)
{
		// Return true if the vector is close to zero in all dimensions.
		double s = 0.000000001;
		return (fabs(vec.x) < s) && (fabs(vec.y) < s) && (fabs(vec.z) < s);
}

t_vec3	vec3_cos(t_vec3 theta)
{
	return (new_vec3(cos(theta.x), cos(theta.y), cos(theta.z)));
}

t_vec3	vec3_sin(t_vec3 theta)
{
	return (new_vec3(sin(theta.x), sin(theta.y), sin(theta.z)));
}
