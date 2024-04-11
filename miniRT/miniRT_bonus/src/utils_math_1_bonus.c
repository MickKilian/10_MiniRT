/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_math_1_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 20:41:26 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/04/07 15:27:44 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt_bonus.h"

double	ft_min(double n1, double n2)
{
	if (n1 <= n2)
		return (n1);
	else
		return (n2);
}

double	ft_max(double n1, double n2)
{
	if (n1 >= n2)
		return (n1);
	else
		return (n2);
}

double	ft_min3(double n1, double n2, double n3)
{
	return (ft_min(ft_min(n1, n2), n3));
}

double	ft_max3(double n1, double n2, double n3)
{
	return (ft_max(ft_max(n1, n2), n3));
}
