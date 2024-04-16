/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_extra.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 07:40:44 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/04/10 23:45:08 by mbourgeo         ###   ########.fr       */
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
	else
		return (display_error_plus(ERR_INFO_TYPE,
				rt->tp.params[rt->tp.count]));
}
