/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_types_3_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 07:40:44 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/04/10 11:04:10 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt_bonus.h"

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

bool	is_rt_file(char *file_path)
{
	size_t	path_length;

	path_length = ft_strlen(file_path) - 3;
	if (path_length)
		return (ft_strncmp(file_path + path_length, ".rt", 3) == 0);
	return (0);
}

bool	is_xpm_file(char *file_path)
{
	size_t	path_length;

	path_length = ft_strlen(file_path) - 4;
	if (path_length)
		return (ft_strncmp(file_path + path_length, ".xpm", 4) == 0);
	return (0);
}
