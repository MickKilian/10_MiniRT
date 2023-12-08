/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 09:50:07 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/12/08 11:17:29 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ray_tracing.h"

int	parse_ambient_params(t_rt *rt, char *line)
{
	t_vec3	background_rgb;
	char	**params;

	printf("line = %s\n", line);
	params = ft_split(line, ' ');
	params = ft_split(params[2], ',');
	printf("params : %s, %s, %s\n", params[0], params[1], params[2]);
	background_rgb = new_vec3(ft_atoi(params[0]), ft_atoi(params[1]), ft_atoi(params[2]));
	printf("background : %d, %d, %d\n", ft_atoi(params[0]), ft_atoi(params[1]), ft_atoi(params[2]));
	rt->cam.background = rgb2vec(background_rgb);
	printf("background : %f, %f, %f\n", rt->cam.background.x, rt->cam.background.y, rt->cam.background.z);
	rt->ambient.set = 1;
	return (0);
}

int	parse_light_params(t_rt *rt, char *line)
{
	rt->light.set = 1;
	(void)line;
	return (0);
}

int	parse_camera_params(t_rt *rt, char *line)
{
	rt->cam.set = 1;
	(void)line;
	return (0);
}
