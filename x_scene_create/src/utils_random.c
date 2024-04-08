/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_random.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 02:32:41 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/03/17 06:44:54 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/scene_create.h"

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
        p = new_vec3(random_double_interval(-1, 1), random_double_interval(-1, 1), 0);
        if (vec3_length_squared(p) < 1)
            return p;
    }
}

void	random_dice(t_rt *rt, t_vec3 center, double size, t_vec3 color)
{
	int		val;
	t_vec3	dir_1;
	t_vec3	dir_2;
	double	angle;

	val = (int)trunc(random_double_interval(1,7));
	angle = random_double_interval(0,360);
	switch (val)
	{
		case 1:
			dir_1 = new_vec3(0,0,1);
			dir_2 = new_vec3(0,1,0);
			break;
		case 2:
			dir_1 = new_vec3(0,1,0);
			dir_2 = new_vec3(0,0,1);
			break;
		case 3:
			dir_1 = new_vec3(1,0,0);
			dir_2 = new_vec3(0,1,0);
			break;
		case 4:
			dir_1 = new_vec3(0,1,0);
			dir_2 = new_vec3(1,0,0);
			break;
		case 5:
			dir_1 = new_vec3(1,0,0);
			dir_2 = new_vec3(0,0,-1);
			break;
		case 6:
			dir_1 = new_vec3(0,0,-1);
			dir_2 = new_vec3(1,0,0);
			break;
	}
	set_dice(rt, center, dir_1, dir_2, size);
	//set_dielec(rt, color, 1.5);
	set_lamber(rt, color);
	set_rot(rt, new_vec3(0,0,1), angle);
	write_str(rt, "\n");
}
