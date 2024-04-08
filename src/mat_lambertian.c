/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_lambertian.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 03:18:48 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/04/08 01:28:18 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

t_lamber	lamber(t_vec3 color)
{
	t_lamber	lamber;

	lamber.color = color;
	return (lamber);
}

t_material	*mat_lamber(t_lamber lamber)
{
	t_material	*mat;

	mat = ft_calloc(1, sizeof(t_material));
	mat->type = LAMBERTIAN;
	mat->color = lamber.color;
	mat->light_conc = 0;
	mat->k_d = 1;
	mat->k_s = 0;
	mat->lamber = lamber;
	return (mat);
}
