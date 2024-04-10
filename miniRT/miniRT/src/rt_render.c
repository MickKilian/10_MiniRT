/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:54:17 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/04/10 11:40:23 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

int	render(t_rt *rt)
{
	int	j;

	j = 0;
	time_estimation(rt);
	progress_compute(rt, j);
	while (j < rt->img.h)
	{
		while (j < rt->img.h && j / 10 == (j + 1) / 10)
		{
			render_innerloop(rt, j);
			j++;
		}
		progress_compute(rt, j);
		render_innerloop(rt, j);
		j++;
	}
	printf("\rDone in  : \n");
	rt->mlx.win_ptr = mlx_new_window(rt->mlx.ptr, rt->img.w, rt->img.h,
			"42 mini_rt");
	mlx_key_hook(rt->mlx.win_ptr, on_key_press, &rt->mlx.ptr);
	mlx_hook(rt->mlx.win_ptr, 17, 0L, mlx_loop_end, rt->mlx.ptr);
	image_update(&rt->mlx, rt->img);
	return (0);
}

void	progress_compute(t_rt *rt, int j)
{
	struct timeval	cur_time;
	int				cur_sec;

	gettimeofday(&cur_time, NULL);
	cur_sec = (int)(((cur_time.tv_sec - rt->begin_time.tv_sec) * 1000000
				+ cur_time.tv_usec - rt->begin_time.tv_usec) / 1000000);
	if (j > rt->img.h * 0.75)
		rt->estim_sec = cur_sec * rt->img.h / j;
	printf("\rProgress : %d / %d sec ", cur_sec, rt->estim_sec);
	fflush(stdout);
}

int	render_innerloop(t_rt *rt, int j)
{
	t_vec3	pixel_color;
	int		i;
	int		k;

	i = 0;
	while (i < rt->img.w)
	{
		pixel_color = new_vec3(0, 0, 0);
		k = 0;
		while (k < rt->spp)
		{
			pixel_color = vec3_add2(pixel_color,
					ray_color(rt, rt->max_depth, get_ray(&rt->cam, i, j)));
			k++;
		}
		pixel_color = vec3_scale(1.0 / (double)rt->spp, pixel_color);
		pixel_color = limit_color_vec(pixel_color);
		my_mlx_pixel_put(rt->img, i, j,
			rgb2val(vec2rgb(lin2gam_vec(pixel_color))));
		i++;
	}
	return (0);
}

void	time_estimation(t_rt *rt)
{
	struct timeval	e_time;
	struct timeval	b_time;
	int				estim;

	estim = 0;
	gettimeofday(&rt->begin_time, NULL);
	gettimeofday(&b_time, NULL);
	render_innerloop(rt, 0);
	gettimeofday(&e_time, NULL);
	estim = (int)((rt->img.h) * ((e_time.tv_sec - b_time.tv_sec)
				* 1000000 + e_time.tv_usec - b_time.tv_usec) / 1000000);
	gettimeofday(&b_time, NULL);
	render_innerloop(rt, rt->img.h / 3);
	gettimeofday(&e_time, NULL);
	estim += (int)((rt->img.h) * ((e_time.tv_sec - b_time.tv_sec)
				* 1000000 + e_time.tv_usec - b_time.tv_usec) / 1000000);
	gettimeofday(&b_time, NULL);
	render_innerloop(rt, rt->img.h * 0.666);
	gettimeofday(&e_time, NULL);
	estim += (int)((rt->img.h) * ((e_time.tv_sec - b_time.tv_sec)
				* 1000000 + e_time.tv_usec - b_time.tv_usec) / 1000000);
	rt->estim_sec = estim / 3;
}
