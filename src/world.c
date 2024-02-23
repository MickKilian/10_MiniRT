/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:23:39 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/02/23 16:29:22 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

int	world_populate(t_world *world)
{
	//(void)world;
	printf("world's size is : %ld\n", world->size);
	display_world(world);
	//httbl_addback(world, new_httbl(geom_plane(plane(new_vec3( 0, 0, 0), vec3_cross(new_vec3(1, 0, 0), new_vec3(0, 1, 0)))), mat_lamber(lamber(new_vec3(0.7, 0.7, 0.7)))));
	//httbl_record(world, new_httbl(geom_cylinder(cylinder(new_vec3(0, 0, 0), new_vec3(0, 0, 1), 1, 2.5)), mat_metal(metal(new_vec3(0.81, 1, 0.02), 0))));
	//httbl_record(world, new_httbl(geom_disc(disc(new_vec3(0,0,0), new_vec3(0,0,1), 1)), mat_lamber(lamber(new_vec3(0.81, 1, 0.02))))); // begin
	//httbl_record(world, new_httbl(geom_sphere(sphere(new_vec3(0, 0, 1), 1)), mat_lamber(lamber(new_vec3(0, 1.0, 0.3)))));
	//httbl_record(world, new_httbl(geom_cone(cone(new_vec3(0.0, 0.0, 2.0), new_vec3(0, 0., 1), 0, 1, -2)), mat_lamber(lamber(new_vec3(1, 0, 0)))));
	//httbl_addback(world, new_httbl(geom_quad(quad(new_vec3(0, 0, 0), new_vec3(3, 0, 0), new_vec3(0, 3, 0))), mat_lamber(lamber(new_vec3(0, 0, 0.8)))));
	return (0);
}

void	create_saf_cone(t_world *world, t_vec3 pos, t_vec3 gen, double height) {
	double	radius_max = height / 4;
	double	radius_min = height / 20;
	double	radius_step = (radius_max - radius_min) / 5;

	httbl_record(world, new_httbl(geom_cone(cone(new_vec3(pos.x, pos.y, 5 * height / 5), gen, radius_min + 0 * radius_step, radius_min + 1 * radius_step, -height / 5)), mat_lamber(lamber(new_vec3(1, 0.2, 0)))));
	httbl_record(world, new_httbl(geom_cone(cone(new_vec3(pos.x, pos.y, 4 * height / 5), gen, radius_min + 1 * radius_step, radius_min + 2 * radius_step, -height / 5)), mat_lamber(lamber(new_vec3(1, 1, 1)))));
	httbl_record(world, new_httbl(geom_cone(cone(new_vec3(pos.x, pos.y, 3 * height / 5), gen, radius_min + 2 * radius_step, radius_min + 3 * radius_step, -height / 5)), mat_lamber(lamber(new_vec3(1, 0.2, 0)))));
	httbl_record(world, new_httbl(geom_cone(cone(new_vec3(pos.x, pos.y, 2 * height / 5), gen, radius_min + 3 * radius_step, radius_min + 4 * radius_step, -height / 5)), mat_lamber(lamber(new_vec3(1, 1, 1)))));
	httbl_record(world, new_httbl(geom_cone(cone(new_vec3(pos.x, pos.y, 1 * height / 5), gen, radius_min + 4 * radius_step, radius_min + 5 * radius_step, -height / 5)), mat_lamber(lamber(new_vec3(1, 0.2, 0)))));
	httbl_record(world, new_httbl(geom_box(box(new_vec3(pos.x - radius_max * 6 / 5, pos.y - radius_max * 6 / 5, 0), new_vec3(pos.x + radius_max * 6 / 5, pos.y + radius_max * 6 / 5, height / 20))), mat_lamber(lamber(new_vec3(1.0, 0.2, 0.1)))));
}

void	create_cylinder_box(t_world *world, double height, double width, double thickness, double factor, double spacing, double y_offset, double z_offset) {
	t_material *metal_tube = mat_metal(metal(new_vec3(0.2, 0.2, 0.2), 0));
	//t_material *metal_tube_2 = mat_metal(metal(new_vec3(0.0, 0.1, 0.0), 0.5));
	t_material *metal_trans_tube = mat_metal(metal(new_vec3(0.05, 0.05, 0.05), 0));

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
//	_table[httbl->geom->type](...);
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
		cos_theta = vec3_cos(rt->world.httbl->geom->theta);
		sin_theta = vec3_sin(rt->world.httbl->geom->theta);
		transformed_r = translate_r(r, vec3_scale(-1, rt->world.httbl->geom->trans));
		transformed_r = rotate_rx(transformed_r, cos_theta.x, -sin_theta.x);
		transformed_r = rotate_ry(transformed_r, cos_theta.y, -sin_theta.y);
		transformed_r = rotate_rz(transformed_r, cos_theta.z, -sin_theta.z);
		//printf("geom_type : %d\n", rt->world.httbl->geom->type);
		if ((rt->world.httbl->geom->type == POINT && hit_point_geom(rt, transformed_r, interval(tray.min, closest_so_far), &temp_rec)) ||
					(rt->world.httbl->geom->type == PLANE && hit_plane(rt, transformed_r, interval(tray.min, closest_so_far), &temp_rec)) ||
					(rt->world.httbl->geom->type == QUAD && hit_quad(rt, transformed_r, interval(tray.min, closest_so_far), &temp_rec)) ||
					(rt->world.httbl->geom->type == DISC && hit_disc(rt, transformed_r, interval(tray.min, closest_so_far), &temp_rec)) ||
					(rt->world.httbl->geom->type == SPHERE && hit_sphere(rt, transformed_r, interval(tray.min, closest_so_far), &temp_rec)) ||
					(rt->world.httbl->geom->type == CYLINDER && hit_cylinder_finite(rt, transformed_r, interval(tray.min, closest_so_far), &temp_rec)) ||
					(rt->world.httbl->geom->type == CONE && hit_cone_finite(rt, transformed_r, interval(tray.min, closest_so_far), &temp_rec)))
		{
			hit_anything = true;
			closest_so_far = temp_rec.t;
			if (rt->world.httbl->geom->theta.z)
			{
				temp_rec.p = rotate_z(temp_rec.p, cos_theta.z, sin_theta.z);
				temp_rec.normal = rotate_z(temp_rec.normal, cos_theta.z, sin_theta.z);
			}
			if (rt->world.httbl->geom->theta.y)
			{
				temp_rec.p = rotate_y(temp_rec.p, cos_theta.y, sin_theta.y);
				temp_rec.normal = rotate_y(temp_rec.normal, cos_theta.y, sin_theta.y);
			}
			if (rt->world.httbl->geom->theta.x)
			{
				temp_rec.p = rotate_x(temp_rec.p, cos_theta.x, sin_theta.x);
				temp_rec.normal = rotate_x(temp_rec.normal, cos_theta.x, sin_theta.x);
			}
			temp_rec.p = translate_p(temp_rec.p, rt->world.httbl->geom->trans);
			*rec = temp_rec;
		}
		rt->world.httbl = rt->world.httbl->next;
	}
	rt->world.httbl = rt->world.httbl_head;
	//if (hit_anything)
	//	printf("HIT %d\n", rt->world.httbl->geom->type);
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
	if (new_httbl->geom->type == BOX)
	{
		add_box_quads(world, &new_httbl->geom->box, new_httbl->mat);
		free(new_httbl);
		return;
	}
	if (new_httbl->geom->type == DIE)
	{
		add_box_quads(world, &new_httbl->geom->box, new_httbl->mat);
		add_die_dots(world, &new_httbl->geom->box, new_httbl->mat);
		free(new_httbl);
		return;
	}
	if (new_httbl->geom->type == CYLINDER) {
		printf("adding for cyl\n");
		add_cyl_discs(world, new_httbl->geom, new_httbl->mat);
	}
	if (new_httbl->geom->type == CONE)
		add_con_discs(world, new_httbl->geom, new_httbl->mat);
	
	httbl_addback(world, new_httbl);
}
