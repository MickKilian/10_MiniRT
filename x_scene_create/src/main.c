/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 22:19:34 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/03/17 14:55:39 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/scene_create.h"

int	main(int argc, char **argv)
{
	t_rt	rt;

	ft_bzero(&rt, sizeof(t_rt));
	rt.geometry = ft_calloc(1, sizeof(t_geometry));
	rt.material = ft_calloc(1, sizeof(t_material));
	if (argc != 2)
		return (display_error(ERR_NB_ARGUMENTS));
	remove(argv[1]);
	if (open_and_write_file(&rt, argv[1]))
		return (1);
	scene_create(&rt);
	close(rt.fd);
	free(rt.geometry);
	free(rt.material);
	return (0);
}
