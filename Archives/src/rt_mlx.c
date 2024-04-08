/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 22:33:54 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/04/06 03:31:26 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

int	on_key_press(int keycode, t_mlx *mlx_data)
{
    if (keycode == 65307 && mlx_data->ptr)
    {
        ft_putstr_fd("ESC pressed\n", 1);
        mlx_loop_end(mlx_data->ptr);
    }
    return (0);
}

int    mlx_initialize(t_mlx *mlx, int w, int h)
{
    mlx->ptr = mlx_init();
    mlx->win_ptr = mlx_new_window(mlx->ptr, w, h, "42 mini_rt");
    mlx_key_hook(mlx->win_ptr, on_key_press, &mlx->ptr);
    mlx_hook(mlx->win_ptr, 17, 0L, mlx_loop_end, mlx->ptr);
    return (0);
}

