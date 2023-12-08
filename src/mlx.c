/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 22:33:54 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/12/03 23:11:13 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ray_tracing.h"

int	mlx_initialize(t_mlx *mlx, int img_width, int img_height)
{

	int	win_width;
	int	win_height;

	win_width = 1920;
	win_height = 1080;

	// Initialisation of mlx and image
	mlx->ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->ptr, win_width, win_height, "Hello world!");
	if (image_create(mlx, img_width, img_height))
			return (1);
	return (0);
}

int	image_create(t_mlx *mlx, int img_width, int img_height)
{
	mlx->image.img = mlx_new_image(mlx->ptr,
			img_width, img_height);
	if (!mlx->image.img)
		return (1);
	mlx->image.addr = mlx_get_data_addr(mlx->image.img,
			&mlx->image.bpp, &mlx->image.line_length, &mlx->image.endian);
	if (!mlx->image.addr)
		return (1);
	return (0);
}

int	image_update(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->ptr, mlx->win_ptr,
		mlx->image.img, 0, 0);
	//printf("mlx_ptr : %p\n", mlx->ptr);
	//printf("mlx_win_ptr : %p\n", mlx->win_ptr);
	//printf("mlx_image : %p\n", mlx->image.img);
	return (0);
}

int	my_mlx_pixel_put(t_image img, int x, int y, int color)
{
	char	*dst;

	dst = img.addr + (y * img.line_length + x * (img.bpp / 8));
	if (!dst)
		return (1);
	*(unsigned int *)dst = color;
	return (0);
}
