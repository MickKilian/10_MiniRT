/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 08:32:19 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/02/22 02:06:41 by mbourgeo         ###   ########.fr       */
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
