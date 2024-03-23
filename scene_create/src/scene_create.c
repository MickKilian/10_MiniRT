/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:23:39 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/03/17 04:53:12 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/scene_create.h"

int	scene_create(t_rt *rt)
{
	// Initialization for random generator
	srand(time(NULL) ^ getpid());
	n_random_dice(rt);

	return (0);
}
