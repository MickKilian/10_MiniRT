/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_extra.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 07:40:44 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/03/22 16:53:27 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

int	parse_extra(t_rt *rt)
{
	rt->tp_count++;
	if (ft_strcmp(rt->tp_params[rt->tp_count], "tra") == 0)
		return (parse_translation(rt));
	else if (ft_strcmp(rt->tp_params[rt->tp_count], "rot") == 0)
		return (parse_rotation(rt));
	else if (ft_strcmp(rt->tp_params[rt->tp_count], "die") == 0)
		return (parse_dielectric(rt));
	else if (ft_strcmp(rt->tp_params[rt->tp_count], "met") == 0)
		return (parse_metal(rt));
	else if (ft_strcmp(rt->tp_params[rt->tp_count], "dif") == 0)
		return (parse_diff_light(rt));
	else
		return (display_error_plus(ERR_INFO_TYPE,
				rt->tp_params[rt->tp_count]));
}
