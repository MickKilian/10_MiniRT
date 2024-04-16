/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_interval_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 01:29:53 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/04/10 15:33:02 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

double	clamp(t_itv itv, double x)
{
	if (x < itv.min)
		return (itv.min);
	else if (x > itv.max)
		return (itv.max);
	return (x);
}
