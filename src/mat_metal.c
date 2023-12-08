/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_metal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 03:22:09 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/12/04 06:03:30 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ray_tracing.h"

t_metal	metal(t_vec3 color, double fuzz)
{
	t_metal	metal;

	metal.albedo = color;
	metal.fuzz  = fuzz;
	return (metal);
}
