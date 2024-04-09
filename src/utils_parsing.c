/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 07:40:44 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/04/09 00:20:07 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

int	check_nb_params(t_rt *rt, int expect, char *err_msg)
{
	rt->tp.expect = expect;
	get_end_idx(rt);
	if (sts(itv(rt->tp.expect, rt->tp.expect + rt->tp.option),
			rt->tp.end - rt->tp.count) < 0)
		return (display_error_plus(ERR_TL_PARAMS, err_msg));
	else if (sts(itv(rt->tp.expect, rt->tp.expect + rt->tp.option),
			rt->tp.end - rt->tp.count) > 0)
		return (display_error_plus(ERR_TM_PARAMS, err_msg));
	else
		return (0);
}

void	get_end_idx(t_rt *rt)
{
	rt->tp.end = rt->tp.count;
	while (rt->tp.end + 1 <= rt->tp.avail)
	{
		if (ft_isalpha(rt->tp.params[rt->tp.end + 1][0]))
			break ;
		rt->tp.end++;
	}
	if (rt->tp.params[rt->tp.end + 1])
		rt->tp.extra = true;
	else
		rt->tp.extra = false;
}

void	free_tp(t_temp tp)
{
	if (tp.geom)
		free(tp.geom);
	if (tp.mat)
		free(tp.mat);
//	if (tp.txm_path)
//		free(tp.txm_path);
//	if (tp.bmp_path)
//		free(tp.bmp_path);
}

void	rt_re_init(t_rt *rt)
{
	ft_bzero(&rt->tp, sizeof(t_temp));
//	rt->tp_expect = 0;
//	rt->tp_count = 0;
//	rt->tp_avail = 0;
//	rt->tp_end = 0;
//	rt->tp_option = 0;
//	rt->tp_extra = false;
//	rt->tp_geom = NULL;
//	rt->tp_mat = NULL;
//	rt->tp_color = new_vec3(0, 0, 0);
//	rt->tp_ret = 0;
//	rt->tp_has_txm = false;
//	rt->tp_has_bmp = false;
//	rt->tp_has_pat = false;
//	rt->tp_pat = 0;
//	rt->tp_pat_ratio = 0;
//	ft_bzero(&rt->tp_ray, sizeof(t_ray));
//	rt->tp_type = 0;
//	ft_bzero(&rt->tp_color, sizeof(t_vec3));
//	ft_bzero(&rt->tp_light, sizeof(t_light));
//	ft_bzero(&rt->tp_trsf, sizeof(t_trsf));
//	rt->tp_shadow_comp = false;
}
