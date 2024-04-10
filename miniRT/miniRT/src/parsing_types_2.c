/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_types_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 07:40:44 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/04/09 23:41:44 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

int	parse_dbl_0180(char *str, double *num)
{
	if (!is_dec(str))
		return (display_error_plus(ERR_DEC, str));
	*num = str2dbl(str);
	if (!is_in_range0180(*num))
		return (display_error_plus(ERR_OUT_OF_VIEW_ANGLE, str));
	return (0);
}

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
			ret = display_error_plus(ERR_DEC, params[i]);
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
		if ((!is_dec(params[i]) && display_error_plus(ERR_DEC, params[i]))
			|| (!is_in_range_n1_1(str2dbl(params[i++]))
				&& display_error_plus(ERR_OUT_OF_N1_1, params[i - 1])))
			ret = 1;
	if (!ret && i != 3)
		ret = display_error_plus(ERR_NB_COMPS_VEC, str);
	if (!ret && vec3_len(new_vec3(str2dbl(params[0]),
				str2dbl(params[1]), str2dbl(params[2]))) != 1)
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
