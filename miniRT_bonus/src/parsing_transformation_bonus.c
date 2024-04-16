/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_transformation_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 07:40:44 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/04/08 23:55:21 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt_bonus.h"

int	parse_translation(t_rt *rt)
{
	if (check_nb_params(rt, NB_PARAMS_TRANSLATION, ERR_PARAMS_TRANSLATION))
		return (1);
	else if (parse_dbl_vec3(rt->tp.params[++rt->tp.count], &rt->tp.trsf.tra))
		return (1);
	geom_translate(rt);
	return (0);
}

int	parse_rotation(t_rt *rt)
{
	if (check_nb_params(rt, NB_PARAMS_ROTATION, ERR_PARAMS_ROTATION))
		return (1);
	else if (parse_dbl_vec3(rt->tp.params[++rt->tp.count], &rt->tp.trsf.rot_ax))
		return (1);
	else if (parse_dbl(rt->tp.params[++rt->tp.count], &rt->tp.trsf.rot_an))
		return (1);
	rt->tp.trsf.rot_ax = vec3_unit(rt->tp.trsf.rot_ax);
	rt->tp.trsf.rot_an = deg2rad(rt->tp.trsf.rot_an);
	geom_rotate(rt);
	return (0);
}
