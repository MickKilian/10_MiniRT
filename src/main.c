/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 22:19:34 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/03/23 07:03:09 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//****************************************************************************//
// I learned ray tracing using the following different resources              //
// Tuto rayTracing                                                            //
// https://raytracing.github.io/books/RayTracingInOneWeekend.html             //
//****************************************************************************//

#include "../inc/mini_rt.h"

int	main(int argc, char **argv)
{
	t_rt	rt;

	ft_bzero(&rt, sizeof(t_rt));
	if (argc != 2)
		return (display_error(ERR_NB_ARGUMENTS));
	else if (open_and_read_file(&rt, argv[1]))
	{
		free_httbls(rt.world.httbl_head);
		return (1);
	}
	mini_rt(&rt);
	return (0);
}

int	mini_rt(t_rt *rt)
{
	srand(time(NULL) ^ getpid());
	rt_initialize(rt);
	if (mlx_initialize(&rt->mlx, rt->img_w, rt->img_h))
		return (1);
	cam_initialize(rt);
	world_populate(&rt->world);
	render(rt);
	image_update(&rt->mlx);
	free_httbls(rt->world.httbl_head);
	mlx_loop(rt->mlx.ptr);
	ft_exit(rt);
	return (0);
}

int	ft_exit(t_rt *rt)
{
	if (rt->mlx.ptr)
	{
		mlx_loop_end(rt->mlx.ptr);
		if (rt->mlx.image.img)
			mlx_destroy_image(rt->mlx.ptr, rt->mlx.image.img);
		if (rt->mlx.win_ptr)
			mlx_destroy_window(rt->mlx.ptr, rt->mlx.win_ptr);
		mlx_destroy_display(rt->mlx.ptr);
		free(rt->mlx.ptr);
	}
	exit(EXIT_SUCCESS);
	return (0);
}
