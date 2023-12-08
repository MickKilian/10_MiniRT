/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 07:26:39 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/12/02 04:50:09 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ray_tracing.h"

void	write_color(t_vec3 pixel_color)
{
    // Write the translated [0,255] value of each color component.
    printf("%d %d %d\n", (int)(255.999 * pixel_color.x), (int)(255.999 * pixel_color.y), (int)(255.999 * pixel_color.z));
}
