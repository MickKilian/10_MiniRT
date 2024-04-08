/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_lights.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 02:50:35 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/04/08 01:25:24 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

t_vec3	point_lights(t_rt *rt, t_hit_rec *rec)
{
	t_vec3		light_intensity;
	t_hit_rec	light_rec;
	t_ray		shadow_ray;
	t_vec3		light_o;
	t_vec3		light_o_diff;
	t_vec3		light_o_spec;
	t_httbl		*light;

	light_o = new_vec3(0, 0, 0);
	light = rt->world.httbl_head;
	rt->cur_httbl = rec->httbl;
	rt->tp_shadow_comp = true;
	while (light)
	{
		if (light->geom->type == POINT)
		{
			shadow_ray = new_ray(vec3_add2(rec->p, vec3_scale(SHADOW_BIAS, rec->nrm)), vec3_sub2(light->geom->pnt.q, rec->p));
			ft_bzero(&light_rec, sizeof(t_hit_rec));
			if (!world_hit(rt, shadow_ray, itv(0.001, 0.95), &light_rec))
			{
				light_intensity = vec3_scale(1.25 / PI, vec3_scale(light->mat->diff_light.ratio, light->mat->diff_light.color));
				light_o_diff = vec3_prd(vec3_scale(1, rec->httbl->mat->color),
						vec3_scale(ft_max(0, vec3_dot(rec->nrm, vec3_unit(shadow_ray.dir))), light_intensity));
				if (vec3_dot(vec3_unit(vec3_sub2(rec->p, rt->cam.ctr)), reflect(vec3_unit(shadow_ray.dir), rec->nrm)) > 0)
					light_o_spec = vec3_scale(ft_max(0, pow(vec3_dot(vec3_unit(vec3_sub2(rec->p, rt->cam.ctr)), reflect(vec3_unit(shadow_ray.dir), rec->nrm)), rec->httbl->mat->light_conc)), light_intensity);
				else
					light_o_spec = new_vec3(0, 0, 0);
				light_o = vec3_add2(light_o, vec3_add2(vec3_scale(rec->httbl->mat->k_d, light_o_diff), vec3_scale(rec->httbl->mat->k_s, light_o_spec)));
			}
		}
		light = light->next;
	}
	rt->tp_shadow_comp = false;
	return (light_o);
}

t_vec3	ray_color_grad_blue(t_ray r)
{
	t_vec3	pixel_color;
	double	a;

	ft_bzero(&pixel_color, sizeof(t_vec3));
	a = 0.5 * (vec3_unit(r.dir).y + 1.0);
	pixel_color = vec3_add2(vec3_scale(1.0 - a, new_vec3(1.0, 1.0, 1.0)),
			vec3_scale(a, new_vec3(0.5, 0.7, 1.0)));
	return (pixel_color);
}
