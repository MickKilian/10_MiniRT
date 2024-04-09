/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_txm_pat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 07:40:44 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/04/09 02:18:06 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"
#include <errno.h>

int	parse_texture(t_rt *rt)
{
	int		fd;
	char	*xpm_file_path;

	if (check_nb_params(rt, NB_PARAMS_TXM, ERR_PARAMS_TXM))
		return (1);
	xpm_file_path = rt->tp.params[++rt->tp.count];
	fd = open(xpm_file_path, O_RDONLY);
	if (!is_xpm_file(xpm_file_path))
		return (display_error_plus(ERR_IS_NOT_XPM_FILE, xpm_file_path));
	else if (fd == -1)
		return (display_error_plus(ERR_OPEN_XPM_FILE, xpm_file_path));
	rt->tp.has_txm = true;
	rt->tp.txm_path = xpm_file_path;
	return (0);
}

int	parse_bump(t_rt *rt)
{
	int		fd;
	char	*xpm_file_path;

	if (check_nb_params(rt, NB_PARAMS_BUMP, ERR_PARAMS_BUMP))
		return (1);
	xpm_file_path = rt->tp.params[++rt->tp.count];
	fd = open(xpm_file_path, O_RDONLY);
	if (!is_xpm_file(xpm_file_path))
		return (display_error_plus(ERR_IS_NOT_XPM_FILE, xpm_file_path));
	else if (fd == -1)
		return (display_error_plus(ERR_OPEN_XPM_FILE, xpm_file_path));
	rt->tp.has_bmp = true;
	rt->tp.bmp_path = xpm_file_path;
	return (0);
}

int	parse_pattern(t_rt *rt)
{
	double	ratio;

	if (check_nb_params(rt, NB_PARAMS_PAT, ERR_PARAMS_PAT))
		return (1);
	if (parse_pat(rt->tp.params[++rt->tp.count], &rt->tp.pat))
		return (1);
	else if (parse_int_pos(rt->tp.params[++rt->tp.count], &ratio))
		return (1);
	rt->tp.has_pat = true;
	rt->tp.pat_ratio = (int)ratio;
	return (0);
}
