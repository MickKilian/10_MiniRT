/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_txm_pat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 07:40:44 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/04/06 10:32:54 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

int	parse_texture(t_rt *rt)
{
	int		fd;
	char	*xpm_file_path;

	if (check_nb_params(rt, NB_PARAMS_TXM, ERR_PARAMS_TXM))
		return (1);
	xpm_file_path = rt->tp_params[++rt->tp_count];
	fd = open(xpm_file_path, O_RDONLY);
	if (!is_xpm_file(xpm_file_path))
		return (display_error_plus(ERR_IS_NOT_XPM_FILE, xpm_file_path));
	else if (fd == -1)
		return (display_error_plus(ERR_OPEN_XPM_FILE, xpm_file_path));
	rt->tp_has_txm = true;
	rt->tp_txm_path = xpm_file_path;
	return (0);
}

int	parse_bump(t_rt *rt)
{
	int		fd;
	char	*xpm_file_path;

	if (check_nb_params(rt, NB_PARAMS_BUMP, ERR_PARAMS_BUMP))
		return (1);
	xpm_file_path = rt->tp_params[++rt->tp_count];
	fd = open(xpm_file_path, O_RDONLY);
	if (!is_xpm_file(xpm_file_path))
		return (display_error_plus(ERR_IS_NOT_XPM_FILE, xpm_file_path));
	else if (fd == -1)
		return (display_error_plus(ERR_OPEN_XPM_FILE, xpm_file_path));
	rt->tp_has_bmp = true;
	rt->tp_bmp_path = xpm_file_path;
	return (0);
}

int	parse_pattern(t_rt *rt)
{
	double	ratio;

	if (check_nb_params(rt, NB_PARAMS_PAT, ERR_PARAMS_PAT))
		return (1);
	if (parse_pat(rt->tp_params[++rt->tp_count], &rt->tp_pat))
		return (1);
	else if (parse_int_pos(rt->tp_params[++rt->tp_count], &ratio))
		return (1);
	rt->tp_has_pat = true;
	rt->tp_pat_ratio = (int)ratio;
	return (0);
}
