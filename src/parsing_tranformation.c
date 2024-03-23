/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tranformation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 07:40:44 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/03/23 09:42:54 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

int	parse_translation(t_rt *rt)
{
	if (check_nb_params(rt, NB_PARAMS_TRANSLATION, ERR_PARAMS_TRANSLATION))
		return (1);
	else if (parse_dbl_vec3(rt->tp_params[++rt->tp_count], &rt->tp_trsf.tra))
		return (1);
	geom_translate(rt);
	return (0);
}

int	parse_rotation(t_rt *rt)
{
	if (check_nb_params(rt, NB_PARAMS_ROTATION, ERR_PARAMS_ROTATION))
		return (1);
	else if (parse_dbl_vec3(rt->tp_params[++rt->tp_count], &rt->tp_trsf.rot_ax))
		return (1);
	else if (parse_dbl(rt->tp_params[++rt->tp_count], &rt->tp_trsf.rot_an))
		return (1);
	rt->tp_trsf.rot_ax = vec3_unit(rt->tp_trsf.rot_ax);
	rt->tp_trsf.rot_an = deg2rad(rt->tp_trsf.rot_an);
	geom_rotate(rt);
	return (0);
}
