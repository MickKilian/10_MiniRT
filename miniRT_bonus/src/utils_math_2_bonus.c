/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_math_2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 20:41:26 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/04/07 15:20:25 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt_bonus.h"

double	ft_abs(double a)
{
	if (a < 0)
		a = a * (-1);
	return (a);
}

double	ft_modulo(double x, double y)
{
	int	res;

	res = (int)(x / y);
	if (y)
		return (x - res * y);
	else
		return (-1);
}

int	next_modulo(int x, int mod)
{
	return ((x + 1) % mod);
}
