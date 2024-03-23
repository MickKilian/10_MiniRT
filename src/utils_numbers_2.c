/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_numbers_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 20:41:26 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/03/23 06:47:44 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

int	is_in_int_range(char *str)
{
	if (ft_strlen(str) > 11 || str2dbl(str) < -2147483648
		|| str2dbl(str) > 2147483647)
		return (0);
	return (1);
}

int	is_in_range01(double num)
{
	if (num < 0.0 || num > 1.0)
		return (0);
	return (1);
}

int	is_in_range0180(double num)
{
	if (num < 0.0 || num > 180.0)
		return (0);
	return (1);
}
