/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_interval.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 01:29:53 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/03/23 06:38:54 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

t_itv	itv(double min, double max)
{
	t_itv	itv;

	itv.min = fmin(min, max);
	itv.max = fmax(min, max);
	return (itv);
}

bool	cts(t_itv itv, double x)
{
	return (itv.min <= x && x <= itv.max);
}

bool	srs(t_itv itv, double x)
{
	return (itv.min < x && x < itv.max);
}

int	sts(t_itv itv, double x)
{
	if (x < itv.min)
		return (-1);
	if (x > itv.max)
		return (1);
	return (0);
}

double	clamp(t_itv itv, double x)
{
	if (x < itv.min)
		return (itv.min);
	else if (x > itv.max)
		return (itv.max);
	return (x);
}
