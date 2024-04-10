/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 08:32:19 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/03/10 06:11:32 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

bool	display_error(char *error)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(error, 2);
	ft_putstr_fd("\n", 2);
	return (1);
}

bool	display_error_plus(char *error, char *msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(error, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	return (1);
}

bool	display_warning(char *warning)
{
	ft_putstr_fd("Warning\n", 2);
	ft_putstr_fd(warning, 2);
	ft_putstr_fd("\n", 2);
	return (1);
}

bool	display_warning_plus(char *warning, char *msg)
{
	ft_putstr_fd("Warning\n", 2);
	ft_putstr_fd(warning, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	return (1);
}

char	*get_error_message(char *geom)
{
	if (!ft_strcmp(geom, "sp"))
		return (ERR_PARAMS_SPHERE);
	else if (!ft_strcmp(geom, "qd"))
		return (ERR_PARAMS_QUAD);
	else if (!ft_strcmp(geom, "ds"))
		return (ERR_PARAMS_DISC);
	else if (!ft_strcmp(geom, "bx"))
		return (ERR_PARAMS_BOX);
	else if (!ft_strcmp(geom, "pl"))
		return (ERR_PARAMS_PLANE);
	else if (!ft_strcmp(geom, "cy"))
		return (ERR_PARAMS_CYLINDER);
	else if (!ft_strcmp(geom, "co"))
		return (ERR_PARAMS_CONE);
	else if (!ft_strcmp(geom, "di"))
		return (ERR_PARAMS_DICE);
	else if (!ft_strcmp(geom, "sc"))
		return (ERR_PARAMS_SAFE_CONE);
	return (NULL);
}
