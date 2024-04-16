/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_vec3_4_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 03:03:50 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/04/10 15:31:14 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt_bonus.h"

t_vec3	vec3_cos(t_vec3 theta)
{
	return (new_vec3(cos(theta.x), cos(theta.y), cos(theta.z)));
}

t_vec3	vec3_sin(t_vec3 theta)
{
	return (new_vec3(sin(theta.x), sin(theta.y), sin(theta.z)));
}

t_vec3	vec3_cpy(t_vec3 vec)
{
	return (new_vec3(vec.x, vec.y, vec.z));
}
