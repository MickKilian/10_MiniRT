/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_interval_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 01:29:53 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/04/10 15:32:43 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

t_itv	itv(double min, double max)
{
	t_itv	itv;

	itv.min = ft_min(min, max);
	itv.max = ft_max(min, max);
	return (itv);
}

t_itv	itv_span(double min, double max, double span)
{
	double	ctr;

	ctr = (min + max) / 2;
	return (itv(ctr - span / 2, ctr + span / 2));
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
