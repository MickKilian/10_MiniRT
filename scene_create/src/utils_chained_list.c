/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_chained_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 07:09:03 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/03/17 05:04:09 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/scene_create.h"

t_list_obj	*new_list_obj(t_obj obj)
{
	t_list_obj *new_obj;

	new_obj = ft_calloc(1, sizeof(t_list_obj));
	if (!new_obj)
		return (NULL);
	new_obj->next = NULL;
	new_obj->obj = obj;
	return (new_obj);
}

void	list_obj_addback(t_rt *rt, t_list_obj *new_list_obj)
{
	if (!new_list_obj)
		return ;
	if (!rt->list_obj)
	{
		rt->list_obj_head = new_list_obj;
	}
	else
	{
		while (rt->list_obj->next)
			rt->list_obj = rt->list_obj->next;
		rt->list_obj->next = new_list_obj;
	}
	rt->list_obj_size += 1;
	rt->list_obj = rt->list_obj_head;
	return ;
}

void	free_list_obj(t_list_obj *list_obj)
{
	t_list_obj	*temp;

	temp = list_obj;
	while (list_obj)
	{
		list_obj = list_obj->next;
		free(temp);
		temp = list_obj;
	}
}
