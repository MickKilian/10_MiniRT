/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:54:17 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/02/23 23:10:16 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

void	cam_initialize(t_rt *rt)
{
	double	viewport_height;
	double	viewport_width;
	t_vec3	viewport_u;
	t_vec3	viewport_v;
	t_vec3	viewport_upper_left;
	double	theta;
	t_vec3	look_from;
	t_vec3	look_at;
	t_vec3	vup;
	double	defocus_radius;

	if (!rt->set_algo) {
		rt->cam.samples_per_pixel = SAMPLES_PER_PIXEL;
		rt->cam.max_depth = MAX_DEPTH;
	}
	//parsed//rt->cam.background = new_vec3(0.2, 0.2, 0.2);		// Background color
	//rt->cam.vfov = 30;  // Vertical view angle (field of view) //FROM PARSING

	rt->cam.defocus_angle = 0.0;  // Variation angle of rays through each pixel
    rt->cam.focus_dist = 1;    // Distance from camera lookfrom point to plane of perfect focus

	// Camera position
	look_from = rt->cam.center;
    //look_at = new_vec3(0, 0, 1);		// Point camera is looking at ?// CAMERA DIR FROM PARSING
    look_at = vec3_add2(rt->cam.center, rt->cam.dir);		// Point camera is looking at
    vup = new_vec3(0.0, 0.0, 1.0);			// Camera-relative "up" direction

	// Viewport dimensions
	// Viewport widths less than one are ok since they are real valued.
	// We want viewport proportions to exactly match our image proportions
	// rt->cam.focal_length = vec3_length(vec3_substract2(look_from, look_at));
	//theta = deg2rad(rt->cam.vfov);
    //viewport_height = 2.0 * tan(theta / 2.0) * rt->cam.focus_dist;
	//viewport_width = viewport_height * ((double)img_width / (double)img_height);
	theta = deg2rad(rt->cam.hfov);
    viewport_width = 2.0 * tan(theta / 2.0) * rt->cam.focus_dist;
	viewport_height = viewport_width * ((double)rt->img_height / (double)rt->img_width);

	// Calculate the u,v,w unit basis vectors for the camera coordinate frame.
	rt->cam.w = vec3_unit(vec3_substract2(look_from, look_at));
	rt->cam.u = vec3_unit(vec3_cross(vup, rt->cam.w));
	rt->cam.v = vec3_cross(rt->cam.w, rt->cam.u);

	// Calculate the vectors across the horizontal and down the vertical viewport edges.
	viewport_u = vec3_scale(viewport_width, rt->cam.u);		// Vector across viewport horizontal edge
	viewport_v = vec3_scale(-viewport_height, rt->cam.v);	// Vector down viewport vertical edgw

	// Calculate the horizontal and vertical delta vectors from pixel to pixel.
	rt->cam.pixel_delta_u = vec3_scale(1.0 / rt->img_width, viewport_u);
	rt->cam.pixel_delta_v = vec3_scale(1.0 / rt->img_height, viewport_v);

	// Calculate the location of the upper left pixel.
	// viewport_upper_left = center - (focal_length * w) - viewport_u/2 - viewport_v/2;
	viewport_upper_left = vec3_add3(
			vec3_add2(rt->cam.center, vec3_scale(-rt->cam.focus_dist, rt->cam.w)),
			vec3_scale(-0.5, viewport_u),
			vec3_scale(-0.5, viewport_v));
	rt->cam.pixel00_loc = vec3_add3(
			viewport_upper_left,
			vec3_scale(0.5, rt->cam.pixel_delta_u),
			vec3_scale(0.5, rt->cam.pixel_delta_v));

	// Calculate the camera defocus disk basis vectors.
	defocus_radius = rt->cam.focus_dist * tan(deg2rad(rt->cam.defocus_angle / 2));
	rt->cam.defocus_disk_u = vec3_scale(defocus_radius, rt->cam.u);
	rt->cam.defocus_disk_v = vec3_scale(defocus_radius, rt->cam.v);
}

int	render(t_rt *rt)
{
	time_estimation(rt);
	for (int j = 0; j < rt->img_height; ++j)
	{
		printf("\rRemaining scanlines: %d ", rt->img_height - j);
		render_innerloop(rt, j);
	}
	printf("\rDone.                   \n");
	return (0);
}

int	render_innerloop(t_rt *rt, int j)
{
	t_vec3			pixel_color;

	for (int i = 0; i < rt->img_width; ++i)
	{
		pixel_color = new_vec3(0, 0, 0);
		for (int k = 0; k < rt->cam.samples_per_pixel; ++k)
		{
			pixel_color = vec3_add2(pixel_color,
					ray_color(rt, rt->cam.max_depth, get_ray(&rt->cam, i, j)));
		}
		pixel_color = vec3_scale(1.0 / (double)rt->cam.samples_per_pixel, pixel_color);
		//pixel_color = new_vec3(fmin(pixel_color.x, 1), fmin(pixel_color.y, 1), fmin(pixel_color.z, 1));
		// We apply the gamme correction to the image
		//my_mlx_pixel_put(rt->mlx.image, i, j, rgb2val(vec2rgb(pixel_color)));
		my_mlx_pixel_put(rt->mlx.image, i, j, rgb2val(vec2rgb(lin2gam_vec(pixel_color))));
	}
	return (0);
}

void	time_estimation(t_rt *rt)
{
	struct timeval	end_time, begin_time;
	int				estimated;

	estimated = 0;
	gettimeofday(&begin_time, NULL);
	render_innerloop(rt, 0);
	gettimeofday(&end_time, NULL);
	estimated = (int)((rt->img_height) * ((end_time.tv_sec - begin_time.tv_sec)
		* 1000000 + end_time.tv_usec - begin_time.tv_usec) / 1000000);
	gettimeofday(&begin_time, NULL);
	render_innerloop(rt, rt->img_height / 3);
	gettimeofday(&end_time, NULL);
	estimated += (int)((rt->img_height) * ((end_time.tv_sec - begin_time.tv_sec)
		* 1000000 + end_time.tv_usec - begin_time.tv_usec) / 1000000);
	gettimeofday(&begin_time, NULL);
	render_innerloop(rt, rt->img_height * 0.666);
	gettimeofday(&end_time, NULL);
	estimated += (int)((rt->img_height) * ((end_time.tv_sec - begin_time.tv_sec)
		* 1000000 + end_time.tv_usec - begin_time.tv_usec) / 1000000);
	printf("\rEstimated computation time: %d sec\n", estimated / 3);
}
