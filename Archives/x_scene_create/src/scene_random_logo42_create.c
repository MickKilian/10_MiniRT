/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_random_logo42_create.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:23:39 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/03/16 03:30:10 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/scene_create.h"

bool	is_inside(double x, double r, double min, double max)
{
	return (x - r >= min && x + r <= max);
}

bool	is_in_logo42(t_sphere sph, t_vec3 p, double height)
{
	double	x;
	double	y;
	double	z;
	double	r;

	x = 40.0 / height * (sph.center.x - p.x);
	y = 40.0 / height * (sph.center.y - p.y);
	z = 40.0 / height * (sph.center.z - p.z);
	r = 40.0 / height * sph.radius;
	//4 in 42
	if (!is_inside(y, r, 0, 20))
		return (0);
	else if (is_inside(z, r, 0.0, 19.0) && is_inside(x, r, 17.0, 25.5))
		return (1);
	else if (is_inside(z, r, 10.5, 19.0) && is_inside(x, r, 0.0, 25.5))
		return (1);
	else if ((is_inside(z, r, 10.5, 27.5) && is_inside(x, r, -8.5 + z - 10.5, z - 10.5)) && (is_inside(z, r, 10.5, 27.5) && is_inside(x, r, 0.0, 17.0)))
		return (1);
	else if (is_inside(z, r, 19.0, 40.0) && is_inside(x, r, z - 19.0, 8.5 + z - 19.0))
		return (1);
	//2 in 42
	else if (is_inside(z, r, 9.5, 19.0) && (is_inside(x, r, 30.0, 38.5) || is_inside(x, r, 38.5 + z - 9.5, 47.0)))
		return (1);
	else if (is_inside(z, r, 31.5, 40.0) && (is_inside(x, r, 38.5, 47.0) || is_inside(x, r, 30.0, 30.0 + z - 31.5)))
		return (1);
	else if ((is_inside(z, r, 9.5, 31.5) && is_inside(x, r, 20.5 + z - 9.5, 29.0 + z - 9.5)) && (is_inside(z, r, 9.5, 31.5) && is_inside(x, r, 30.0, 38.5)))
		return (1);
	else if ((is_inside(z, r, 19.0, 40.0) && is_inside(x, r, 30.0 + z - 19.0, 38.5 + z - 19.0)) && (is_inside(z, r, 19.0, 40.0) && is_inside(x, r, 38.5, 47.0)))
		return (1);
	return (0);
}

void	random_logo42_sphere(t_world *world, double height, int nb_spheres)
{
	t_vec3		center;
	t_vec3		color;
	double		radius;
	int			count;
	t_sphere	sph;

	count = 0;
	while (count < nb_spheres) {
		center = new_vec3(random_double_interval(-height, height), random_double_interval(-height, height), random_double_interval(-height, height));
		radius = random_double_interval(height / 80, height / 20);
		sph = sphere(center, radius);
		if (is_in_logo42(sph, new_vec3(-0.5875 * height, -0.5875 * height, -0.5 * height), height) && !is_overlaying(world->httbl_head, sph) && !is_overlaying_xz(world->httbl_head, sph))
		{
			color = random_vec3_interval(0, 255);
			httbl_record(world, geom_sphere(sphere(center, radius)), mat_lamber(lamber(rgb2vec(color))));
			httbl_record(world, geom_quad(quad(center, new_vec3(height / 1000.0,0,0), new_vec3(0.0,0.0,2.0 * height))), mat_lamber(lamber(rgb2vec(new_vec3(200,200,180)))));
			printf("sp %f,%f,%f %f %d,%d,%d\n", center.x, center.y, center.z, radius, (int)color.x, (int)color.y, (int)color.z);
			printf("qd %f,%f,%f %f,%f,%f %f,%f,%f %d,%d,%d\n",
					center.x, center.y, center.z,
					height / 1000, 0.0, 0.0,
					0.0, 0.0, 2.0 * height,
					200, 200, 180);
			count++;
			//printf("count %d\n", count);
		}
	}
}

bool	is_overlaying(t_httbl *httbl, t_sphere sph)
{
	while (httbl)
	{
		if (httbl->geom->type == SPHERE && vec3_length(vec3_substract2(httbl->geom->sph.center, sph.center)) < 1.2 * (httbl->geom->sph.radius + sph.radius))
			return (1);
		httbl = httbl->next;
	}
	return (0);
}

bool	is_overlaying_xz(t_httbl *httbl, t_sphere sph)
{
	while (httbl)
	{
		if (httbl->geom->type == SPHERE && vec3_length(vec3_substract2(vec3_prod_comp_by_comp(httbl->geom->sph.center, new_vec3(1,0,1)), vec3_prod_comp_by_comp(sph.center, new_vec3(1,0,1)))) < 1.0 * (httbl->geom->sph.radius + sph.radius))
			return (1);
		httbl = httbl->next;
	}
	return (0);
}
