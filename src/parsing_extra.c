/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_extra.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 07:40:44 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/04/09 20:43:01 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

int	parse_extra(t_rt *rt)
{
	rt->tp.count++;
	if (ft_strcmp(rt->tp.params[rt->tp.count], "tra") == 0)
		return (parse_translation(rt));
	else if (ft_strcmp(rt->tp.params[rt->tp.count], "rot") == 0)
		return (parse_rotation(rt));
	else if (ft_strcmp(rt->tp.params[rt->tp.count], "die") == 0)
		return (parse_dielectric(rt));
	else if (ft_strcmp(rt->tp.params[rt->tp.count], "met") == 0)
		return (parse_metal(rt));
	else if (ft_strcmp(rt->tp.params[rt->tp.count], "dif") == 0)
		return (parse_diff_light(rt));
	else if (ft_strcmp(rt->tp.params[rt->tp.count], "pat") == 0)
		return (parse_pattern(rt));
	else if (ft_strcmp(rt->tp.params[rt->tp.count], "txm") == 0)
		return (parse_texture(rt));
	else if (ft_strcmp(rt->tp.params[rt->tp.count], "bmp") == 0)
		return (parse_bump(rt));
	else
		return (display_error_plus(ERR_INFO_TYPE,
				rt->tp.params[rt->tp.count]));
}
