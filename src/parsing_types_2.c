/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_types_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 07:40:44 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/04/08 03:56:42 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

int	parse_dbl_vec3(char *str, t_vec3 *vec)
{
	char	**params;
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	params = ft_split(str, ',');
	while (!ret && params && params[i])
	{
		if (!is_dec(params[i++]))
			ret = display_error_plus(ERR_DEC, params[i - 1]);
	}
	if (!ret && i != 3)
		ret = display_error_plus(ERR_NB_COMPS_VEC, str);
	if (!ret)
	{
		vec->x = str2dbl(params[0]);
		vec->y = str2dbl(params[1]);
		vec->z = str2dbl(params[2]);
	}
	free_split_vec(params);
	return (ret);
}

int	parse_dbl_vec3_n1_1(char *str, t_vec3 *vec)
{
	char	**params;
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	params = ft_split(str, ',');
	while (!ret && params && params[i])
	{
		if (!is_dec(params[i]))
			ret = display_error_plus(ERR_DEC, params[i - 1]);
		if (!is_in_range_n1_1(str2dbl(params[i++])))
			ret = display_error_plus(ERR_OUT_OF_N1_1, params[i - 1]);
	}
	if (!ret && i != 3)
		ret = display_error_plus(ERR_NB_COMPS_VEC, str);
	if (!ret)
	{
		vec->x = str2dbl(params[0]);
		vec->y = str2dbl(params[1]);
		vec->z = str2dbl(params[2]);
	}
	free_split_vec(params);
	return (ret);
}

int	parse_dbl_vec3_n1_1_norm(char *str, t_vec3 *vec)
{
	char	**params;
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	params = ft_split(str, ',');
	while (!ret && params && params[i])
	{
		if (!is_dec(params[i]))
			ret = display_error_plus(ERR_DEC, params[i - 1]);
		if (!is_in_range_n1_1(str2dbl(params[i++])))
			ret = display_error_plus(ERR_OUT_OF_N1_1, params[i - 1]);
	}
	if (!ret && i != 3)
		ret = display_error_plus(ERR_NB_COMPS_VEC, str);
	if (!ret && vec3_len(new_vec3(str2dbl(params[0]), str2dbl(params[1]), str2dbl(params[2]))) != 1)
		ret = display_error_plus(ERR_NORMALIZED, str);
	if (!ret)
	{
		vec->x = str2dbl(params[0]);
		vec->y = str2dbl(params[1]);
		vec->z = str2dbl(params[2]);
	}
	free_split_vec(params);
	return (ret);
}

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
		if (!is_long(params[i]) || !is_valid_color_comp(params[i++]))
			ret = display_error_plus(ERR_INVALID_COLOR_COMP, params[i - 1]);
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
	if (!is_long(str) || str2dbl(str) >= LEN_PAT_TYPES)
		return (display_error_plus(ERR_PAT, str));
	*num = str2dbl(str);
	return (0);
}
