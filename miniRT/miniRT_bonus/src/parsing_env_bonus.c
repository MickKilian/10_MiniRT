/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_env_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 09:50:07 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/04/10 22:29:00 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt_bonus.h"

int	parse_resolution_params(t_rt *rt)
{
	double	w;
	double	h;

	rt->tp.option = 1;
	if ((rt->set_resolution && display_error(ERR_DUPLICATE_RESOLUTION))
		|| check_nb_params(rt, NB_PARAMS_RESOLUTION, ERR_PARAMS_RESOLUTION)
		|| (rt->tp.extra && display_error_plus(ERR_EXTRA_INFO,
				rt->tp.params[rt->tp.count])))
		return (1);
	else if (parse_int_pos(rt->tp.params[++rt->tp.count], &w))
		return (1);
	else if (rt->tp.count < rt->tp.end)
	{
		if (parse_int_pos(rt->tp.params[++rt->tp.count], &h))
			return (1);
	}
	else
		h = w / ASPECT_RATIO;
	rt->img.w = (int)w;
	rt->img.h = (int)h;
	rt->aspect_ratio = (double)rt->img.w / (double)rt->img.h;
	rt->set_resolution = 1;
	rt->tp.option = 0;
	return (0);
}

int	parse_algo_params(t_rt *rt)
{
	double	spp;
	double	depth;

	if ((rt->set_algo && display_error(ERR_DUPLICATE_ALGO))
		|| check_nb_params(rt, NB_PARAMS_ALGO, ERR_PARAMS_ALGO)
		|| (rt->tp.extra && display_error_plus(ERR_EXTRA_INFO,
				rt->tp.params[rt->tp.count])))
		return (1);
	else if (parse_int_pos(rt->tp.params[++rt->tp.count], &spp))
		return (1);
	else if (parse_int_pos(rt->tp.params[++rt->tp.count], &depth))
		return (1);
	rt->spp = (int)spp;
	rt->max_depth = (int)depth;
	rt->set_algo = 1;
	return (0);
}

int	parse_ambient_params(t_rt *rt)
{
	if ((rt->ambient.set && display_error(ERR_DUPLICATE_AMBIENT))
		|| check_nb_params(rt, NB_PARAMS_AMBIENT, ERR_PARAMS_AMBIENT)
		|| (rt->tp.extra && display_error_plus(ERR_EXTRA_INFO,
				rt->tp.params[rt->tp.count])))
		return (1);
	else if (parse_dbl_01(rt->tp.params[++rt->tp.count],
			&rt->ambient.ratio))
		return (1);
	else if (parse_color(rt->tp.params[++rt->tp.count], &rt->tp.color))
		return (1);
	rt->ambient.color = rgb2vec(rt->tp.color);
	rt->ambient.set = 1;
	return (0);
}

int	parse_light_params(t_rt *rt)
{
	if ((!MULTI_LIGHTS && rt->set_point_light
			&& display_error(ERR_DUPLICATE_PT_LIGHT))
		|| check_nb_params(rt, NB_PARAMS_POINT_LIGHT, ERR_PARAMS_POINT_LIGHT)
		|| (rt->tp.extra && display_error_plus(ERR_EXTRA_INFO,
				rt->tp.params[rt->tp.count])))
		return (1);
	else if (parse_dbl_vec3(rt->tp.params[++rt->tp.count],
			&rt->tp.light.pos))
		return (1);
	else if (parse_dbl_01(rt->tp.params[++rt->tp.count],
			&rt->tp.light.ratio))
		return (1);
	else if (parse_color(rt->tp.params[++rt->tp.count], &rt->tp.color))
		return (1);
	if (!MULTI_LIGHTS)
		rt->tp.light.color = new_vec3(1, 1, 1);
	else
		rt->tp.light.color = rgb2vec(rt->tp.color);
	rt->set_point_light = 1;
	rt->tp.geom = geom_point(point(rt->tp.light.pos));
	rt->tp.mat = mat_diff_light(rt->tp, diff_light(rt->tp.light.ratio,
				rt->tp.light.color));
	return (0);
}

int	parse_camera_params(t_rt *rt)
{
	if ((rt->cam.set && display_error(ERR_DUPLICATE_CAMERA))
		|| check_nb_params(rt, NB_PARAMS_CAMERA, ERR_PARAMS_CAMERA)
		|| (rt->tp.extra && display_error_plus(ERR_EXTRA_INFO,
				rt->tp.params[rt->tp.count])))
		return (1);
	else if (parse_dbl_vec3(rt->tp.params[++rt->tp.count], &rt->cam.ctr))
		return (1);
	else if (parse_dbl_vec3(rt->tp.params[++rt->tp.count], &rt->cam.dir))
		return (1);
	else if (parse_dbl_0180(rt->tp.params[++rt->tp.count], &rt->cam.hfov))
		return (1);
	rt->cam.set = 1;
	return (0);
}
