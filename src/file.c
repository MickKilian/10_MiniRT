/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 07:09:03 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/02/21 23:15:54 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

bool	is_rt_file(char *file_path)
{
	size_t	path_length;

	path_length = ft_strlen(file_path) - 3;
	if (path_length)
		return (ft_strncmp(file_path + path_length, ".rt", 3) == 0);
	return (0);
}

int	read_file(t_rt *rt, int fd)
{
	int		ret;
	char	*line;

	ret = 0;

	while (!ret)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		line = clean_line(line);
	 	if (ft_strcmp(line, "\0") == 0)
			continue;
		if (parse_line(rt, line))
		{
			ret = 1;
		}
		free(line);
	}
	if (ret == 0 && is_incomplete_file(rt))
		ret = 1;
	close(fd);
	return (ret);
}

char	*clean_line(char *line)
{
	int		i;
	char	*tmp;

	i = -1;
	tmp = line;
	while (tmp && tmp[++i])
		if (tmp[i] == '\t' || tmp[i] == '\n')
			tmp[i] = ' ';
	line = ft_strtrim(tmp, " ");
	free(tmp);
	return (line);
}

bool	is_incomplete_file(t_rt *rt)
{
	if (!rt->ambient.set && !rt->light.set)
		return (display_error(ERR_AT_LEAST_A_OR_L));
	//if (!rt->ambient.set)
	//	return (display_error(ERR_NO_PARAMS_AMBIENT));
	//if (!rt->light.set)
	//	return (display_error(ERR_NO_PARAMS_LIGHT));
	if (!rt->cam.set)
		return (display_error(ERR_NO_PARAMS_CAMERA));
	return (0);
}

int	open_and_read_file(t_rt *rt, char *file_path)
{
	int	fd;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (display_error(ERR_OPEN_FILE));
	if (!is_rt_file(file_path))
		return (display_error(ERR_IS_NOT_RT_FILE));
	if (read_file(rt, fd) || is_incomplete_file(rt))
	{
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}
