/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 20:41:26 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/02/22 01:25:24 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

int	is_digit(char c) {
	if (c < 48 || c > 57)
		return (0);
	else
		return (1);
}

int	is_dec(char *str) {
	while (*str) {
		if (!is_digit(*str) && *str != '-' && *str != '.')
			return (0);
		str++;
	}
	return (1);
}

int	is_ulong(char *str) {
	while (*str) {
		if (!is_digit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	is_long(char *str) {
	if (*str == '-')
		str++;
	while (*str) {
		if (!is_digit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	is_valid_color_comp(char *str) {
	if (ft_atoi(str) < 0 || ft_atoi(str) > 255)
		return (0);
	return (1);
}

int	 is_in_int_range(char *str) {
	if (ft_strlen(str) > 11 || str2dbl(str) < -2147483648 || str2dbl(str) > 2147483647)
		return (0);
	return (1);
}

int	is_in_range01 (double num)
{
	if (num < 0.0 || num > 1.0)
		return (0);
	return (1);
}

int	is_in_range0180 (double num)
{
	if (num < 0.0 || num > 180.0)
		return (0);
	return (1);
}
