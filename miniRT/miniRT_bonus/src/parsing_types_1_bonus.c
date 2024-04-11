/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_types_1_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 07:40:44 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/04/09 19:37:42 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt_bonus.h"

int	parse_dbl(char *str, double *num)
{
	if (!is_dec(str))
		return (display_error_plus(ERR_DEC, str));
	*num = str2dbl(str);
	return (0);
}

int	parse_dbl_pos(char *str, double *num)
{
	if (!is_dec(str))
		return (display_error_plus(ERR_DEC, str));
	*num = str2dbl(str);
	if (*num < 0)
		return (display_error_plus(ERR_NEGATIVE_NUM, str));
	return (0);
}

int	parse_int_pos(char *str, double *num)
{
	if (!is_long(str))
		return (display_error_plus(ERR_INT, str));
	*num = str2dbl(str);
	if (*num <= 0)
		return (display_error_plus(ERR_NEGATIVE_NUM, str));
	return (0);
}

int	parse_dbl_01(char *str, double *num)
{
	if (!is_dec(str))
		return (display_error_plus(ERR_DEC, str));
	*num = str2dbl(str);
	if (!is_in_range01(*num))
		return (display_error_plus(ERR_OUT_OF_01, str));
	return (0);
}

int	parse_dbl_n1_1(char *str, double *num)
{
	if (!is_dec(str))
		return (display_error_plus(ERR_DEC, str));
	*num = str2dbl(str);
	if (!is_in_range_n1_1(*num))
		return (display_error_plus(ERR_OUT_OF_N1_1, str));
	return (0);
}
