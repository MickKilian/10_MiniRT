/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 22:19:34 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/04/06 03:41:17 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

int	main(int argc, char **argv, char **envp)
{
	t_rt	rt;
	int		ret;

	if (!envp[0])
		return (1);
	ret = 0;
	ft_bzero(&rt, sizeof(t_rt));
	if (argc != 2)
		return (display_error(ERR_NB_ARGUMENTS));
	else if (open_and_read_file(&rt, argv[1]) || mini_rt(&rt))
		ret = 1;
	ft_exit(&rt);
	return (ret);
}

int	mini_rt(t_rt *rt)
{
	srand(time(NULL) ^ getpid());
	if (rt_initialize(rt) || render(rt))
		return (1);
	mlx_loop(rt->mlx.ptr);
	return (0);
}

int	ft_exit(t_rt *rt)
{
	free_httbls(&rt->world);
	if (rt->mlx.ptr)
	{
		mlx_loop_end(rt->mlx.ptr);
		if (rt->img.ptr)
			mlx_destroy_image(rt->mlx.ptr, rt->img.ptr);
		if (rt->mlx.win_ptr)
			mlx_destroy_window(rt->mlx.ptr, rt->mlx.win_ptr);
		mlx_destroy_display(rt->mlx.ptr);
		free(rt->mlx.ptr);
	}
	exit(EXIT_SUCCESS);
	return (0);
}
