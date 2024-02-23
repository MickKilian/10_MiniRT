/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_diff_light.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 00:07:15 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/02/23 16:41:22 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

t_diff_light	diff_light(double ratio, t_vec3 color)
{
	t_diff_light	diff_light;

	diff_light.color = color;
	diff_light.ratio = ratio;
	return (diff_light);
}
