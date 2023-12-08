/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interval.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 01:29:53 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/12/08 00:52:28 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ray_tracing.h"

t_interval	interval(double min, double max)
{
	t_interval	intrvl;

	intrvl.min = fmin(min, max);
	intrvl.max = fmax(min, max);
	return(intrvl);
}

bool	contains(t_interval intrvl, double x)
{
	return (intrvl.min <= x && x <= intrvl.max);
}

bool	surrounds(t_interval intrvl, double x)
{
	return (intrvl.min < x && x < intrvl.max);
}

double	clamp(t_interval intrvl, double x)
{
	if (x < intrvl.min)
		return intrvl.min;
	else if (x > intrvl.max)
		return intrvl.max;
	return x;
}
