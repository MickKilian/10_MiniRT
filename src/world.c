/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:23:39 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/12/08 05:58:34 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ray_tracing.h"

int	world_initialize(t_world *world)
{
	//ft_bzero(world, sizeof(t_world));
	// Initialisation of world
	//// Populate world with sphere for ground
	//httbl_addback(world, new_httbl_sphere(new_sphere(new_vec3(-0.0, -100.5, -1.0), 100.0), METAL, new_vec3(0.13333, 0.25, 0.36)));
	//// Populate world with central sphere
	//httbl_addback(world, new_httbl_sphere(new_sphere(new_vec3(0.0, 0.0, -1.0), 0.5), METAL, new_vec3(0.5, 0.5, 0.5)));
	//// Populate with many little spheres
	//httbl_addback(world, new_httbl_sphere(new_sphere(new_vec3(-0.6, -0.3, -0.7), 0.15), METAL, new_vec3(0.0, 0.5, 0.0)));
	//httbl_addback(world, new_httbl_sphere(new_sphere(new_vec3(1.0, 1.0, -0.5), 0.8), LAMBERTIAN, new_vec3(0.8, 0.3, 0.05)));
	//httbl_addback(world, new_httbl_sphere(new_sphere(new_vec3(-0.3, 0.0, -0.5), 0.05), LAMBERTIAN, new_vec3(0.5, 0.0, 0.0)));
	//httbl_addback(world, new_httbl_sphere(new_sphere(new_vec3(0.3, 0.3, -0.5), 0.05), LAMBERTIAN, new_vec3(0.0, 0.0, 0.5)));
	//httbl_addback(world, new_httbl_sphere(new_sphere(new_vec3(0.5, 0.2, -0.5), 0.02), LAMBERTIAN, new_vec3(0.0, 0.5, 0.5)));
	//httbl_addback(world, new_httbl_sphere(new_sphere(new_vec3(-0.6, 0.3, -0.5), 0.03), LAMBERTIAN, new_vec3(0.5, 0.0, 0.5)));
	//httbl_addback(world, new_httbl_sphere(new_sphere(new_vec3(-0.03, 0.19, -0.3), 0.05), LAMBERTIAN, new_vec3(1.0, 1.0, 0.0)));
	//OTHER SET OF SPHERES
	//// Ground
	//httbl_addback(world, new_httbl_sphere(new_sphere(new_vec3(-0.0, -100.5, -1.0), 100.0), LAMBERTIAN, new_vec3(0.8, 0.8, 0.0)));
	//// Center sphere
	//httbl_addback(world, new_httbl_sphere(new_sphere(new_vec3(0.0, 0.0, -1.0), 0.5), LAMBERTIAN, new_vec3(0.1, 0.2, 0.5)));
	//// Left sphere
	//httbl_addback(world, new_httbl_sphere(new_sphere(new_vec3(-1.0, 0.0, -1.0), 0.5), DIELECTRIC, new_vec3(0.9, 0.9, 0.9)));
	//httbl_addback(world, new_httbl_sphere(new_sphere(new_vec3(-1.0, 0.0, -1.0), -0.4), DIELECTRIC, new_vec3(0.9, 0.9, 0.9)));
	//// Right sphere
	//httbl_addback(world, new_httbl_sphere(new_sphere(new_vec3(1.0, 0.0, -1.0), 0.5), LAMBERTIAN, new_vec3(0.02, 0.0, 0.1)));
	//// Left sphere
	//httbl_addback(world, new_httbl_sphere(new_sphere(new_vec3(-r, 0.0, -1.0), r), LAMBERTIAN, new_vec3(0.0, 0.0, 1.0)));
	//// Right spehere
	//httbl_addback(world, new_httbl_sphere(new_sphere(new_vec3(r, 0.0, -1.0), r), LAMBERTIAN, new_vec3(1.0, 0.0, 0.0)));

//	//// Populate world with sphere for ground
//	httbl_addback(world, new_httbl_sphere(new_sphere(new_vec3(-0.0, -100.5, -1.0), 100.0), LAMBERTIAN, new_vec3(0.8, 0.8, 0.0)));
//	// Center sphere
//	httbl_addback(world, new_httbl_sphere(new_sphere(new_vec3(0.0, 0.0, -1.0), 0.5), LAMBERTIAN, new_vec3(0.1, 0.2, 0.5)));
//	// Left sphere
//	httbl_addback(world, new_httbl_sphere(new_sphere(new_vec3(-1.0, 0.0, -1.0), 0.5), DIELECTRIC, new_vec3(0.9, 0.9, 0.9)));
//	httbl_addback(world, new_httbl_sphere(new_sphere(new_vec3(-1.0, 0.0, -1.0), -0.4), DIELECTRIC, new_vec3(0.9, 0.9, 0.9)));
//	// Right sphere
//	httbl_addback(world, new_httbl_sphere(new_sphere(new_vec3(1.0, 0.0, -1.0), 0.5), METAL, new_vec3(0.8, 0.6, 0.2)));
//
	// Center sphere
	//httbl_addback(world, new_httbl_sphere(new_sphere(new_vec3(0.0, 0.0, -1.0), 0.5), LAMBERTIAN, new_vec3(0.1, 0.2, 0.5)));
	//httbl_addback(world, new_httbl(void(*p1), void(*p2)));

//	// Populate world with sphere for ground
//	httbl_addback(world, new_httbl(geom_sphere(sphere(new_vec3(0.0, -100.5, -1.0), 100.0)), mat_lamber(lamber(new_vec3(0.8, 0.8, 0.0)))));
//	// Center sphere
//	httbl_addback(world, new_httbl(geom_sphere(sphere(new_vec3(0.0, 0.0, -1.0), 0.5)), mat_lamber(lamber(new_vec3(0.1, 0.2, 0.5)))));
//	// Left sphere
//	httbl_addback(world, new_httbl(geom_sphere(sphere(new_vec3(-1.0, 0.0, -1.0), 0.5)), mat_dielec(dielec(new_vec3(0.9, 0.9, 0.9), 1.5))));
//	httbl_addback(world, new_httbl(geom_sphere(sphere(new_vec3(-1.0, 0.0, -1.0), -0.4)), mat_dielec(dielec(new_vec3(0.9, 0.9, 0.9), 1.5))));
//	// Right sphere
//	httbl_addback(world, new_httbl(geom_sphere(sphere(new_vec3(1.0, 0.0, -1.0), 0.5)), mat_metal(metal(new_vec3(0.8, 0.6, 0.2), 0.0))));

	// Populate world with sphere for ground
//	httbl_addback(world, new_httbl(geom_sphere(sphere(new_vec3(0.0, -1000.0, 0.0), 1000)), mat_lamber(lamber(new_vec3(0.5, 0.5, 0.5)))));


//	for (int a = -11; a < 11; a++) {
//		for (int b = -11; b < 11; b++) {
//			double	choose_mat = random_double();
//			t_vec3	center = new_vec3(a + 0.9 * random_double(), 0.2, b + 0.9 * random_double());
//
//			if (vec3_length(vec3_substract2(center, new_vec3(4, 0.2, 0))) > 0.9)
//			{
//				t_material	sphere_material;
//				if (choose_mat < 0.8) {
//					// diffuse
//					t_vec3	albedo = vec3_prod_comp_by_comp(new_vec3(random_double(), random_double(), random_double()),
//							new_vec3(random_double(), random_double(), random_double()));
//					sphere_material = mat_lamber(lamber(albedo));
//					httbl_addback(world, new_httbl(geom_sphere(sphere(center, 0.2)), sphere_material));
//				} 
//				else if (choose_mat < 0.95)
//				{
//					// metal
//					t_vec3	albedo = new_vec3(random_double_interval(0.5, 1), random_double_interval(0.5, 1.0), random_double_interval(0.5, 1.0));
//					double	fuzz = random_double(0, 0.5);
//					sphere_material = mat_metal(metal(albedo, fuzz));
//					httbl_addback(world, new_httbl(geom_sphere(sphere(center, 0.2)), sphere_material));
//				}
//				else
//				{
//					// glass
//					t_vec3	albedo = new_vec3(0.5, 0.5, 0.5);
//					sphere_material = mat_dielec(dielec(albedo, 1.5));
//					httbl_addback(world, new_httbl(geom_sphere(sphere(center, 0.2)), sphere_material));
//				}
//			}
//		}
//	httbl_addback(world, new_httbl(geom_sphere(sphere(new_vec3(0.0, -1000.0, 0.0), 1000)), mat_lamber(lamber(new_vec3(0.5, 0.5, 0.5)))));
 // Materials
    //t_material	left_red     = mat_lamber(lamber(new_vec3(1.0, 0.2, 0.2)));
    //t_material	back_green   = mat_lamber(lamber(new_vec3(0.2, 1.0, 0.2)));
    //t_material	right_blue   = mat_lamber(lamber(new_vec3(0.2, 0.2, 1.0)));
    //t_material	upper_orange = mat_lamber(lamber(new_vec3(1.0, 0.5, 0.0)));
    //t_material	lower_teal   = mat_lamber(lamber(new_vec3(0.2, 0.8, 0.8)));

    // Planes
	//httbl_addback(world, new_httbl(geom_plane(plane(new_vec3(-3,-2, 5), new_vec3(0, 0,-4), new_vec3(0, 4, 0))), left_red));
	///httbl_addback(world, new_httbl(geom_plane(plane(new_vec3(-2,-2, 0), new_vec3(4, 0, 0), new_vec3(0, 4, 0))), back_green));
	//httbl_addback(world, new_httbl(geom_plane(plane(new_vec3( 3,-2, 1), new_vec3(0, 0, 4), new_vec3(0, 4, 0))), right_blue));
	//httbl_addback(world, new_httbl(geom_plane(plane(new_vec3(-2, 3, 1), new_vec3(4, 0, 0), new_vec3(0, 0, 4))), upper_orange));
	//httbl_addback(world, new_httbl(geom_plane(plane(new_vec3(-2,-3, 5), new_vec3(4, 0, 0), new_vec3(0, 0,-4))), lower_teal));

//	httbl_addback(world, new_httbl(geom_sphere(sphere(new_vec3(0.0, 1.0, 0.0), 1.0)), mat_dielec(dielec(new_vec3(0.9, 0.9, 0.9), 1.5))));
//
//	httbl_addback(world, new_httbl(geom_sphere(sphere(new_vec3(-4.0, 1.0, 0.0), 1.0)), mat_lamber(lamber(new_vec3(0.4, 0.2, 0.1)))));
//
//	httbl_addback(world, new_httbl(geom_sphere(sphere(new_vec3(4.0, 1.0, 0.0), 1.0)), mat_metal(metal(new_vec3(0.7, 0.6, 0.5), 0.0))));
//	//Materials
    //t_material	left_red     = mat_lamber(lamber(new_vec3(1.0, 0.2, 0.2)));
    //t_material	left_red     = mat_lamber(lamber(new_vec3(1.0, 0.2, 0.2)));
    //t_material	back_green   = mat_lamber(lamber(new_vec3(0.2, 1.0, 0.2)));
    //t_material	lower_teal   = mat_lamber(lamber(new_vec3(0.2, 0.8, 0.8)));
    // Planes
	//httbl_addback(world, new_httbl(geom_plane(plane(new_vec3(0, 0, 0), new_vec3(0, 1, 0), new_vec3(0, 0, 1))), left_red));
	//httbl_addback(world, new_httbl(geom_plane(plane(new_vec3(0, 0, 0), new_vec3(1, 0, 0), new_vec3(0, 1, 0))), back_green));
	//httbl_addback(world, new_httbl(geom_plane(plane(new_vec3(0, 0, 0), new_vec3(0, 1, 0), new_vec3(0, 0, 1))), lower_teal));
	//// Sphere
	//httbl_addback(world, new_httbl(geom_sphere(sphere(new_vec3(0.0, 0.0, 0.0), 4.0)), mat_dielec(dielec(new_vec3(0.5, 0.5, 0.5), 1.5))));
//	httbl_addback(world, new_httbl(geom_sphere(sphere(new_vec3(0, 0, -1000), 1000)), mat_metal(metal(new_vec3(0.6, 0.6, 0.6), 0.5))));
//	//httbl_addback(world, new_httbl(geom_sphere(sphere(new_vec3(0, 2, 0), 2)), mat_lamber(lamber(new_vec3(1, 0.0, 0.1)))));
//    t_material difflight = mat_diff_light(diff_light(new_vec3(5, 5, 5)));
//    t_material difflight_2 = mat_diff_light(diff_light(new_vec3(0, 5, 5)));
//	httbl_addback(world, new_httbl(geom_quad(quad(new_vec3(-4, -4, 0), new_vec3(0, 8, 0), new_vec3(8, 0, 0))), difflight));
//	httbl_addback(world, new_httbl(geom_sphere(sphere(new_vec3(5, 9, 2), 0.9)), difflight_2));
//	add_box(world, new_vec3(-3.5, -3.5, 0), new_vec3(-1.5,-1.5, 1.1), mat_dielec(dielec(new_vec3(0.05, 0.15, 0.9), 1.5)));
//	add_box(world, new_vec3(-3.5, -1, 0), new_vec3(-1.5, 1, 1.65), mat_lamber(lamber(new_vec3(1.0, 0.6, 0.0))));
//	add_box(world, new_vec3(-3.5,  1.5, 0), new_vec3(-1.5, 3.5, 2.2), mat_lamber(lamber(new_vec3(0.2, 0.0, 0.3))));
//	add_box(world, new_vec3(-1, -3.5, 0), new_vec3( 1,-1.5, 0.7), mat_metal(metal(new_vec3(0.8, 0.8, 0.8), 0.6)));
//	//add_box(world, new_vec3(-1, -1, 0), new_vec3( 1, 1, 0.5), mat_lamber(lamber(new_vec3(5.0, 4.0, 0.0))));
//	//add_box(world, new_vec3(-0.5, -0.5, 0), new_vec3( 0.5, 0.5, 1.3), difflight_2);
//	httbl_addback(world, new_httbl(geom_sphere(sphere(new_vec3(0, 0, 0.9), 0.9)), mat_dielec(dielec(new_vec3(1.0, 0.9, 0.9), 1.5))));
//	//add_box(world, new_vec3(-0.1, -0.1, 1.5), new_vec3( 0.1, 0.1, 3.2), mat_lamber(lamber(new_vec3(0.05, 0.05, 0.3))));
//	httbl_addback(world, new_httbl(geom_sphere(sphere(new_vec3(0, 0, 4), 0.5)), mat_metal(metal(new_vec3(0.9, 0.75, 0.1), 0.8))));
//	add_box(world, new_vec3(-1,  1.5, 0), new_vec3( 1, 3.5, 2.2), mat_metal(metal(new_vec3(1.0, 0.1, 1.0), 0.8)));
//	add_box(world, new_vec3( 1.5, -3.5, 0), new_vec3( 3.5,-1.5, 1), mat_metal(metal(new_vec3(1.0, 0.0, 0.1), 0.4)));
//	add_box(world, new_vec3( 1.5, -1, 0), new_vec3( 3.5, 1, 2), mat_lamber(lamber(new_vec3(0.4, 0.3, 0.8))));
//	add_box(world, new_vec3( 1.5,  1.5, 0), new_vec3( 3.5, 3.5, 3), mat_dielec(dielec(new_vec3(0.4, 0.9, 0.0), 1.5)));
//	add_box(world, new_vec3( -0.7,  -5.5, 0), new_vec3( 0.8, -5.4, 1.5), mat_dielec(dielec(new_vec3(1.0, 0.3, 1.0), 1.5)));
//	add_box(world, new_vec3( 0.8,  -5.5, 0), new_vec3( 2.3, -5.4, 1.9), mat_dielec(dielec(new_vec3(1.0, 1.0, 0.3), 1.5)));
//	add_box(world, new_vec3( 2.3,  -5.5, 0), new_vec3( 5.5, -5.4, 1.2), mat_dielec(dielec(new_vec3(0.3, 1.0, 1.0), 1.5)));
// 	//world.add(box(point3(265, 0, 295), point3(430, 330, 460), white))
//	httbl_addback(world, new_httbl(geom_sphere(sphere(new_vec3(7, 4, 1.8), 1.8)), mat_metal(metal(new_vec3(1.0, 0.9, 0.9), 0))));
//	httbl_addback(world, new_httbl(geom_sphere(sphere(new_vec3(7.2, -0.5, 1.5), 0.7)), mat_metal(metal(new_vec3(0.65, 0.8, 0.1), 0.8))));
//	httbl_addback(world, new_httbl(geom_sphere(sphere(new_vec3(5.9, -2, 0.6), 0.6)), difflight));

    //t_material difflight = mat_diff_light(diff_light(new_vec3(50, 50, 50)));
	//httbl_addback(world, new_httbl(geom_quad(quad(new_vec3(0, 1, -10), new_vec3(5, 0, 0), new_vec3(0, 5, 0))), difflight));
	////httbl_addback(world, new_httbl(geom_sphere(sphere(new_vec3(5, 4, 10), 1)), difflight));

	//httbl_addback(world, new_httbl(geom_cylinder(cylinder(new_vec3(0, 0, 0), new_vec3(0, 0, 10), 1, 10)), mat_lamber(lamber(new_vec3(1, 0, 0)))));


	//httbl_record(world, new_httbl(geom_sphere(sphere(new_vec3(0, 0, -1000), 1000)), mat_lamber(lamber(new_vec3(0.8, 0.8, 0.8)))));
	//httbl_record(world, new_httbl(geom_sphere(sphere(new_vec3(0, 0, 1), 1)), mat_lamber(lamber(new_vec3(1.0, 0.0, 0.3)))));
	httbl_record(world, new_httbl(geom_cylinder(cylinder(new_vec3 (0, 0, 0), new_vec3(0, 0, 1), 2, 2.0)), mat_lamber(lamber(new_vec3(1, 0, 0.3)))));
	//httbl_record(world, new_httbl(geom_box(box(new_vec3( -1, -1, -0), new_vec3( 1, 1, 2))), mat_lamber(lamber(new_vec3(0.4, 0.3, 0.8)))));
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
					(rt->world.httbl->geom.type == DISC && hit_disc(rt, transformed_r, interval(tray.min, closest_so_far), &temp_rec)) ||
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
		add_box_quads(world, &new_httbl->geom. box, new_httbl->mat);
		free(new_httbl);
		return;
	}
	httbl_addback(world, new_httbl);
	if (new_httbl->geom.type == CYLINDER)
		add_cyl_discs(world, &new_httbl->geom.cyl, new_httbl->mat);
}
