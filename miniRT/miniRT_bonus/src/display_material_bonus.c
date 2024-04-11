/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_material_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 03:03:50 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/03/21 00:20:13 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt_bonus.h"

void	display_material(t_material *mat)
{
	printf("   ***MATERIAL\n");
	printf("      type : %d\n", mat->type);
	if (mat->type == LAMBERTIAN)
		display_lamber(&mat->lamber);
	if (mat->type == METAL)
		display_metal(&mat->metal);
}

void	display_lamber(t_lamber *lamber)
{
	printf("      ***LAMBERTIAN\n");
	printf("         color : ");
	display_vec3(lamber->color);
	printf("\n");
}

void	display_metal(t_metal *metal)
{
	printf("      ***METAL\n");
	printf("         color : ");
	display_vec3(metal->color);
	printf("\n");
	printf("         fuzz : %f\n", metal->fuzz);
}
