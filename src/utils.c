/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 20:41:26 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/12/07 08:43:02 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ray_tracing.h"

double	ft_min(const double n1, const double n2)
{
	if (n1 <= n2)
		return n1;
	else
		return n2;
}

double	deg2rad(double deg)
{
	return (deg * PI / 180.0);
}

double	lin2gam_double(double linear)
{
	return sqrt(linear);
}
