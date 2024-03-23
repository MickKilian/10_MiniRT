/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 05:34:23 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/03/22 14:07:16 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

void	mat_create(t_rt *rt)
{
	if (!rt->tp_mat)
		rt->tp_mat = mat_lamber(lamber(rgb2vec(rt->tp_color)));
}

t_material	*duplicate_mat(t_material *src)
{
	t_material	*dest;

	dest = ft_calloc(1, sizeof(t_material));
	dest = memcpy(dest, src, sizeof(t_material));
	return (dest);
}
