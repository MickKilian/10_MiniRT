/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_types_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 07:40:44 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/04/09 23:22:10 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

int	parse_color(char *str, t_vec3 *color)
{
	char	**params;
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	params = ft_split(str, ',');
	while (!ret && params && params[i])
	{
		if (!is_long(params[i]) || !is_valid_color_comp(params[i]))
			ret = display_error_plus(ERR_INVALID_COLOR_COMP, params[i]);
		i++;
	}
	if (!ret && i != 3)
		ret = display_error_plus(ERR_NB_COMPS_COLOR, str);
	if (!ret)
	{
		color->x = ft_atoi(params[0]);
		color->y = ft_atoi(params[1]);
		color->z = ft_atoi(params[2]);
	}
	free_split_vec(params);
	return (ret);
}

int	parse_pat(char *str, int *num)
{
	if (!is_long(str) || str2dbl(str) < 0 || str2dbl(str) >= LEN_PAT_TYPES)
		return (display_error_plus(ERR_PAT, str));
	*num = str2dbl(str);
	return (0);
}
