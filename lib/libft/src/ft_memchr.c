/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:59:14 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/03/18 00:32:07 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n && *(unsigned char *)s != (unsigned char)c)
	{
		s++;
		n--;
	}
	if (n)
		return ((unsigned char *)s);
	else
		return (0);
}
