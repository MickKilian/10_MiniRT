/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_lights.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 02:50:35 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/04/06 00:55:09 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

t_vec3	reflected_lights(t_rt *rt, t_hit_rec *rec)
{
	t_hit_rec	light_rec;
	t_ray		shadow_ray;
	t_vec3		light_o;
	t_vec3		light_i;
	t_httbl		*light;

	light_o = new_vec3(0, 0, 0);
	light = rt->world.httbl_head;
	//display_vec3(rec->p);
	//printf(" %d ", rec->geom_type);
	//printf("size : %ld\n", rt->world.size);
	rt->cur_httbl = rec->httbl;
	rt->tp_shadow_comp = true;
	while (light)
	{
		if (light->geom->type == POINT)
		{
			//printf("NOW\n");
			//if (rec->p.y > -2 && rec->nrm.x == 0)
			//{
			//	display_vec3(rec->p);
			//	display_vec3(vec3_add2(rec->p, vec3_scale(SHADOW_BIAS, rec->nrm)));
			//	printf("\n");
			//}
			shadow_ray = new_ray(vec3_add2(rec->p, vec3_scale(SHADOW_BIAS, rec->nrm)), vec3_sub2(light->geom->pnt.q, rec->p));
			ft_bzero(&light_rec, sizeof(t_hit_rec));
			//printf("SHADOW : ");
		//	if (rec->p.y > 0)
		//		printf("in light : %f %d\n", rec->p.y, rt->world.httbl->geom->type);
			if (!world_hit(rt, shadow_ray, itv(0.001, 0.95), &light_rec))
			{
				//display_vec3(light_ray.orig);
				//printf(" ");
			//light_i = vec3_scale(light->mat->diff_light.ratio / (4 * PI *
			//				vec3_len_sq(vec3_sub2(rec->p, light->geom->pnt.q)))
			//				, light->mat->diff_light.color);
			light_i = vec3_scale(light->mat->diff_light.ratio, light->mat->diff_light.color);
			light_o = vec3_add2(light_o,
					vec3_prd(vec3_scale(1 / PI, rec->lamber.color),
						vec3_scale(ft_max(0, vec3_dot(rec->nrm, vec3_unit(shadow_ray.dir))), light_i)));
			//light_i = vec3_scale(light->mat->diff_light.ratio / (4 * PI * vec3_len_sq(shadow_ray.dir)), light->mat->diff_light.color);
			//light_i = vec3_scale(light->mat->diff_light.ratio, light->mat->diff_light.color);
			//light_o = vec3_add2(light_o,
			//		vec3_scale(ft_max(0, vec3_dot(rec->nrm, vec3_unit(shadow_ray.dir))),
			//				light_i));
			//	display_vec3(rec->lamber.color);
			//	printf(" ");
			//	display_vec3(rt->world.httbl->mat->diff_light.color);
			//	printf("\n");
				//display_vec3(light_color);
				//printf(" ");
				//printf("t : %f\n", light_rec.t);
			}
			else
			{
			//	if (light_rec.httbl == rec->httbl && light_rec.t < 0.999)
			//	{
			//		printf("%d ", rec->httbl->geom->type);
			//		printf("t : %f\n", light_rec.t);
			//	}
				//display_vec3(light_color);
				//printf(" ");
				//printf("t : %f\n", light_rec.t);

			}
		}
		light = light->next;
	}
	rt->tp_shadow_comp = false;
	//printf(" ");
	//display_vec3(light_color);
	//printf("\n");
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
