/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_simple.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 03:03:50 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/03/16 09:02:46 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/scene_create.h"

void	write_str(t_rt *rt, char *str)
{
	write(rt->fd, str, ft_strlen(str));
}

void	write_dbl(t_rt *rt, double x)
{
	char	*str;

	str = ft_dbl2str(x);
	write(rt->fd, str, ft_strlen(str));
	free(str);
}

void	write_code(t_rt *rt, char *str)
{
	write_str(rt, str);
	write_str(rt, "\t");
}

void	write_number(t_rt *rt, double x)
{
	write_dbl(rt, x);
	write_str(rt, "\t");
}

void	write_vec3(t_rt *rt, t_vec3 v)
{
	write_dbl(rt, v.x);
	write_str(rt, ",");
	write_dbl(rt, v.y);
	write_str(rt, ",");
	write_dbl(rt, v.z);
	write_str(rt, "\t");
}
