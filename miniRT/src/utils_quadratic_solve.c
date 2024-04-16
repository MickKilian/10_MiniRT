/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_quadratic_solve.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 01:59:43 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/03/23 06:50:25 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

bool	search_poly_root(t_h_pol *h_pol, t_itv tray, double *root)
{
	if (!solve_h_pol(h_pol))
		return (0);
	*root = h_pol->root_1;
	if (!srs(tray, *root))
	{
		*root = h_pol->root_2;
		if (!srs(tray, *root))
			return (0);
	}
	return (1);
}

bool	search_poly_root_2(t_h_pol *h_pol, t_itv tray,
		double *root_1, double *root_2)
{
	if (!solve_h_pol(h_pol))
		return (0);
	*root_1 = 0;
	*root_2 = 0;
	if (srs(tray, h_pol->root_1))
		*root_1 = h_pol->root_1;
	if (srs(tray, h_pol->root_2))
		*root_2 = h_pol->root_2;
	if (!root_1 && !root_2)
		return (0);
	return (1);
}

bool	solve_h_pol(t_h_pol *h_pol)
{
	double	discriminant;

	discriminant = h_pol->h_b * h_pol->h_b
		- h_pol->a * h_pol->c;
	if (discriminant < 0)
		return (0);
	h_pol->root_1 = (-h_pol->h_b
			- sqrt(discriminant)) / (h_pol->a);
	h_pol->root_2 = (-h_pol->h_b
			+ sqrt(discriminant)) / (h_pol->a);
	return (1);
}
