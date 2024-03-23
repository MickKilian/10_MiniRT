/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_simple.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 03:03:50 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/03/22 13:32:47 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

void	display_vec3(t_vec3 v)
{
	printf("(%f, %f, %f)", v.x, v.y, v.z);
}

void	display_color(t_vec3 color)
{
	printf("%d %d %d\n", (int)(255.999 * color.x),
		(int)(255.999 * color.y),
		(int)(255.999 * color.z));
}
