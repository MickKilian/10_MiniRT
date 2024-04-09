/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_geom_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 09:49:27 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/04/08 23:56:23 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

int	parse_pencil(t_rt *rt)
{
	t_vec3	b_ctr;
	t_vec3	gen;
	double	length;

	if (parse_dbl_vec3(rt->tp.params[++rt->tp.count], &b_ctr))
		return (1);
	else if (parse_dbl_vec3_n1_1_norm(rt->tp.params[++rt->tp.count], &gen))
		return (1);
	else if (parse_dbl_pos(rt->tp.params[++rt->tp.count], &length))
		return (1);
	else if (parse_color(rt->tp.params[++rt->tp.count], &rt->tp.color))
		return (1);
	rt->tp.geom = geom_pencil(pencil(b_ctr, gen, length));
	return (0);
}
