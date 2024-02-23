/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_simple.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 03:03:50 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/02/23 14:11:02 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

void	display_vec3(const t_vec3 v)
{
	printf("(%f, %f, %f)", v.x, v.y, v.z);
}

void	display_color(t_vec3 pixel_color)
{
    printf("%d %d %d\n", (int)(255.999 * pixel_color.x), (int)(255.999 * pixel_color.y), (int)(255.999 * pixel_color.z));
}
