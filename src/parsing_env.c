/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 09:50:07 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/02/12 07:05:54 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

int	parse_ambient_params(t_rt *rt, char *line, int nb_params)
{
	char	**params;
	t_vec3	background_color;

	params = ft_split(line, ' ');
	if (array_size(params) != nb_params)
	{
		free(params);
		return (display_error(ERR_NB_PARAMS_AMBIENT));
	}
	if (parse_color(params[2], &background_color))
		return (1);
	rt->cam.background = rgb2vec(background_color);
	rt->ambient.set = 1;
	if (params)
		free(params);
	return (0);
}

int	parse_light_params(t_rt *rt, char *line, int nb_params)
{
	char	**params;

	params = ft_split(line, ' ');
	if (array_size(params) != nb_params)
	{
		free(params);
		return (display_error(ERR_NB_PARAMS_LIGHT));
	}
	rt->light.set = 1;
	(void)line;
	if (params)
		free(params);
	return (0);
}

int	parse_camera_params(t_rt *rt, char *line, int nb_params)
{
	char	**params;

	params = ft_split(line, ' ');
	if (array_size(params) != nb_params)
	{
		free(params);
		return (display_error(ERR_NB_PARAMS_CAMERA));
	}
	if (parse_dbl_vec3(params[1], &rt->cam.center))
		return (1);
	if (parse_dbl_vec3(params[2], &rt->cam.dir))
		return (1);
	if (parse_dbl(params[3], &rt->cam.hfov))
		return (1);
	rt->cam.set = 1;
	if (params)
		free(params);
	return (0);
}
