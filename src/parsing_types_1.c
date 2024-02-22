/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_types_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 07:40:44 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/02/22 03:34:54 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

int	parse_dbl(char *str, double *num)
{
	if (!is_dec(str))
		return (display_error(ERR_DEC));
	*num = str2dbl(str);
	return (0);
}

int	parse_dbl_01(char *str, double *num)
{
	if (!is_dec(str))
		return (display_error(ERR_DEC));
	*num = str2dbl(str);
	if (!is_in_range01(*num))
		return (display_error_plus(ERR_OUT_OF_RATIO, str));
	return (0);
}

int	parse_dbl_0180(char *str, double *num)
{
	if (!is_dec(str))
		return (display_error(ERR_DEC));
	*num = str2dbl(str);
	if (!is_in_range0180(*num))
		return (display_error_plus(ERR_OUT_OF_VIEW_ANGLE, str));
	return (0);
}
