/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_geom_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 09:49:27 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/04/08 06:31:43 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

int	parse_pencil(t_rt *rt)
{
	t_vec3	b_ctr;
	t_vec3	gen;
	double	length;

	if (parse_dbl_vec3(rt->tp_params[++rt->tp_count], &b_ctr))
		return (1);
	else if (parse_dbl_vec3_n1_1_norm(rt->tp_params[++rt->tp_count], &gen))
		return (1);
	else if (parse_dbl_pos(rt->tp_params[++rt->tp_count], &length))
		return (1);
	else if (parse_color(rt->tp_params[++rt->tp_count], &rt->tp_color))
		return (1);
	rt->tp_geom = geom_pencil(pencil(b_ctr, gen, length));
	return (0);
}
