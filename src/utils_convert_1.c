/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_convert_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 20:41:26 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/03/23 06:35:21 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

double	deg2rad(double deg)
{
	return (deg * PI / 180.0);
}

double	rad2deg(double rad)
{
	return (rad * 180.0 / PI);
}

t_vec3	deg2rad_vec3(t_vec3 vec)
{
	t_vec3	new_vec;

	new_vec = vec3_scale(PI / 180.0, vec);
	return (new_vec);
}

double	lin2gam_double(double linear)
{
	return (sqrt(linear));
}
