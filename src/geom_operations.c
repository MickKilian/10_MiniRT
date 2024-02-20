/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geom_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 09:42:04 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/02/15 23:32:59 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

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

	httbl_addback(world, new_httbl(geom_quad(quad(new_vec3(min.x, min.y, max.z), dx, dy)), mat)); // up
	httbl_addback(world, new_httbl(geom_quad(quad(new_vec3(max.x, min.y, max.z), vec3_scale(-1, dz), dy)), mat)); // right
	httbl_addback(world, new_httbl(geom_quad(quad(new_vec3(max.x, min.y, min.z), vec3_scale(-1, dx), dy)), mat)); // bottom
	httbl_addback(world, new_httbl(geom_quad(quad(new_vec3(min.x, min.y, min.z), dz, dy)), mat)); // left
	httbl_addback(world, new_httbl(geom_quad(quad(new_vec3(min.x, max.y, max.z), dx, vec3_scale(-1, dz))), mat)); // back
	httbl_addback(world, new_httbl(geom_quad(quad(new_vec3(min.x, min.y, min.z), dx, dz)), mat)); // front
}

void	add_die_dots(t_world *world, t_box *box, t_material mat)
{
	t_vec3	min;
	t_vec3	max;
	t_vec3	dx;
	t_vec3	dy;
	t_vec3	dz;
	double	dot_r;
	t_material	mat_dot;
	t_vec3	size;

	// Construct the two opposite vertices with the minimum and maximum coordinates.
	min = new_vec3(fmin(box->a.x, box->b.x), fmin(box->a.y, box->b.y), fmin(box->a.z, box->b.z));
	max = new_vec3(fmax(box->a.x, box->b.x), fmax(box->a.y, box->b.y), fmax(box->a.z, box->b.z));

	dx = new_vec3(max.x - min.x, 0, 0);
	dy = new_vec3(0, max.y - min.y, 0);
	dz = new_vec3(0, 0, max.z - min.z);

	dot_r = (max.x - min.x) / 20;
	size = new_vec3( max.x - min.x, max.y - min.y, max.z - min.z);

	mat_dot = mat_lamber(lamber(new_vec3(1, 1, 1)));

	//(void)dx;
	(void)dy;
	(void)dz;
	(void)mat;

	// Construct DOTS FACE 1
	httbl_addback(world, new_httbl(geom_disc(disc(new_vec3(min.x + size.x / 2, min.y + size.y / 2, max.z), vec3_scale(1, dz), dot_r)), mat_dot));
	// Construct DOTS FACE 2
	httbl_addback(world, new_httbl(geom_disc(disc(new_vec3(min.x, min.y + size.y / 2 - size.y / 3, min.z + size.z / 2 - size.z / 3), vec3_scale(-1, dx), dot_r)), mat_dot));
	httbl_addback(world, new_httbl(geom_disc(disc(new_vec3(min.x, min.y + size.y / 2 + size.y  / 3, min.z + size.z / 2 + size.z / 3), vec3_scale(-1, dx), dot_r)), mat_dot));
	// Construct DOTS FACE 3
	httbl_addback(world, new_httbl(geom_disc(disc(new_vec3(min.x + size.x / 2 - size.x / 3, min.y, min.z + size.z / 2 - size.z / 3), vec3_scale(-1, dy), dot_r)), mat_dot));
	httbl_addback(world, new_httbl(geom_disc(disc(new_vec3(min.x + size.x / 2, min.y, min.z + size.z / 2), vec3_scale(-1, dy), dot_r)), mat_dot));
	httbl_addback(world, new_httbl(geom_disc(disc(new_vec3(min.x + size.x / 2 + size.x / 3, min.y, min.z + size.z / 2 + size.z / 3), vec3_scale(-1, dy), dot_r)), mat_dot));
	// Construct DOTS FACE 4
	httbl_addback(world, new_httbl(geom_disc(disc(new_vec3(min.x + size.x / 2 - size.x / 3, max.y, min.z + size.z / 2 - size.z / 3), vec3_scale(1, dy), dot_r)), mat_dot));
	httbl_addback(world, new_httbl(geom_disc(disc(new_vec3(min.x + size.x / 2 - size.x / 3, max.y, min.z + size.z / 2 + size.z / 3), vec3_scale(1, dy), dot_r)), mat_dot));
	httbl_addback(world, new_httbl(geom_disc(disc(new_vec3(min.x + size.x / 2 + size.x / 3, max.y, min.z + size.z / 2 - size.z / 3), vec3_scale(1, dy), dot_r)), mat_dot));
	httbl_addback(world, new_httbl(geom_disc(disc(new_vec3(min.x + size.x / 2 + size.x / 3, max.y, min.z + size.z / 2 + size.z / 3), vec3_scale(1, dy), dot_r)), mat_dot));
	// Construct DOTS FACE 5
	httbl_addback(world, new_httbl(geom_disc(disc(new_vec3(max.x, min.y + size.y / 2 - size.y / 3, min.z + size.z / 2 - size.z / 3), vec3_scale(1, dx), dot_r)), mat_dot));
	httbl_addback(world, new_httbl(geom_disc(disc(new_vec3(max.x, min.y + size.y / 2 - size.y / 3, min.z + size.z / 2 + size.z / 3), vec3_scale(1, dx), dot_r)), mat_dot));
	httbl_addback(world, new_httbl(geom_disc(disc(new_vec3(max.x, min.y + size.y / 2, min.z + size.z / 2), vec3_scale(1, dx), dot_r)), mat_dot));
	httbl_addback(world, new_httbl(geom_disc(disc(new_vec3(max.x, min.y + size.y / 2 + size.y / 3, min.z + size.z / 2 - size.z / 3), vec3_scale(1, dx), dot_r)), mat_dot));
	httbl_addback(world, new_httbl(geom_disc(disc(new_vec3(max.x, min.y + size.y / 2 + size.y / 3, min.z + size.z / 2 + size.z / 3), vec3_scale(1, dx), dot_r)), mat_dot));
	// Construct DOTS FACE 6
	httbl_addback(world, new_httbl(geom_disc(disc(new_vec3(min.x + size.x / 2 - size.x / 3, min.y + size.y / 2 - size.y / 3, min.z), vec3_scale(-1, dz), dot_r)), mat_dot));
	httbl_addback(world, new_httbl(geom_disc(disc(new_vec3(min.x + size.x / 2 - size.x / 3, min.y + size.y / 2, min.z), vec3_scale(-1, dz), dot_r)), mat_dot));
	httbl_addback(world, new_httbl(geom_disc(disc(new_vec3(min.x + size.x / 2 - size.x / 3, min.y + size.y / 2 + size.y / 3, min.z), vec3_scale(-1, dz), dot_r)), mat_dot));
	httbl_addback(world, new_httbl(geom_disc(disc(new_vec3(min.x + size.x / 2 + size.x / 3, min.y + size.y / 2 - size.y / 3, min.z), vec3_scale(-1, dz), dot_r)), mat_dot));
	httbl_addback(world, new_httbl(geom_disc(disc(new_vec3(min.x + size.x / 2 + size.x / 3, min.y + size.y / 2, min.z), vec3_scale(-1, dz), dot_r)), mat_dot));
	httbl_addback(world, new_httbl(geom_disc(disc(new_vec3(min.x + size.x / 2 + size.x / 3, min.y + size.y / 2 + size.y / 3, min.z), vec3_scale(-1, dz), dot_r)), mat_dot));
}

void	add_cyl_discs(t_world *world, t_geometry *geom, t_material mat)
{
	t_vec3	begin_disc_center;
	t_vec3	end_disc_center;
	t_vec3	cos_theta;
	t_vec3	sin_theta;
	t_vec3	generator;

	// Construct the two opposite discs of a finite cylinder.
	cos_theta = vec3_cos(vec3_scale(1, geom->theta));
	sin_theta = vec3_sin(vec3_scale(1, geom->theta));
	begin_disc_center = translate_p(rotate(geom->cyl.base_center, cos_theta, sin_theta), vec3_scale(1, geom->trans));
	generator = rotate(geom->cyl.generator, cos_theta, sin_theta);
	httbl_addback(world, new_httbl(geom_disc(disc(begin_disc_center, generator, geom->cyl.radius)), mat)); // begin
	end_disc_center = translate_p(rotate(vec3_add2(geom->cyl.base_center, vec3_scale(geom->cyl.height, geom->cyl.generator)),cos_theta, sin_theta), vec3_scale(1, geom->trans));
	httbl_addback(world, new_httbl(geom_disc(disc(end_disc_center, generator, geom->cyl.radius)), mat)); // end
}

void	add_con_discs(t_world *world, t_geometry *geom, t_material mat)
{
	t_vec3	begin_disc_center;
	t_vec3	end_disc_center;
	t_vec3	cos_theta;
	t_vec3	sin_theta;
	t_vec3	generator;

	// Construct the two opposite discs of a finite cone.
	cos_theta = vec3_cos(vec3_scale(1, geom->theta));
	sin_theta = vec3_sin(vec3_scale(1, geom->theta));
	begin_disc_center = translate_p(rotate(geom->con.base_center, cos_theta, sin_theta), vec3_scale(1, geom->trans));
	generator = rotate(geom->con.generator, cos_theta, sin_theta);
	httbl_addback(world, new_httbl(geom_disc(disc(begin_disc_center, generator, geom->con.radius_min)), mat)); // begin
	end_disc_center = translate_p(rotate(vec3_add2(geom->con.base_center, vec3_scale(geom->con.height, geom->con.generator)),cos_theta, sin_theta), vec3_scale(1, geom->trans));
	httbl_addback(world, new_httbl(geom_disc(disc(end_disc_center, generator, geom->con.radius_max)), mat)); // end
}

t_ray	translate_r(t_ray r, t_vec3 trans)
{
	t_vec3	new_orig;

	new_orig = vec3_add2(r.orig, trans);
	return (new_ray(new_orig, r.dir));
}

t_vec3	translate_p(t_vec3 v, t_vec3 trans)
{
	return (vec3_add2(v, trans));
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

t_vec3		rotate(t_vec3 vec, t_vec3 cos_theta, t_vec3 sin_theta) {
	t_vec3	rotated_vec;

	rotated_vec = rotate_x(vec, cos_theta.x, sin_theta.x);
	rotated_vec = rotate_y(rotated_vec, cos_theta.y, sin_theta.y);
	rotated_vec = rotate_z(rotated_vec, cos_theta.z, sin_theta.z);
	return (rotated_vec);
}
