/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_poly_root.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 01:59:43 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/12/08 05:46:31 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ray_tracing.h"

bool	search_poly_root(t_half_poly *half_poly, const t_interval tray, double *root)
{
	if (!solve_half_poly(half_poly))
		return (0);
	*root = half_poly->root_1;
	if (!surrounds(tray, *root))
	{
		*root = half_poly->root_2;
		if (!surrounds(tray, *root))
		return (0);
	}
	return (1);
}

bool	solve_half_poly(t_half_poly *half_poly)
{
	double	discriminant;

	discriminant = half_poly->half_b * half_poly->half_b -
		half_poly->a * half_poly->c;
	if (discriminant < 0)
		return (0);
	half_poly->root_1 = (-half_poly->half_b -
			sqrt(discriminant)) / half_poly->a;
	half_poly->root_2 = (-half_poly->half_b +
			sqrt(discriminant)) / half_poly->a;
	return (1);
}
