/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_sets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 22:51:38 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/11/29 19:43:50 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../../includes/fractol.h"

int	ft_get_color_set(t_rt *prm)
{
	if (prm->clr_md == 4)
		ft_set_clr_md_4(prm);
	else if (prm->clr_md == 5)
		ft_set_clr_md_5(prm);
	else if (prm->clr_md == 6)
		ft_set_clr_md_6(prm);
	return (0);
}

int	ft_set_clr_md_4(t_rt *prm)
{
	prm->clr_sch[0] = 5;
	prm->clr_sch[1] = 0x00000000;
	prm->clr_sch[2] = 0x0075D5FD;
	prm->clr_sch[3] = 0x00B76CFD;
	prm->clr_sch[4] = 0x00FF2281;
	prm->clr_sch[5] = 0x00011FFD;
	prm->clr_sch[6] = 0;
	prm->clr_sch[7] = 0;
	prm->clr_sch[8] = 0;
	prm->clr_sch[9] = 0;
	prm->clr_sch[10] = 0;
	return (0);
}

int	ft_set_clr_md_5(t_rt *prm)
{
	prm->clr_sch[0] = 7;
	prm->clr_sch[1] = 0x00000000;
	prm->clr_sch[2] = 0x00FFEB00;
	prm->clr_sch[3] = 0x00FC0019;
	prm->clr_sch[4] = 0x0001FF4F;
	prm->clr_sch[5] = 0x00FF01D7;
	prm->clr_sch[6] = 0x005600CC;
	prm->clr_sch[7] = 0x0000EDF5;
	prm->clr_sch[8] = 0;
	prm->clr_sch[9] = 0;
	prm->clr_sch[10] = 0;
	return (0);
}

int	ft_set_clr_md_6(t_rt *prm)
{
	prm->clr_sch[0] = 5;
	prm->clr_sch[1] = 0x002E2E41;
	prm->clr_sch[2] = 0x004D3347;
	prm->clr_sch[3] = 0x0086112E;
	prm->clr_sch[4] = 0x00EB3E1B;
	prm->clr_sch[5] = 0x00FB6D10;
	prm->clr_sch[6] = 0;
	prm->clr_sch[7] = 0;
	prm->clr_sch[8] = 0;
	prm->clr_sch[9] = 0;
	prm->clr_sch[10] = 0;
	return (0);
}
