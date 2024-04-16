/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 07:40:44 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/04/09 08:11:44 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt_bonus.h"

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
