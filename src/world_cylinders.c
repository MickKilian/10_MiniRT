/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_cylinders.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:23:39 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/02/11 20:35:44 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

//	cam->samples_per_pixel = 10;
//	cam->max_depth = 40;
//	//parsed//cam->background = new_vec3(0.2, 0.2, 0.2);		// Background color
//	cam->vfov = 15;  // Vertical view angle (field of view)
//
//	cam->defocus_angle = 0.0;  // Variation angle of rays through each pixel
//    cam->focus_dist = 5000;    // Distance from camera lookfrom point to plane of perfect focus
//
//	// Camera position
//	look_from = new_vec3(22000, -13000, 12000);	// Point camera is looking from
//	//look_from = new_vec3(2000, -2000, 500);	// Point camera is looking from
//    look_at = new_vec3(3000, 2000, 500);		// Point camera is looking at
//    //look_at = new_vec3(0, 0, 0);		// Point camera is looking at
//    vup = new_vec3(0.0, 0.0, 1.0);			// Camera-relative "up" direction
//	cam->center = look_from;

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
	//httbl_addback(world, new_httbl(geom_quad(quad(new_vec3(0, 0, 0), new_vec3(1, 0, 0), new_vec3(0, 1, 0))), mat_lamber(lamber(new_vec3(0.8, 0.8, 0.8)))));
	////httbl_addback(world, new_httbl(geom_sphere(sphere(new_vec3(5, 4, 10), 1)), difflight));

	//httbl_addback(world, new_httbl(geom_cylinder(cylinder(new_vec3(0, 0, 0), new_vec3(0, 0, 10), 1, 10)), mat_lamber(lamber(new_vec3(1, 0, 0)))));


	//httbl_record(world, new_httbl(geom_sphere(sphere(new_vec3(0, 0, -10010), 10000)), mat_lamber(lamber(new_vec3(0, 0, 10)))));
	//httbl_record(world, new_httbl(geom_sphere(sphere(new_vec3(0, 0, 0.5), 0.5)), mat_lamber(lamber(new_vec3(1.0, 1.0, 0.3)))));
	//httbl_record(world, new_httbl(geom_cylinder(cylinder(new_vec3(0.0, 0.0, 0.0), new_vec3(0.0, 0., 1), 0.2, 1)), mat_lamber(lamber(new_vec3(0, 0, 1)))));
	//httbl_record(world, new_httbl(geom_cylinder(cylinder(new_vec3(1.0, -1.0, 0.0), new_vec3(0.3, 0., 1), 0.2, 2.0)), mat_lamber(lamber(new_vec3(1, 0, 0.3)))));
	//httbl_record(world, new_httbl(geom_cylinder(cylinder(new_vec3(-1.0, 1.0, 0.0), new_vec3(0.3, 0., 1), 0.2, 2.0)), mat_lamber(lamber(new_vec3(1, 0, 0.3)))));
	//httbl_record(world, new_httbl(geom_cylinder(cylinder(new_vec3(1.0, 1.0, 0.0), new_vec3(0.3, 0., 1), 0.2, 2.0)), mat_lamber(lamber(new_vec3(1, 0, 0.3)))));
	//httbl_record(world, new_httbl(geom_cylinder(cylinder(new_vec3(0.0, 0.0, 2.0), new_vec3(0.3, 0., 1), 1.5, 0.5)), mat_lamber(lamber(new_vec3(1, 0, 0.8)))));
	//httbl_record(world, new_httbl(geom_cylinder(cylinder(new_vec3(0.0, 0.0, 2.5), new_vec3(0.3, 0., 1), 0.5, 0.3)), mat_lamber(lamber(new_vec3(0.2, 0, 0.8)))));
	//t_material difflight = mat_diff_light(diff_light(new_vec3(5, 5, 5)));
	//httbl_addback(world, new_httbl(geom_quad(quad(new_vec3(-4, -4, 0), new_vec3(0, 8, 0), new_vec3(8, 0, 0))), difflight));
	//httbl_record(world, new_httbl(geom_box(box(new_vec3(-4, -4, -2), new_vec3(8, 8, 0))), difflight));
	//double a = 1;
//	httbl_record(world, new_httbl(geom_box(box(new_vec3( -a/2, -a/2, 0), new_vec3(a/2, a/2, a))), mat_lamber(lamber(new_vec3(0.4, 0.3, 0.8)))));
	//
	//httbl_record(world, new_httbl(geom_cone(cone(new_vec3(0.0, 0.0, 2.0), new_vec3(0, 0., 1), 0, 0.5, -1)), mat_lamber(lamber(new_vec3(1, 1, 0)))));
	//httbl_record(world, new_httbl(geom_box(box(new_vec3( 0, 0, -0), new_vec3( 3, 2, 2))), mat_lamber(lamber(new_vec3(0.4, 0.3, 0.8)))));
	////PINK: new_vec3(1, 0, 0.8)
	//CUP
	//httbl_record(world, new_httbl(geom_cone(cone(new_vec3(4, 4, 0.0), new_vec3(0., 0., 1), 1.8, 2, 4)), mat_metal(metal(new_vec3(0.6, 0.6, 0.6), 0.5))));
	////INFINITE PLANE
	httbl_addback(world, new_httbl(geom_plane(plane(new_vec3( 0, 0, 0), new_vec3(1, 0, 0), new_vec3(0, 1, 0))), mat_lamber(lamber(new_vec3(0.7, 0.7, 0.7)))));
	//httbl_addback(world, new_httbl(geom_plane(plane(new_vec3( 0, 0, 0), new_vec3(1, 0, 0), new_vec3(0, 1, 0))), mat_metal(metal(new_vec3(0.8, 0.8, 0.95), 0.9))));
	double	thickness = 100;
	double	factor = 0.3;
//	double	height = 947 * 2;
//	double	width = 5807.92;
//	//MIRROR
//	httbl_record(world, new_httbl(geom_box(box(new_vec3(-5000, 15000, 0), new_vec3(15000, 15200, 2 * height))), mat_metal(metal(new_vec3(0.7, 0.9, 1.0), 0))));
//	//BOX
//	create_cylinder_box(world, height, width, thickness, factor, 1500);
//	////cylinders
//	//481, 911, 358, 947, 426,
//	//0, 481, 1804.92, 2947.09, 4111.61, 5381.92, 5807.92
//	httbl_record(world, new_httbl(geom_cylinder(cylinder(new_vec3(481, -1850, thickness * factor + 481), new_vec3(0, 1, 0), 481, 3700)), mat_metal(metal(new_vec3(0.2, 0.7, 0), 0))));
//	httbl_record(world, new_httbl(geom_cylinder(cylinder(new_vec3(1804.82, -1500, thickness * factor + 911), new_vec3(0, 1, 0), 911, 3000)), mat_metal(metal(new_vec3(0.2, 0.2, 0.0), 0))));
//	httbl_record(world, new_httbl(geom_cylinder(cylinder(new_vec3(2947.09, -2500, thickness * factor + 358), new_vec3(0, 1, 0), 358, 5000)), mat_metal(metal(new_vec3(0.9, 0.3, 0.4), 0))));
//	httbl_record(world, new_httbl(geom_cylinder(cylinder(new_vec3(4111.61, -1450, thickness * factor + 947), new_vec3(0, 1, 0), 947, 2900)), mat_metal(metal(new_vec3(0.7, 0.7, 0.7), 0))));
//	httbl_record(world, new_httbl(geom_cylinder(cylinder(new_vec3(5381.92, -1600, thickness * factor + 426), new_vec3(0, 1, 0), 426, 3200)), mat_metal(metal(new_vec3(0.0, 0.3, 0.7), 0))));
//
	double	length = 1500;
	double	y_offset = 4.5 * length;
	double	z_offset = 0;
	double	height = 796 * 2;
	double	width_2 = 10114.378;
	//MIRROR
	//httbl_record(world, new_httbl(geom_box(box(new_vec3(-15000, 15000, 0), new_vec3(15000, 15200, 2.5 * height))), mat_metal(metal(new_vec3(0.05, 0.1, 0.4), 0))));
	//stop mirror
	httbl_addback(world, new_httbl(geom_quad(quad(new_vec3(0, -4000, 0), new_vec3(0, y_offset + 3000 + 6000, 0), new_vec3(0, 0, 3 * height))), mat_metal(metal(new_vec3(0.2, 0.2, 0.4), 0))));
	//BOX
	//create_cylinder_box(world, height, width, thickness, factor, 2500, y_offset, z_offset);
	////cylinders
	//85, 279, 496, 602, 644, 715, 723, 765, 796
	//0, 85, 392.994, 1136.99, 2229.86, 3475.16, 4832.3, 6270.28, 7757.69, 9318.38, 10114.4
	httbl_record(world, new_httbl(geom_cylinder(cylinder(new_vec3(85, y_offset - length, thickness * factor + 85), new_vec3(0, 1, 0), 85, length * 2)), mat_metal(metal(new_vec3(0.81, 1, 0.02), 0))));
	httbl_record(world, new_httbl(geom_cylinder(cylinder(new_vec3(392.994, y_offset - length, thickness * factor + 279), new_vec3(0, 1, 0), 279, length * 2)), mat_metal(metal(new_vec3(0.9, 0.01, 0.01), 0))));
	httbl_record(world, new_httbl(geom_cylinder(cylinder(new_vec3(1136.99, y_offset - length, thickness * factor + 496), new_vec3(0, 1, 0), 496, length * 2)), mat_metal(metal(new_vec3(0.4, 0.4, 0.4), 0))));
	httbl_record(world, new_httbl(geom_cylinder(cylinder(new_vec3(2229.86, y_offset - length, thickness * factor + 602), new_vec3(0, 1, 0), 602, length * 2)), mat_metal(metal(new_vec3(0.9, 0.7, 0.2), 0))));
	httbl_record(world, new_httbl(geom_cylinder(cylinder(new_vec3(3475.16, y_offset - length, thickness * factor + 644), new_vec3(0, 1, 0), 644, length * 2)), mat_metal(metal(new_vec3(0.2, 0.4, 0.0), 0))));
	httbl_record(world, new_httbl(geom_cylinder(cylinder(new_vec3(4832.3, y_offset - length, thickness * factor + 715), new_vec3(0, 1, 0), 715, length * 2)), mat_metal(metal(new_vec3(0.4, 0.2, 0.7), 0))));
	httbl_record(world, new_httbl(geom_cylinder(cylinder(new_vec3(6270.28, y_offset - length, thickness * factor + 723), new_vec3(0, 1, 0), 723, length * 2)), mat_metal(metal(new_vec3(0.8, 0.8, 0.8), 0))));
	httbl_record(world, new_httbl(geom_cylinder(cylinder(new_vec3(7757.69, y_offset - length, thickness * factor + 765), new_vec3(0, 1, 0), 765, length * 2)), mat_metal(metal(new_vec3(0.7, 0.4, 0.0), 0))));
	httbl_record(world, new_httbl(geom_cylinder(cylinder(new_vec3(9318.38, y_offset - length, thickness * factor + 796), new_vec3(0, 1, 0), 796, length * 2)), mat_metal(metal(new_vec3(0.0, 0.3, 0.7), 0))));

	//
	y_offset = 0;
	z_offset = 0;
	length = 1500;
	height = 796 * 2;
	double	width_1 = 9713.97;
	//MIRROR
	//httbl_record(world, new_httbl(geom_box(box(new_vec3(1000, 15000, 0), new_vec3(12000, 15200, 2.5 * height))), mat_metal(metal(new_vec3(1.0, 1.0, 0.9), 0))));
//	httbl_addback(world, new_httbl(geom_quad(quad(new_vec3(-8000, 30000, 0), new_vec3(18000, 3000, 0), new_vec3(0, 100, 2.5 * height))), mat_metal(metal(new_vec3(0.7, 1.0, 1.0), 0))));
	//httbl_record(world, new_httbl(geom_box(box(new_vec3(980, 14080, 0), new_vec3(12020, 14080, 20))), mat_lamber(lamber(new_vec3(0.1, 0.1, 0.5)))));
	//httbl_record(world, new_httbl(geom_box(box(new_vec3(980, 14080, 2.5 * height - 20), new_vec3(12020, 14080, 2.5 * height + 20))), mat_lamber(lamber(new_vec3(0.1, 0.1, 0.5)))));
	//BOX
	//create_cylinder_box(world, height, width, thickness, factor, 2500, y_offset, z_offset);
	////cylinders
	//85, 644, 723, 496, 796, 279, 765, 602, 715,
	//0, 85, 644, 2008.72, 3206.39, 4463.08, 5405.6, 6329.58, 7686.82, 8998.97, 9713.97
	httbl_record(world, new_httbl(geom_cylinder(cylinder(new_vec3(85, y_offset - length, thickness * factor + 85 + z_offset), new_vec3(0, 1, 0), 85, length * 2)), mat_metal(metal(new_vec3(0.81, 1, 0.02), 0))));
	httbl_record(world, new_httbl(geom_cylinder(cylinder(new_vec3(644, y_offset - length, thickness * factor + 644 + z_offset), new_vec3(0, 1, 0), 644, length * 2)), mat_metal(metal(new_vec3(0.2, 0.4, 0.0), 0))));
	httbl_record(world, new_httbl(geom_cylinder(cylinder(new_vec3(2008.72, y_offset - length, thickness * factor + 723 + z_offset), new_vec3(0, 1, 0), 723, length * 2)), mat_metal(metal(new_vec3(0.8, 0.8, 0.8), 0))));
	httbl_record(world, new_httbl(geom_cylinder(cylinder(new_vec3(3206.39, y_offset - length, thickness * factor + 496 + z_offset), new_vec3(0, 1, 0), 496, length * 2)), mat_metal(metal(new_vec3(0.4, 0.4, 0.4), 0))));
	httbl_record(world, new_httbl(geom_cylinder(cylinder(new_vec3(4463.08, y_offset - length, thickness * factor + 796 + z_offset), new_vec3(0, 1, 0), 796, length * 2)), mat_metal(metal(new_vec3(0.0, 0.3, 0.7), 0))));
	httbl_record(world, new_httbl(geom_cylinder(cylinder(new_vec3(5405.6, y_offset - length, thickness * factor + 279 + z_offset), new_vec3(0, 1, 0), 279, length * 2)), mat_metal(metal(new_vec3(0.9, 0.01, 0.01), 0))));
	httbl_record(world, new_httbl(geom_cylinder(cylinder(new_vec3(6329.58, y_offset - length, thickness * factor + 765 + z_offset), new_vec3(0, 1, 0), 765, length * 2)), mat_metal(metal(new_vec3(0.7, 0.4, 0.0), 0))));
	httbl_record(world, new_httbl(geom_cylinder(cylinder(new_vec3(7686.82, y_offset - length, thickness * factor + 602 + z_offset), new_vec3(0, 1, 0), 602, length * 2)), mat_metal(metal(new_vec3(0.9, 0.7, 0.2), 0))));
	httbl_record(world, new_httbl(geom_cylinder(cylinder(new_vec3(8998.97, y_offset - length, thickness * factor + 715 + z_offset), new_vec3(0, 1, 0), 715, length * 2)), mat_metal(metal(new_vec3(0.4, 0.2, 0.7), 0))));

	//Glass measure block
	httbl_record(world, new_httbl(geom_box(box(new_vec3(width_1, -3000, 0), new_vec3(width_1 + 5, 6000, height))), mat_dielec(dielec(new_vec3(0.9, 0.9, 1.0), 1.5))));
	y_offset = 6 * length;
	httbl_record(world, new_httbl(geom_box(box(new_vec3(width_2, y_offset - 6000, 0), new_vec3(width_2 + 5, y_offset + 3000, height))), mat_dielec(dielec(new_vec3(1.0, 0.9, 0.9), 1.5))));
	//CONES
	//create_safety_cone(world, new_vec3(7000, 0, 0), new_vec3(0.0, 0.0, 1.0), 600.0);
	create_safety_cone(world, new_vec3(9000, -4000, 0), new_vec3(0.0, 0.0, 1.0), 600.0);
	create_safety_cone(world, new_vec3(7000, -4000, 0), new_vec3(0.0, 0.0, 1.0), 600.0);
	create_safety_cone(world, new_vec3(5000, -4000, 0), new_vec3(0.0, 0.0, 1.0), 600.0);
	create_safety_cone(world, new_vec3(3000, -4000, 0), new_vec3(0.0, 0.0, 1.0), 600.0);
	create_safety_cone(world, new_vec3(1000, -4000, 0), new_vec3(0.0, 0.0, 1.0), 600.0);
	create_safety_cone(world, new_vec3(11000, 0, 0), new_vec3(0.0, 0.0, 1.0), 600.0);

	//TREES
//	t_vec3 pos = new_vec3(-25000, 45000, 7000);
//	httbl_record(world, new_httbl(geom_cone(cone(new_vec3(pos.x, pos.y, pos.z), new_vec3(0, 0, 1), 400, 800, -pos.z)), mat_lamber(lamber(new_vec3(0.1, 0.05, 0)))));
//	httbl_record(world, new_httbl(geom_sphere(sphere(new_vec3(pos.x, pos.y, -30000), 30200)), mat_lamber(lamber(new_vec3(0.01, 0.01, 0)))));
//	httbl_record(world, new_httbl(geom_sphere(sphere(new_vec3(pos.x, pos.y, pos.z), pos.z * 2 / 7)), mat_lamber(lamber(new_vec3(0.1, 0.4, 0.1)))));
//	httbl_record(world, new_httbl(geom_sphere(sphere(new_vec3(pos.x + 2000, 0.9 * pos.y, 1.2 * pos.z), pos.z * 2 / 17)), mat_lamber(lamber(new_vec3(0.2, 0.2, 0.05)))));
//	httbl_record(world, new_httbl(geom_sphere(sphere(new_vec3(pos.x + 2800, pos.y - 2800, 0.95 * pos.z), pos.z * 2 / 20)), mat_lamber(lamber(new_vec3(0.05, 0.2, 0.05)))));
//	httbl_record(world, new_httbl(geom_sphere(sphere(new_vec3(pos.x - 2000, pos.y, 1.15 * pos.z), pos.z * 2 / 15)), mat_lamber(lamber(new_vec3(0.17, 0.2, 0.05)))));
//	httbl_record(world, new_httbl(geom_sphere(sphere(new_vec3(pos.x, pos.y - 2000, 1.05 * pos.z), pos.z * 2 / 14)), mat_lamber(lamber(new_vec3(0.05, 0.2, 0.05)))));
//
//	pos = new_vec3(12000, 10000, 800);
//	httbl_record(world, new_httbl(geom_sphere(sphere(new_vec3(pos.x, pos.y, pos.z), 1000)), mat_lamber(lamber(new_vec3(0.08, 0.08, 0)))));
//	pos = new_vec3(13000, 11000, 500);
//	httbl_record(world, new_httbl(geom_sphere(sphere(new_vec3(pos.x, pos.y, pos.z), 700)), mat_lamber(lamber(new_vec3(0.05, 0.05, 0.01)))));
//	pos = new_vec3(12900, 9000, 200);
//	httbl_record(world, new_httbl(geom_sphere(sphere(new_vec3(pos.x, pos.y, pos.z), 300)), mat_lamber(lamber(new_vec3(0.3, 0.2, 0.05)))));
//	//pos = new_vec3(11000, 20000, 1000);
//	//httbl_record(world, new_httbl(geom_sphere(sphere(new_vec3(pos.x, pos.y, pos.z), 3000)), mat_lamber(lamber(new_vec3(0.6, 0.1, 0.05)))));
//	//httbl_record(world, new_httbl(geom_sphere(sphere(new_vec3(pos.x + 600, pos.y - 400, 2 * pos.z), 2000)), mat_lamber(lamber(new_vec3(0.3, 0.1, 0.08)))));
	
//	//SUN
//	httbl_record(world, new_httbl(geom_sphere(sphere(new_vec3(-180000, 250000, 18000), 6000)), mat_lamber(lamber(new_vec3(1, 0.7, 0.1)))));
	
	return (0);
}

void	create_safety_cone(t_world *world, t_vec3 pos, t_vec3 gen, double height) {
	double	radius_max = height / 4;
	double	radius_min = height / 20;
	double	radius_step = (radius_max - radius_min) / 5;

	httbl_record(world, new_httbl(geom_cone(cone(new_vec3(pos.x, pos.y, 5 * height / 5), gen, radius_min + 0 * radius_step, radius_min + 1 * radius_step, -height / 5)), mat_lamber(lamber(new_vec3(1, 0.2, 0)))));
	httbl_record(world, new_httbl(geom_cone(cone(new_vec3(pos.x, pos.y, 4 * height / 5), gen, radius_min + 1 * radius_step, radius_min + 2 * radius_step, -height / 5)), mat_lamber(lamber(new_vec3(1, 1, 1)))));
	httbl_record(world, new_httbl(geom_cone(cone(new_vec3(pos.x, pos.y, 3 * height / 5), gen, radius_min + 2 * radius_step, radius_min + 3 * radius_step, -height / 5)), mat_lamber(lamber(new_vec3(1, 0.2, 0)))));
	httbl_record(world, new_httbl(geom_cone(cone(new_vec3(pos.x, pos.y, 2 * height / 5), gen, radius_min + 3 * radius_step, radius_min + 4 * radius_step, -height / 5)), mat_lamber(lamber(new_vec3(1, 1, 1)))));
	httbl_record(world, new_httbl(geom_cone(cone(new_vec3(pos.x, pos.y, 1 * height / 5), gen, radius_min + 4 * radius_step, radius_min + 5 * radius_step, -height / 5)), mat_lamber(lamber(new_vec3(1, 0.2, 0)))));
	httbl_record(world, new_httbl(geom_box(box(new_vec3(pos.x - 6 / 5 * radius_max, pos.y - 6 / 5 * radius_max, 0), new_vec3(pos.x + 6 / 5 * radius_max, pos.y + 6 / 5 * radius_max, height / 20))), mat_lamber(lamber(new_vec3(1.0, 0.2, 0.1)))));
}

void	create_cylinder_box(t_world *world, double height, double width, double thickness, double factor, double spacing, double y_offset, double z_offset) {
	t_material metal_tube = mat_metal(metal(new_vec3(0.2, 0.2, 0.2), 0));
	//t_material metal_tube_2 = mat_metal(metal(new_vec3(0.0, 0.1, 0.0), 0.5));
	t_material metal_trans_tube = mat_metal(metal(new_vec3(0.05, 0.05, 0.05), 0));

	//BOX
	httbl_record(world, new_httbl(geom_box(box(new_vec3(-thickness * factor, y_offset - spacing / 2 - thickness, z_offset + 0), new_vec3(0, y_offset - spacing / 2, z_offset + height + 2 * thickness * factor))), metal_tube));
	httbl_record(world, new_httbl(geom_box(box(new_vec3(-thickness * factor, y_offset + spacing / 2, z_offset + 0), new_vec3(0, y_offset + spacing / 2 + thickness, z_offset + height + 2 * thickness * factor))), metal_tube));
	httbl_record(world, new_httbl(geom_box(box(new_vec3(width, y_offset - spacing / 2 - thickness, z_offset + 0), new_vec3(width + thickness * factor, y_offset - spacing / 2, z_offset + height + 2 * thickness * factor))), metal_tube));
	httbl_record(world, new_httbl(geom_box(box(new_vec3(width, y_offset + spacing / 2, z_offset + 0), new_vec3(width + thickness * factor, y_offset + spacing / 2 + thickness, z_offset + height + 2 * thickness * factor))), metal_tube));
	httbl_record(world, new_httbl(geom_box(box(new_vec3(-thickness * factor, y_offset - spacing / 2 - thickness, z_offset + 0), new_vec3(width + thickness * factor, y_offset - spacing / 2, z_offset + thickness * factor))), metal_tube));
	httbl_record(world, new_httbl(geom_box(box(new_vec3(-thickness * factor, y_offset + spacing / 2, z_offset + 0), new_vec3(width + thickness * factor, y_offset + spacing / 2 + thickness, z_offset + thickness * factor))), metal_tube));
	httbl_record(world, new_httbl(geom_box(box(new_vec3(-thickness * factor, y_offset - spacing / 2 - thickness, z_offset + height + thickness * factor), new_vec3(width + thickness * factor, y_offset - spacing / 2, z_offset + height + 2 * thickness * factor))), metal_tube));
	httbl_record(world, new_httbl(geom_box(box(new_vec3(-thickness * factor, y_offset + spacing / 2, z_offset + height + thickness * factor), new_vec3(width + thickness * factor, y_offset + spacing / 2 + thickness, z_offset + height + 2 * thickness * factor))), metal_tube));
	//
	httbl_record(world, new_httbl(geom_box(box(new_vec3(-thickness * factor, y_offset - spacing / 2 - thickness, z_offset + height / 2 - spacing / 8 - thickness), new_vec3(0, y_offset + spacing / 2 + thickness, z_offset + height / 2 - spacing / 8))), metal_trans_tube));
	httbl_record(world, new_httbl(geom_box(box(new_vec3(-thickness * factor, y_offset - spacing / 2 - thickness, z_offset + height / 2 + spacing / 8), new_vec3(0, y_offset + spacing / 2 + thickness, z_offset + height / 2 + spacing / 8 + thickness))), metal_trans_tube));
	httbl_record(world, new_httbl(geom_box(box(new_vec3(width, y_offset + - spacing / 2 - thickness, z_offset + height / 2 - spacing / 8 - thickness), new_vec3(width + thickness * factor, y_offset + spacing / 2 + thickness, z_offset + height / 2 - spacing / 8))), metal_trans_tube));
	httbl_record(world, new_httbl(geom_box(box(new_vec3(width, y_offset + - spacing / 2 - thickness, z_offset + height / 2 + spacing / 8), new_vec3(width + thickness * factor, y_offset + spacing / 2 + thickness, z_offset + height / 2 + spacing / 8 + thickness))), metal_trans_tube));
	httbl_record(world, new_httbl(geom_box(box(new_vec3(width / 2 - spacing / 8 - thickness, y_offset - spacing / 2 - thickness, z_offset + height + thickness * factor), new_vec3(width / 2 - spacing / 8, y_offset + spacing / 2 + thickness, z_offset + height + 2 * thickness * factor))), metal_trans_tube));
	httbl_record(world, new_httbl(geom_box(box(new_vec3(width / 2 + spacing / 8, y_offset - spacing / 2 - thickness, z_offset + height + thickness * factor), new_vec3(width / 2 + spacing / 8 + thickness, y_offset + spacing / 2 + thickness, z_offset + height + 2 * thickness * factor))), metal_trans_tube));
	httbl_record(world, new_httbl(geom_box(box(new_vec3(width / 2 - spacing / 8 - thickness, y_offset - spacing / 2 - thickness, z_offset + 0), new_vec3(width / 2 - spacing / 8, y_offset + spacing / 2 + thickness, z_offset + thickness * factor))), metal_trans_tube));
	httbl_record(world, new_httbl(geom_box(box(new_vec3(width / 2 + spacing / 8, y_offset - spacing / 2 - thickness, z_offset + 0), new_vec3(width / 2 + spacing / 8 + thickness, y_offset + spacing / 2 + thickness, z_offset + thickness * factor))), metal_trans_tube));
}

//tableau de pointeurs sur fonctions
//typedef bool (*t_hit)(const t_rt *, const t_ray, const t_interval, t_hit_rec *);
//
//static void render(t_httbl* httbl)
//{
//	static const t_hit _table[LEN_GEOM_TYPES] =
//	{
//		&hit_plane,
//		&hit_quad,
//		&hit_disc,
//		NULL,
//		&hit_sphere,
//		&hit_cylinder_finite
//	}
//
//	_table[httbl->geom.type](...);
//}

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
		//printf("theta\n");
		//display_vec3(rt->world.httbl->geom.theta);
		//printf("\n");
		cos_theta = vec3_cos(rt->world.httbl->geom.theta);
		sin_theta = vec3_sin(rt->world.httbl->geom.theta);
		transformed_r = offset_r(r, vec3_scale(-1, rt->world.httbl->geom.offset));
		transformed_r = rotate_rx(transformed_r, cos_theta.x, -sin_theta.x);
		transformed_r = rotate_ry(transformed_r, cos_theta.y, -sin_theta.y);
		transformed_r = rotate_rz(transformed_r, cos_theta.z, -sin_theta.z);
		//display_vec3(r.dir);
		//printf("\n*");
		//display_vec3(transformed_r.dir);
		//printf("\n");
		if ((rt->world.httbl->geom.type == PLANE && hit_plane(rt, transformed_r, interval(tray.min, closest_so_far), &temp_rec)) ||
					(rt->world.httbl->geom.type == QUAD && hit_quad(rt, transformed_r, interval(tray.min, closest_so_far), &temp_rec)) ||
					(rt->world.httbl->geom.type == DISC && hit_disc(rt, transformed_r, interval(tray.min, closest_so_far), &temp_rec)) ||
					(rt->world.httbl->geom.type == SPHERE && hit_sphere(rt, transformed_r, interval(tray.min, closest_so_far), &temp_rec)) ||
					(rt->world.httbl->geom.type == CYLINDER && hit_cylinder_finite(rt, transformed_r, interval(tray.min, closest_so_far), &temp_rec)) ||
					(rt->world.httbl->geom.type == CONE && hit_cone_finite(rt, transformed_r, interval(tray.min, closest_so_far), &temp_rec)))
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
