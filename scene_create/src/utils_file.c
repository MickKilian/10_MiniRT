/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 07:09:03 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/03/17 14:44:41 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/scene_create.h"

bool	is_rt_file(char *file_path)
{
	size_t	path_length;

	path_length = ft_strlen(file_path) - 3;
	if (path_length)
		return (ft_strncmp(file_path + path_length, ".rt", 3) == 0);
	return (0);
}

int	open_and_write_file(t_rt *rt, char *file_path)
{
	rt->fd = open(file_path, O_RDWR | O_CREAT, 0640);
	if (rt->fd == -1)
		return (display_error(ERR_OPEN_FILE));
	else if (!is_rt_file(file_path))
		return (display_error(ERR_IS_NOT_RT_FILE));
	return (0);
}
