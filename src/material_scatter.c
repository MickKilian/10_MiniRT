/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material_scatter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 02:25:58 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/02/13 02:02:39 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

// Lambertian : We model here Light Scatter and Reflectance
// Lambertian ditribution (in a manner proportional to cos(phi))
// We have 3 different options to model scatter of Lambertian diffuse materials we choose model with attenuation and always scattering
bool	lambertian_scatter(const t_ray r_in, const t_hit_rec rec, t_vec3 *attenuation, t_ray *scattered)
{
	t_vec3	scatter_direction;

	// Different steps to refine scattering model for diffuse material
	//// ray_color is mapped with the coordinates of the normal to the surface at hit point
	//return (vec3_scale(0.5, vec3_add2(rec.normal, new_vec3(1.0, 1.0, 1.0))));
	//// We use here reflection evenly in all directions
	//bouncing_dir = random_in_same_hemisphere(rec.normal);
	scatter_direction = vec3_add2(rec.normal, random_unit_vector());
	// Catch degenerate scatter direction
	if (near_zero(scatter_direction))
		scatter_direction = rec.normal;
	*scattered = new_ray(rec.p, scatter_direction);
    *attenuation = rec.lamber.color;
	(void)r_in;
    return (1);
}

// Metal : Perfect reflection
// We use function reflect
bool	metal_scatter(const t_ray r_in, const t_hit_rec rec, t_vec3 *attenuation, t_ray *scattered)
{
	t_vec3	reflected;

	reflected = reflect(vec3_unit(r_in.dir), rec.normal);
	*scattered = new_ray(rec.p, vec3_add2(reflected, vec3_scale(rec.metal.fuzz, random_unit_vector())));
    *attenuation = rec.metal.color;
    return (1);
}

// Dielectric : ALl refraction
// We use function refract
bool	dielectric_scatter(const t_ray r_in, const t_hit_rec rec, t_vec3 *attenuation, t_ray *scattered)
{
	double	ir = 1.5;	// Index of Refraction
	double	refraction_ratio;
	double	cos_theta;
	double	sin_theta;
	t_vec3	direction;
	bool	cannot_refract;

	if (rec.front_face)
		refraction_ratio = 1.0 / ir;
	else
		refraction_ratio = ir;
	cos_theta = fmin(vec3_dot(vec3_scale(-1.0, vec3_unit(r_in.dir)), rec.normal), 1.0);
	sin_theta = sqrt(1.0 - cos_theta*cos_theta);
	cannot_refract = refraction_ratio * sin_theta > 1.0;
	if (cannot_refract || reflectance(cos_theta, refraction_ratio) > random_double())
		direction = reflect(vec3_unit(r_in.dir), rec.normal);
	else
	direction = refract(vec3_unit(r_in.dir), rec.normal, refraction_ratio);
	*scattered = new_ray(rec.p, direction);
    *attenuation = rec.dielec.color;
    return (1);
}
