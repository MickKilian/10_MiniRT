/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 19:24:57 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/03/23 04:58:22 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

//void	*ft_calloc(size_t nmemb, size_t size)
//{
//	char	*temp;
//
//	temp = malloc(nmemb * size);
//	if (!temp)
//		return (NULL);
//	ft_bzero(temp, nmemb * size);
//	return (temp);
//}

//int	allocator(void *ptr, size_t size)
//{
//	*(void **)ptr = malloc(size);
//	if (!*(void **)ptr)
//		return (1);
//	ft_bzero(*(void **)ptr, size);
//	return (0);
//}

//void	ft_bzero(void *ptr, const size_t size)
//{
//	size_t	i;
//	char	*str;
//
//	if (!ptr)
//		return ;
//	i = 0;
//	str = (char *)ptr;
//	while (i < size)
//	{
//		str[i] = 0;
//		i++;
//	}
//}

void	free_httbls(t_httbl *httbl)
{
	t_httbl	*temp;

	while (httbl)
	{
		temp = httbl->next;
		free(httbl->geom);
		free(httbl->mat);
		free(httbl);
		httbl = temp;
	}
}

void	free_split_vec(char **vec)
{
	int	i;

	i = 0;
	while (vec[i])
	{
		free(vec[i]);
		i++;
	}
	free(vec);
}
