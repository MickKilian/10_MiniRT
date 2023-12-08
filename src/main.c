/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 22:19:34 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/12/08 11:18:42 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//****************************************************************************//
// I learned ray tracing using the following resources                        //
// Tuto ray_tracing                                                           //
// https://raytracing.github.io/books/RayTracingInOneWeekend.html             //
//****************************************************************************//

#include "../inc/ray_tracing.h"

int	main(int argc, char **argv)
{
	t_rt	rt;

	ft_bzero(&rt, sizeof(t_rt));
	if (argc != 2)
		return (display_error(ERR_BAD_NB_ARGUMENTS));
	else if (open_and_read_file(&rt, argv[1]))
		return (1);
	ray_tracing(&rt);
	return (0);
}
