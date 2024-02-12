/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:23:39 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/02/09 08:58:14 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

int	world_initialize(t_world *world)
{
	//Parameters
	//
	// IMAGE_WIDTH 1000
	// cam->samples_per_pixel = 100;
	// cam->max_depth = 50;
	// cam->background = new_vec3(0.7, 0.6, 0.5);		// Background color
	// cam->vfov = 40;  // Vertical view 5ngle (field of view)

	// cam->defocus_angle = 0.0;  // Variation angle of rays through each pixel
	// cam->focus_dist = 5;    // Distance from camera lookfrom point to plane of perfect focus

	// // Camera position
	// look_from = new_vec3(2, -11, 4.2);	// Point camera is looking from
	// look_at = new_vec3(2, 0, 1);		// Point camera is looking at
	// vup = new_vec3(0.0, 0.0, 1.0);			// Camera-relative "up" direction

	// Rotate quads
	//geom.theta = new_vec3(0, 0, deg2rad(20));

	httbl_addback(world, new_httbl(geom_sphere(sphere(new_vec3(0, 0, -1000), 1000)), mat_metal(metal(new_vec3(0.6, 0.6, 0.6), 0.5))));
    t_material difflight = mat_diff_light(diff_light(new_vec3(5, 5, 5)));
    t_material difflight_2 = mat_diff_light(diff_light(new_vec3(0, 5, 5)));
	httbl_addback(world, new_httbl(geom_quad(quad(new_vec3(-4, -4, 0), new_vec3(0, 8, 0), new_vec3(8, 0, 0))), difflight));
	httbl_addback(world, new_httbl(geom_sphere(sphere(new_vec3(5, 9, 2), 0.9)), difflight_2));
	//httbl_record(world, new_httbl(geom_box(box(new_vec3(-4, -4, -2), new_vec3(8, 8, 0))), difflight));
	httbl_record(world, new_httbl(geom_box(box(new_vec3(-3.5, -3.5, 0), new_vec3(-1.5,-1.5, 1.1))), mat_dielec(dielec(new_vec3(0.05, 0.15, 0.9), 1.5))));
//	add_box(world, new_vec3(-3.5, -1, 0), new_vec3(-1.5, 1, 1.65), mat_lamber(lamber(new_vec3(1.0, 0.6, 0.0))));
//	add_box(world, new_vec3(-3.5,  1.5, 0), new_vec3(-1.5, 3.5, 2.2), mat_lamber(lamber(new_vec3(0.2, 0.0, 0.3))));
//	add_box(world, new_vec3(-1, -3.5, 0), new_vec3( 1,-1.5, 0.7), mat_metal(metal(new_vec3(0.8, 0.8, 0.8), 0.6)));
	httbl_addback(world, new_httbl(geom_sphere(sphere(new_vec3(0, 0, 0.9), 0.9)), mat_dielec(dielec(new_vec3(1.0, 0.9, 0.9), 1.5))));
	httbl_addback(world, new_httbl(geom_sphere(sphere(new_vec3(0, 0, 4), 0.5)), mat_metal(metal(new_vec3(0.9, 0.75, 0.1), 0.8))));
//	add_box(world, new_vec3(-1,  1.5, 0), new_vec3( 1, 3.5, 2.2), mat_metal(metal(new_vec3(1.0, 0.1, 1.0), 0.8)));
//	add_box(world, new_vec3( 1.5, -3.5, 0), new_vec3( 3.5,-1.5, 1), mat_metal(metal(new_vec3(1.0, 0.0, 0.1), 0.4)));
//	add_box(world, new_vec3( 1.5, -1, 0), new_vec3( 3.5, 1, 2), mat_lamber(lamber(new_vec3(0.4, 0.3, 0.8))));
//	add_box(world, new_vec3( 1.5,  1.5, 0), new_vec3( 3.5, 3.5, 3), mat_dielec(dielec(new_vec3(0.4, 0.9, 0.0), 1.5)));
//	add_box(world, new_vec3( -0.7,  -5.5, 0), new_vec3( 0.8, -5.4, 1.5), mat_dielec(dielec(new_vec3(1.0, 0.3, 1.0), 1.5)));
//	add_box(world, new_vec3( 0.8,  -5.5, 0), new_vec3( 2.3, -5.4, 1.9), mat_dielec(dielec(new_vec3(1.0, 1.0, 0.3), 1.5)));
//	add_box(world, new_vec3( 2.3,  -5.5, 0), new_vec3( 5.5, -5.4, 1.2), mat_dielec(dielec(new_vec3(0.3, 1.0, 1.0), 1.5)));
	httbl_addback(world, new_httbl(geom_sphere(sphere(new_vec3(7, 4, 1.8), 1.8)), mat_metal(metal(new_vec3(1.0, 0.9, 0.9), 0))));
	httbl_addback(world, new_httbl(geom_sphere(sphere(new_vec3(7.2, -0.5, 1.5), 0.7)), mat_metal(metal(new_vec3(0.65, 0.8, 0.1), 0.8))));
	httbl_addback(world, new_httbl(geom_sphere(sphere(new_vec3(5.9, -2, 0.6), 0.6)), difflight));
	return (0);
}

bool	world_hit(t_rt *rt, const t_ray r, t_interval tray, t_hit_rec *rec)
{
	t_hit_rec	temp_rec;
	bool		hit_anything;
	double		closest_so_far;
	t_ray		transformed_r;
	t_vec3		cos_theta;
	t_vec3		sin_theta;

	ft_bzero(&temp_rec, sizeof(t_hit_rec));
	hit_anything = false;
	closest_so_far = tray.max;
	while (rt->world.httbl)
	{
		cos_theta = vec3_cos(rt->world.httbl->geom.theta);
		sin_theta = vec3_sin(rt->world.httbl->geom.theta);
		transformed_r = offset_r(r, vec3_scale(-1, rt->world.httbl->geom.offset));
		transformed_r = rotate_rx(transformed_r, cos_theta.x, -sin_theta.x);
		transformed_r = rotate_ry(transformed_r, cos_theta.y, -sin_theta.y);
		transformed_r = rotate_rz(transformed_r, cos_theta.z, -sin_theta.z);
		if ((rt->world.httbl->geom.type == PLANE && hit_plane(rt, transformed_r, interval(tray.min, closest_so_far), &temp_rec)) ||
					(rt->world.httbl->geom.type == QUAD && hit_quad(rt, transformed_r, interval(tray.min, closest_so_far), &temp_rec)) ||
					(rt->world.httbl->geom.type == SPHERE && hit_sphere(rt, transformed_r, interval(tray.min, closest_so_far), &temp_rec)) ||
					(rt->world.httbl->geom.type == CYLINDER && hit_cylinder_finite(rt, transformed_r, interval(tray.min, closest_so_far), &temp_rec)))
		{
			hit_anything = true;
			closest_so_far = temp_rec.t;
			if (rt->world.httbl->geom.theta.z)
			{
				temp_rec.p = rotate_z(temp_rec.p, cos_theta.z, sin_theta.z);
				temp_rec.normal = rotate_z(temp_rec.normal, cos_theta.z, sin_theta.z);
			}
			if (rt->world.httbl->geom.theta.y)
			{
				temp_rec.p = rotate_y(temp_rec.p, cos_theta.y, sin_theta.y);
				temp_rec.normal = rotate_y(temp_rec.normal, cos_theta.y, sin_theta.y);
			}
			if (rt->world.httbl->geom.theta.x)
			{
				temp_rec.p = rotate_x(temp_rec.p, cos_theta.x, sin_theta.x);
				temp_rec.normal = rotate_x(temp_rec.normal, cos_theta.x, sin_theta.x);
			}
			temp_rec.p = offset_p(temp_rec.p, rt->world.httbl->geom.offset);
			*rec = temp_rec;
		}
		rt->world.httbl = rt->world.httbl->next;
	}
	rt->world.httbl = rt->world.httbl_head;
	return hit_anything;
}

void	httbl_addback(t_world *world, t_httbl *new_httbl)
{
	if (!new_httbl)
		return ;
	if (!world->httbl)
	{
		world->httbl_head = new_httbl;
	}
	else
	{
		while (world->httbl->next)
			world->httbl = world->httbl->next;
		world->httbl->next = new_httbl;
	}
	world->size += 1;
	//Assign (if first) or go back to first element
	world->httbl = world->httbl_head;
	return ;
}

void	httbl_record(t_world *world, t_httbl *new_httbl)
{
	if (new_httbl->geom.type == BOX)
	{
		add_box_quads(world, &new_httbl->geom.box, new_httbl->mat);
		free(new_httbl);
		return;
	}
	if (new_httbl->geom.type == DICE)
	{
		add_box_quads(world, &new_httbl->geom.box, new_httbl->mat);
		add_dice_dots(world, &new_httbl->geom.box, new_httbl->mat);
		free(new_httbl);
		return;
	}
	if (new_httbl->geom.type == CYLINDER)
		add_cyl_discs(world, &new_httbl->geom, new_httbl->mat);
	if (new_httbl->geom.type == CONE)
		add_con_discs(world, &new_httbl->geom, new_httbl->mat);
	
	httbl_addback(world, new_httbl);
}
