/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 22:33:54 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/03/29 20:33:43 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

int	image_create(t_mlx *mlx, t_image *img, int w, int h)
{
	img->ptr = mlx_new_image(mlx->ptr, w, h);
	if (!img->ptr)
		return (1);
	img->addr = mlx_get_data_addr(img->ptr,
			&img->bpp, &img->line_length, &img->endian);
	if (!img->addr)
		return (1);
	return (0);
}

int	image_update(t_mlx *mlx, t_image img)
{
	mlx_put_image_to_window(mlx->ptr, mlx->win_ptr, img.ptr, 0, 0);
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

t_vec3	get_pixel_color(t_image *img, t_vec3 uv)
{
	char	*dst;
	int		x;
	int		y;

	x = ((int)((1 - uv.x) * img->w) + img->w / 2) % img->w;
	y = (int)((1 - uv.y) * img->h);
	if (0 <= x && x < img->w && 0 <= y && y < img->h)
	{
		dst = img->addr
			+ (y * img->line_length + x * (img->bpp / 8));
		return (rgb2vec(val2rgb(*(unsigned int *)dst)));
	}
	return (new_vec3(0, 0, 0));
}

double	get_bump_gradient(t_image *img, t_vec3 uv, int dir, double coeff)
{
	char	*dst;
	int		x;
	int		y;
	int		val_1;
	int		val_2;

	x = ((int)((1 - uv.x) * img->w) + img->w / 2) % img->w;
	y = (int)((1 - uv.y) * img->h);
	if (0 <= x && x < img->w && 0 <= y && y < img->h)
	{
		dst = img->addr
			+ (y * img->line_length + x * (img->bpp / 8));
		val_1 = *((unsigned int *)dst) & 0xff;
		if (dir == 1)
			x = next_modulo(x, img->w);
		else if (dir == 2)
			y = next_modulo(y, img->h);
		else
			return (1);
		dst = img->addr
			+ (y * img->line_length + x * (img->bpp / 8));
		val_2 = *((unsigned int *)dst) & 0xff;
		return (-((double)(val_1 - val_2)) / coeff);
	}
	return (1);
}
