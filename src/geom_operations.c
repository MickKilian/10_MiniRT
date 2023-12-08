/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geom_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 09:42:04 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/12/08 05:29:29 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ray_tracing.h"

void	add_box_quads(t_world *world, t_box *box, t_material mat)
{
	t_vec3	min;
	t_vec3	max;
	t_vec3	dx;
	t_vec3	dy;
	t_vec3	dz;

	// Construct the two opposite vertices with the minimum and maximum coordinates.
	min = new_vec3(fmin(box->a.x, box->b.x), fmin(box->a.y, box->b.y), fmin(box->a.z, box->b.z));
	max = new_vec3(fmax(box->a.x, box->b.x), fmax(box->a.y, box->b.y), fmax(box->a.z, box->b.z));

	dx = new_vec3(max.x - min.x, 0, 0);
	dy = new_vec3(0, max.y - min.y, 0);
	dz = new_vec3(0, 0, max.z - min.z);

	httbl_addback(world, new_httbl(geom_quad(quad(new_vec3(min.x, min.y, max.z), dx, dy)), mat)); // front
	httbl_addback(world, new_httbl(geom_quad(quad(new_vec3(max.x, min.y, max.z), vec3_scale(-1, dz), dy)), mat)); // front
	httbl_addback(world, new_httbl(geom_quad(quad(new_vec3(max.x, min.y, min.z), vec3_scale(-1, dx), dy)), mat)); // front
	httbl_addback(world, new_httbl(geom_quad(quad(new_vec3(min.x, min.y, min.z), dz, dy)), mat)); // front
	httbl_addback(world, new_httbl(geom_quad(quad(new_vec3(min.x, max.y, max.z), dx, vec3_scale(-1, dz))), mat)); // front
	httbl_addback(world, new_httbl(geom_quad(quad(new_vec3(min.x, min.y, min.z), dx, dz)), mat)); // front
}

void	add_cyl_discs(t_world *world, t_cylinder *cyl, t_material mat)
{
	t_vec3	end_disc_center;

	printf("We are here\n");
	// Construct the two opposite discs of a finite cylinder.
	end_disc_center = vec3_add2(cyl->base_center, vec3_scale(cyl->height, cyl->generator));
	httbl_addback(world, new_httbl(geom_disc(disc(cyl->base_center, cyl->generator, cyl->radius)), mat)); // begin
	httbl_addback(world, new_httbl(geom_disc(disc(end_disc_center, cyl->generator, cyl->radius)), mat)); // end
}

t_ray	offset_r(t_ray r, t_vec3 offset)
{
	t_vec3	new_orig;

	new_orig = vec3_add2(r.orig, offset);
	return (new_ray(new_orig, r.dir));
}

t_vec3	offset_p(t_vec3 v, t_vec3 offset)
{
	return (vec3_add2(v, offset));
}

t_vec3	rotate_x(t_vec3 vec, double cos_theta, double sin_theta)
{
	t_vec3	rotated_vec;

	rotated_vec.x = vec.x;
	rotated_vec.y = cos_theta * vec.y - sin_theta * vec.z;
	rotated_vec.z = sin_theta * vec.y + cos_theta * vec.z;
	return (rotated_vec);
}

t_ray	rotate_rx(t_ray r, double cos_theta, double sin_theta)
{
	return (new_ray(rotate_x(r.orig, cos_theta, sin_theta), rotate_x(r.dir, cos_theta, sin_theta)));
}

t_vec3	rotate_y(t_vec3 vec, double cos_theta, double sin_theta)
{
	t_vec3	rotated_vec;

	rotated_vec.y = vec.y;
	rotated_vec.x = cos_theta * vec.x + sin_theta * vec.z;
	rotated_vec.z = -sin_theta * vec.x + cos_theta * vec.z;
	return (rotated_vec);
}

t_ray	rotate_ry(t_ray r, double cos_theta, double sin_theta)
{
	return (new_ray(rotate_y(r.orig, cos_theta, sin_theta), rotate_y(r.dir, cos_theta, sin_theta)));
}

t_vec3	rotate_z(t_vec3 vec, double cos_theta, double sin_theta)
{
	t_vec3	rotated_vec;

	rotated_vec.z = vec.z;
	rotated_vec.x = cos_theta * vec.x - sin_theta * vec.y;
	rotated_vec.y = sin_theta * vec.x + cos_theta * vec.y;
	return (rotated_vec);
}

t_ray	rotate_rz(t_ray r, double cos_theta, double sin_theta)
{
	return (new_ray(rotate_z(r.orig, cos_theta, sin_theta), rotate_z(r.dir, cos_theta, sin_theta)));
}
