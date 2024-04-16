/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_lights.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 02:50:35 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/04/10 18:08:06 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

t_vec3	point_lights(t_rt *rt, t_hit_rec *rec)
{
	t_httbl	*httbl;
	t_light	light;

	httbl = rt->world.httbl_head;
	light.o = new_vec3(0, 0, 0);
	rt->cur_httbl = rec->httbl;
	rt->tp.shadow_comp = true;
	while (httbl)
	{
		if (httbl->geom->type == POINT)
			point_lights_comp(rt, rec, httbl, &light);
		httbl = httbl->next;
	}
	rt->tp.shadow_comp = false;
	return (light.o);
}

void	point_lights_comp(t_rt *rt, t_hit_rec *rec, t_httbl *httbl,
		t_light *light)
{
	light->shad_r = new_ray(vec3_add2(rec->p, vec3_scale(SHADOW_BIAS,
					rec->nrm)),
			vec3_sub2(httbl->geom->pnt.q, rec->p));
	ft_bzero(&light->rec, sizeof(t_hit_rec));
	if (!world_hit(rt, light->shad_r, itv(0.001, 0.95), &light->rec))
		p_lights_inside(rt, rec, httbl, light);
}

void	p_lights_inside(t_rt *rt, t_hit_rec *rec, t_httbl *httbl,
		t_light *light)
{
	light->intensity = vec3_scale(1.25 / PI, vec3_scale(
				httbl->mat->diff_light.ratio, httbl->mat->diff_light.color));
	light->o_diff = vec3_prd(vec3_scale(1, rec->col),
			vec3_scale(ft_max(0, vec3_dot(rec->nrm,
						vec3_unit(light->shad_r.dir))), light->intensity));
	if (vec3_dot(vec3_unit(vec3_sub2(rec->p, rt->cam.ctr)),
			reflect(vec3_unit(light->shad_r.dir), rec->nrm)) > 0)
		light->o_spec = vec3_scale(ft_max(0,
					pow(vec3_dot(vec3_unit(vec3_sub2(rec->p, rt->cam.ctr)),
							reflect(vec3_unit(light->shad_r.dir), rec->nrm)),
						rec->httbl->mat->light_conc)), light->intensity);
	else
		light->o_spec = new_vec3(0, 0, 0);
	light->o = vec3_add2(light->o, vec3_add2(vec3_scale(rec->httbl->mat->k_d,
					light->o_diff), vec3_scale(rec->httbl->mat->k_s,
					light->o_spec)));
}
