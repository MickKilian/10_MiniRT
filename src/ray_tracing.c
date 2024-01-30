/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 22:39:34 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/01/27 03:28:57 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//****************************************************************************//
// I learned ray tracing using the following different resources like         //
// Tuto rayTracing                                                            //
// https://raytracing.github.io/books/RayTracingInOneWeekend.html             //
//****************************************************************************//

#include "../inc/ray_tracing.h"

int	ray_tracing(t_rt *rt)
{
	// Testing of vec_operations
	// test_vec3_operations();
	// return (0);

	// Initialization for random generator
	srand(time(0));
	// Initialization of structure rt
	rt_initialize(rt);
	// Initialization of the mlx
	if (mlx_initialize(&rt->mlx, rt->img_width, rt->img_height))
		return (1);
	// Initialization op camera parameters
	cam_initialize(&rt->cam, rt->img_width, rt->img_height);
	// Initialisation of environment geometry
	world_initialize(&rt->world);

	// Render whole scene
	render(rt);

	// Show image
	image_update(&rt->mlx);
	mlx_loop(rt->mlx.ptr);

	// Free world
	free_httbls(rt->world.httbl_head);
	
	return (0);
}
