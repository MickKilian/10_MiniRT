/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_lambertian.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 03:18:48 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/02/23 16:41:30 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

t_lamber	lamber(t_vec3 color)
{
	t_lamber	lamber;

	lamber.color = color;
	return (lamber);
}
