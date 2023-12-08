/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_diff_light.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 00:07:15 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/12/07 01:34:41 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ray_tracing.h"

t_diff_light	diff_light(t_vec3 color)
{
	t_diff_light	diff_light;

	diff_light.color = color;
	return (diff_light);
}
