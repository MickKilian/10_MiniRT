/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 20:41:26 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/02/13 04:28:35 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

double	deg2rad(double deg)
{
	return (deg * PI / 180.0);
}

t_vec3	deg2rad_vec3(t_vec3 vec)
{
	t_vec3	new_vec;

	display_vec3(vec);
	new_vec = vec3_scale(PI / 180.0, vec);
	printf("\n");
	return (new_vec);
}

double	lin2gam_double(double linear)
{
	return sqrt(linear);
}

double	str2dbl(char *str)
{
	double	ret;
	double	dec;
	double	rank;
	double	sign;

	dec = 0.0;
	rank = 1.0;
	sign = 1.0;
	ret = (double)ft_atoi(str);
	if (*str && *str == '-')
		sign = -1.0;
	while (*str && *str != '.')
		str++;
	if (*str++ == '.')
	{
		while (*str >= '0' && *str <= '9')
		{
			rank *= 10.0;
			dec += (double)(*str - '0') / rank;
			str++;
		}
		ret += dec * sign;
	}
	return (ret);
}
