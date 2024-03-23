/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 07:40:44 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/03/23 09:43:53 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

int	check_nb_params(t_rt *rt, int expect, char *err_msg)
{
	rt->tp_expect = expect;
	get_end_idx(rt);
	if (sts(itv(rt->tp_expect, rt->tp_expect + rt->tp_option),
			rt->tp_end - rt->tp_count) < 0)
		return (display_error_plus(ERR_TL_PARAMS, err_msg));
	else if (sts(itv(rt->tp_expect, rt->tp_expect + rt->tp_option),
			rt->tp_end - rt->tp_count) > 0)
		return (display_error_plus(ERR_TM_PARAMS, err_msg));
	else
		return (0);
}

void	get_end_idx(t_rt *rt)
{
	rt->tp_end = rt->tp_count;
	while (rt->tp_end + 1 <= rt->tp_avail)
	{
		if (ft_isalpha(rt->tp_params[rt->tp_end + 1][0]))
			break ;
		rt->tp_end++;
	}
	if (rt->tp_params[rt->tp_end + 1])
		rt->tp_extra = true;
	else
		rt->tp_extra = false;
}

void	rt_re_init(t_rt *rt)
{
	rt->tp_expect = 0;
	rt->tp_count = 0;
	rt->tp_avail = 0;
	rt->tp_end = 0;
	rt->tp_option = 0;
	rt->tp_extra = false;
	rt->tp_geom = NULL;
	rt->tp_mat = NULL;
	rt->tp_color = new_vec3(0, 0, 0);
	ft_bzero(&rt->tp_light, sizeof(t_light));
	rt->tp_ret = 0;
	rt->tp_trsf.tra = new_vec3(0, 0, 0);
	rt->tp_trsf.rot_ax = new_vec3(0, 0, 0);
	rt->tp_trsf.rot_an = 0;
}
