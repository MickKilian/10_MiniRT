/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 22:33:54 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/04/09 02:53:27 by mbourgeo         ###   ########.fr       */
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

int    mlx_initialize(t_mlx *mlx)
{
    mlx->ptr = mlx_init();
    return (0);
}

