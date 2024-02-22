/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_types_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 07:40:44 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/02/22 06:44:24 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

int	parse_dbl_vec3(char *str, t_vec3 *vec)
{
	char	**params;
	int		i;

	i = 0;
	params = ft_split(str, ',');
	while (params && params[i])
	{
		if (!is_dec(params[i++]))
		{
			free(params);
			return (display_error(ERR_DEC));
		}
	}
	if (array_size(params) != 3)
	{
		free(params);
		return (display_error_plus(ERR_NB_COMPS_VEC, str));
	}
	vec->x = str2dbl(params[0]);
	vec->y = str2dbl(params[1]);
	vec->z = str2dbl(params[2]);
	free(params);
	return (0);
}

int	parse_color(char *str, t_vec3 *color)
{
	char	**params;
	int		i;
	char	*msg;

	i = 0;
	params = ft_split(str, ',');
	while (params && params[i])
	{
		if (!is_long(params[i]) || !is_valid_color_comp(params[i++]))
		{
			msg = params[i - 1];
			free(params);
			return (display_error_plus(ERR_INVALID_COLOR_COMP, msg));
		}
	}
	if (array_size(params) != 3)
	{
		free(params);
		return (display_error_plus(ERR_NB_COMPS_COLOR, str));
	}
	color->x = ft_atoi(params[0]);
	color->y = ft_atoi(params[1]);
	color->z = ft_atoi(params[2]);
	free(params);
	return (0);
}
