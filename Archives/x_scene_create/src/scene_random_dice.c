/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_random_dice.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:23:39 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/03/17 15:07:40 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/scene_create.h"

void	n_random_dice(t_rt *rt)
{
	// Set environment parameters
	set_resol(rt, 1000);
	write_str(rt, "\n");
	set_algo(rt, 1, 20);
	write_str(rt, "\n");
	set_ambient(rt, 1, new_vec3(255,255,255));
	write_str(rt, "\n");
	set_cam(rt, new_vec3(0,-10,5), new_vec3(0,9,-5), 80);
	write_str(rt, "\n");
	write_str(rt, "\n");
	// Set httbl elements
	set_sphere(rt, new_vec3(0,0,-1000), 1000);
	set_lamber(rt, new_vec3(255,255,150);
	write_str(rt, "\n");
	set_disc(rt, new_vec3(0,0,0), new_vec3(0,0,1), 5.3);
	set_lamber(rt, new_vec3(0,10,0));
	write_str(rt, "\n");
	set_disc(rt, new_vec3(0,0,0), new_vec3(0,0,1), 5);
	set_lamber(rt, new_vec3(25,1,5));
	write_str(rt, "\n");
	place_dice(rt, 3);
	set_cone(rt, new_vec3(6.5,3,3), new_vec3(0,0,-1), 1.5, 1, 3);
	set_lamber(rt, new_vec3(0,0,0));
	write_str(rt, "\n");
	set_cone(rt, new_vec3(6.5,3,3), new_vec3(0,0,-1), 1.4, 0.9, 3);
	set_lamber(rt, new_vec3(0,10,0));
	write_str(rt, "\n");
}

t_obj	new_obj(t_vec3 point, double radius)
{
	t_obj	obj;

	obj.center = point;
	obj.radius = radius;
	return (obj);
}

void	place_dice(t_rt *rt, int nb_dice)
{
	int		i;
	t_vec3	p;
	bool	start;

	start = false;
	i = 0;
	while (i < nb_dice)
	{
		while (!start || !try_location(rt, p, 1))
		{
			p = new_vec3(random_double_interval(-5, 5), random_double_interval(-5, 5), 0.5);
			start = true;
		}
		random_dice(rt, p, 1, vec3_prod_comp_by_comp(new_vec3(i % 3 == 0, i % 3 == 1, i % 3 == 2), new_vec3(150,150,150)));
		list_obj_addback(rt, new_list_obj(new_obj(p, 1)));
		i++;
		start = false;
	}
	free_list_obj(rt->list_obj);
}

bool	try_location(t_rt *rt, t_vec3 p, double size)
{
	int		i;
	bool	ret;

	i = 0;
	ret = true;
	if (vec3_length(p) + size > 4)
		ret = false;
	while (ret && i < rt->list_obj_size)
	{
		if (vec3_length(vec3_substract2(rt->list_obj->obj.center, p)) < sqrt(2) * size)
			ret = false;
		i++;
		rt->list_obj = rt->list_obj->next;
	}
	rt->list_obj = rt->list_obj_head;
	return (ret);
}
