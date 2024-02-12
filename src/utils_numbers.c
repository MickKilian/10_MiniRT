/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 20:41:26 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/02/12 06:34:11 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

int	is_digit(char c) {
	if (c < 48 || c > 57)
		return (0);
	else
		return (1);
}

int	is_double(char *str) {
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
