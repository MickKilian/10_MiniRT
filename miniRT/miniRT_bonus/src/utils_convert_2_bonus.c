/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_convert_2_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 20:41:26 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/03/23 06:37:09 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt_bonus.h"

double	str2dbl(char *str)
{
	double	ret;
	double	dec;
	double	rank;
	double	sign;

	dec = 0.0;
	rank = 1.0;
	sign = 1.0;
	ret = (double)ft_atoi(str);
	if (*str && *str == '-')
		sign = -1.0;
	while (*str && *str != '.')
		str++;
	if (*str++ == '.')
	{
		while (*str >= '0' && *str <= '9')
		{
			rank *= 10.0;
			dec += (double)(*str - '0') / rank;
			str++;
		}
		ret += dec * sign;
	}
	return (ret);
}

int	dec2bin(int dec, int bin, int pos)
{
	if (!dec)
		return (bin);
	return (dec2bin(dec / 2, dec % 2 * pos + bin, 10 * pos));
}
