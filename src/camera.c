/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:54:17 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/02/20 13:36:16 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

void	cam_initialize(t_camera *cam, int img_width, int img_height)
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

	cam->samples_per_pixel = 30;
	cam->max_depth = 40;
	//parsed//cam->background = new_vec3(0.2, 0.2, 0.2);		// Background color
	//cam->vfov = 30;  // Vertical view angle (field of view) //FROM PARSING

	cam->defocus_angle = 0.0;  // Variation angle of rays through each pixel
    cam->focus_dist = 5000;    // Distance from camera lookfrom point to plane of perfect focus

	// Camera position
	//look_from = new_vec3(3, -10, 10);	// Point camera is looking from // FROM PARSING
	look_from = cam->center;
    //look_at = new_vec3(0, 0, 1);		// Point camera is looking at ?// CAMERA DIR FROM PARSING
    look_at = vec3_add2(cam->center, cam->dir);		// Point camera is looking at
    vup = new_vec3(0.0, 0.0, 1.0);			// Camera-relative "up" direction
	cam->center = look_from;

	// Viewport dimensions
	// Viewport widths less than one are ok since they are real valued.
	// We want viewport proportions to exactly match our image proportions
	// cam->focal_length = vec3_length(vec3_substract2(look_from, look_at));
	//theta = deg2rad(cam->vfov);
    //viewport_height = 2.0 * tan(theta / 2.0) * cam->focus_dist;
	//viewport_width = viewport_height * ((double)img_width / (double)img_height);
	theta = deg2rad(cam->hfov);
    viewport_width = 2.0 * tan(theta / 2.0) * cam->focus_dist;
	viewport_height = viewport_width * ((double)img_height / (double)img_width);

	// Calculate the u,v,w unit basis vectors for the camera coordinate frame.
	cam->w = vec3_unit(vec3_substract2(look_from, look_at));
	cam->u = vec3_unit(vec3_cross(vup, cam->w));
	cam->v = vec3_cross(cam->w, cam->u);

	// Calculate the vectors across the horizontal and down the vertical viewport edges.
	viewport_u = vec3_scale(viewport_width, cam->u);		// Vector across viewport horizontal edge
	viewport_v = vec3_scale(-viewport_height, cam->v);	// Vector down viewport vertical edgw

	// Calculate the horizontal and vertical delta vectors from pixel to pixel.
	cam->pixel_delta_u = vec3_scale(1.0 / img_width, viewport_u);
	cam->pixel_delta_v = vec3_scale(1.0 / img_height, viewport_v);

	// Calculate the location of the upper left pixel.
	// viewport_upper_left = center - (focal_length * w) - viewport_u/2 - viewport_v/2;
	viewport_upper_left = vec3_add3(
			vec3_add2(cam->center, vec3_scale(-cam->focus_dist, cam->w)),
			vec3_scale(-0.5, viewport_u),
			vec3_scale(-0.5, viewport_v));
	cam->pixel00_loc = vec3_add3(
			viewport_upper_left,
			vec3_scale(0.5, cam->pixel_delta_u),
			vec3_scale(0.5, cam->pixel_delta_v));

	// Calculate the camera defocus disk basis vectors.
	defocus_radius = cam->focus_dist * tan(deg2rad(cam->defocus_angle / 2));
	cam->defocus_disk_u = vec3_scale(defocus_radius, cam->u);
	cam->defocus_disk_v = vec3_scale(defocus_radius, cam->v);
}

int	render(t_rt *rt)
{
	t_vec3	pixel_color;

	// Intialization of pixel_color
	ft_bzero(&pixel_color, sizeof(t_vec3));

	// Render
	//printf("P3\n%d %d\n255\n", rt->img_width, rt->img_height);

	for (int j = 0; j < rt->img_height; ++j)
	{
		printf("\rScanlines remaining: %d ", rt->img_height - j);
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
	}
	printf("\rDone.                   \n");
	return (0);
}
