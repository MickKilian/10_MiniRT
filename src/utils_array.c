/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 20:41:26 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/02/12 03:57:26 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

double	array_size(char **params)
{
	int	count;

	count = 0;
	while (*params && **params) {
		count++;
		params++;
	}
	return (count);
}
