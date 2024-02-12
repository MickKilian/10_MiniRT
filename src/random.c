/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 02:32:41 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/12/04 02:32:34 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

t_vec3	get_random_dev(const t_camera *cam)
{
	t_vec3	dev;

	dev.x = cam->pixel_delta_u.x * (random_double() - 0.5);
	dev.y = cam->pixel_delta_v.y * (random_double() - 0.5);
	dev.z = 0.0;
	return (dev);
}

double	random_double()
{
    // Returns a random real in [0,1).
    return ((double)rand() / ((double)RAND_MAX + 1.0));
}

double	random_double_interval(double min, double max)
{
    // Returns a random real in [min,max).
    return (min + (max-min)*random_double());
}

t_vec3	random_vec3_interval(double min, double max)
{
	return(new_vec3(random_double_interval(min, max),
				random_double_interval(min, max),
				random_double_interval(min, max)));
}

t_vec3	random_in_unit_sphere(void)
{
	// We will generate a unit vector inside a sphere using the rejection method
	// First we generate a vector inside a cube and then we check if this vector is within the sphere
	t_vec3	vec;

	while (true)
	{
		vec	= random_vec3_interval(-1.0, 1.0);
		if (vec3_length_squared(vec) < 1.0)
			return (vec);
	}
}

t_vec3	random_unit_vector(void)
{
	return (vec3_unit(random_in_unit_sphere()));
}

t_vec3	random_in_same_hemisphere(const t_vec3 normal)
{
	t_vec3	vec_on_unit_sphere;

	vec_on_unit_sphere = random_unit_vector();
	if (vec3_dot(normal, vec_on_unit_sphere) > 0.0)
		return (vec_on_unit_sphere);
	else
		return (vec3_scale(-1.0, vec_on_unit_sphere));
}

t_vec3	random_in_unit_disk(void)
{
    while (true) {
		t_vec3	p;
        p = new_vec3(random_double(-1, 1), random_double(-1, 1), 0);
        if (vec3_length_squared(p) < 1)
            return p;
    }
}
