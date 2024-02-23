/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_metal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 03:22:09 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/02/23 16:41:40 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

t_metal	metal(t_vec3 color, double fuzz)
{
	t_metal	metal;

	metal.color = color;
	metal.fuzz  = fuzz;
	return (metal);
}
