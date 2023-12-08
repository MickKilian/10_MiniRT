/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_manage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 22:51:49 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/11/29 19:18:18 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../../includes/fractol.h"

int	ft_assign_color(t_rt *prm)
{
	if (prm->clr_md >= 1 && prm->clr_md <= 3)
		ft_assign_color_simple(prm);
	else if (prm->clr_md >= 4 && prm->clr_md <= 6)
		ft_assign_color_setmode(prm);
	else if (prm->clr_md == 7)
		ft_assign_color_thsv(prm);
	else if (prm->set == 3)
		ft_assign_color_newton(prm);
	return (0);
}

int	ft_assign_color_simple(t_rt *prm)
{
	if (prm->inset)
		prm->clr.val = 0x00000000;
	else
	{
		prm->clr_lvl = prm->stp_itr * 255
			/ (prm->mx_itr / 2);
		if (prm->stp_itr <= (prm->mx_itr / 2))
		{
			prm->clr.trgb[1] = prm->clr_md1[1] * prm->clr_lvl;
			prm->clr.trgb[2] = prm->clr_md1[2] * prm->clr_lvl;
			prm->clr.trgb[3] = prm->clr_md1[3] * prm->clr_lvl;
		}
		else
		{
			prm->clr.trgb[1] = prm->clr_md1[1] * 255
				+ !prm->clr_md1[1] * prm->clr_lvl;
			prm->clr.trgb[2] = prm->clr_md1[2] * 255
				+ !prm->clr_md1[2] * prm->clr_lvl;
			prm->clr.trgb[3] = prm->clr_md1[3] * 255
				+ !prm->clr_md1[3] * prm->clr_lvl;
		}
		prm->clr.trgb[0] = 0;
		ft_trgb2val(&prm->clr);
	}
	return (0);
}

int	ft_assign_color_setmode(t_rt *prm)
{
	ft_get_color_set(prm);
	if (prm->inset)
		prm->clr.val = prm->clr_sch[1];
	else
	{
		if (prm->stp_itr <= prm->mx_itr / 2 - 1)
			prm->clr.val = prm->clr_sch[prm->stp_itr
				% prm->clr_sch[0] + 1];
		else
			prm->clr.val = prm->clr_sch[prm->stp_itr
				% prm->clr_sch[0] + 1];
	}
	return (0);
}

int	ft_assign_color_thsv(t_rt *prm)
{
	prm->clr.thsv[0] = 0;
	prm->clr.thsv[1] = ft_modulo((prm->hm[0] * prm->stp_itr)
			+ prm->hm[1], 360);
	prm->clr.thsv[2] = prm->hm[2];
	prm->clr.thsv[3] = prm->hm[3] * !prm->inset;
	ft_thsv2trgb(&prm->clr);
	return (0);
}

int	ft_assign_color_newton(t_rt *prm)
{
	prm->clr.trgb[prm->newton_root + 1] = 255
		* (1 - (double)prm->stp_itr / (double)prm->mx_itr);
	prm->clr.trgb[(prm->newton_root + 1) % 3 + 1] = 0;
	prm->clr.trgb[(prm->newton_root + 2) % 3 + 1] = 0;
	prm->clr.trgb[0] = 0;
	ft_trgb2val(&prm->clr);
	return (0);
}
