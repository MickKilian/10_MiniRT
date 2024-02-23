/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 09:50:07 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/02/23 17:54:01 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

int	parse_resolution_params(t_rt *rt)
{
	double	width;
	double	height;

	if (rt->p_avail < NB_PARAMS_RESOLUTION || rt->p_avail > NB_PARAMS_RESOLUTION + 1)
	{
		free(rt->temp_params);
		return (display_error_plus(ERR_NB_PARAMS_RESOLUTION, ft_itoa(NB_PARAMS_RESOLUTION - 1)));
	}
	if (parse_int_pos(rt->temp_params[1], &width))
		return (1);
	if (rt->p_avail > NB_PARAMS_RESOLUTION) {
		if (parse_int_pos(rt->temp_params[2], &height))
			return (1);
	}
	else
		height = width / ASPECT_RATIO;
	rt->img_width = (int)width;
	rt->img_height = (int)height;
	rt->aspect_ratio = (double)rt->img_height/(double)rt->img_height;
	rt->set_resolution = 1;
	if (rt->temp_params)
		free(rt->temp_params);
	return (0);
}

int	parse_algo_params(t_rt *rt)
{
	double	spp;
	double	depth;

	if (rt->p_avail != NB_PARAMS_ALGO)
	{
		free(rt->temp_params);
		return (display_error_plus(ERR_NB_PARAMS_ALGO, ft_itoa(NB_PARAMS_ALGO - 1)));
	}
	if (parse_int_pos(rt->temp_params[1], &spp))
		return (1);
	if (parse_int_pos(rt->temp_params[2], &depth))
		return (1);
	rt->cam.samples_per_pixel = (int)spp;
	rt->cam.max_depth = (int)depth;
	rt->set_algo = 1;
	if (rt->temp_params)
		free(rt->temp_params);
	return (0);
}

int	parse_ambient_params(t_rt *rt)
{
	if (rt->p_avail != NB_PARAMS_AMBIENT_LIGHT)
	{
		free(rt->temp_params);
		return (display_error_plus(ERR_NB_PARAMS_AMBIENT, ft_itoa(NB_PARAMS_AMBIENT_LIGHT - 1)));
	}
	if (parse_dbl_01(rt->temp_params[1], &rt->ambient.ratio))
		return (1);
	if (parse_color(rt->temp_params[2], &rt->temp_color))
		return (1);
	rt->ambient.color = rgb2vec(rt->temp_color);
	rt->ambient.set = 1;
	if (rt->temp_params)
		free(rt->temp_params);
	return (0);
}

int	parse_light_params(t_rt *rt)
{
	if (rt->p_avail != NB_PARAMS_LIGHT)
	{
		free(rt->temp_params);
		return (display_error_plus(ERR_NB_PARAMS_LIGHT, ft_itoa(NB_PARAMS_LIGHT - 1)));
	}
	if (parse_dbl_vec3(rt->temp_params[1], &rt->light.pos))
		return (1);
	if (parse_dbl_01(rt->temp_params[2], &rt->light.ratio))
		return (1);
	if (parse_color(rt->temp_params[3], &rt->temp_color))
		return (1);
	rt->light.color = rgb2vec(rt->temp_color);
	rt->light.set = 1;
	if (rt->temp_params)
		free(rt->temp_params);
	return (0);
}

int	parse_camera_params(t_rt *rt)
{
	if (rt->p_avail != NB_PARAMS_CAMERA)
	{
		free(rt->temp_params);
		return (display_error_plus(ERR_NB_PARAMS_CAMERA, ft_itoa(NB_PARAMS_CAMERA - 1)));
	}
	if (parse_dbl_vec3(rt->temp_params[1], &rt->cam.center))
		return (1);
	if (parse_dbl_vec3(rt->temp_params[2], &rt->cam.dir))
		return (1);
	if (parse_dbl_0180(rt->temp_params[3], &rt->cam.hfov))
		return (1);
	rt->cam.set = 1;
	if (rt->temp_params)
		free(rt->temp_params);
	return (0);
}
