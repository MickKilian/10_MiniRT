/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 22:19:34 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/02/23 14:41:01 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//****************************************************************************//
// I learned ray tracing using the following different resources like         //
// Tuto rayTracing                                                            //
// https://raytracing.github.io/books/RayTracingInOneWeekend.html             //
//****************************************************************************//

#include "../inc/mini_rt.h"

int	main(int argc, char **argv)
{
	t_rt	rt;

	ft_bzero(&rt, sizeof(t_rt));
	if (argc != 2)
		return (display_error(ERR_NB_ARGUMENTS));
	else if (open_and_read_file(&rt, argv[1]))
		return (1);
	mini_rt(&rt);
	return (0);
}
