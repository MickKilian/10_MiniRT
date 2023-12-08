/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:20:13 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/12/08 09:30:15 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ischarset(int c, const char *set)
{
	while (*set)
		if (*set++ == c)
			return (1);
	return (0);
}

static size_t	ft_count_charset(char const *s, char const *set)
{
	int		i;
	size_t	count;

	i = ft_strlen(s);
	count = 0;
	while (i && ft_ischarset(s[--i], set))
		count++;
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*d;
	size_t	dlen;
	size_t	i;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	while (ft_ischarset(*s1, set))
		s1++;
	dlen = ft_strlen(s1) - ft_count_charset(s1, set);
	d = malloc(dlen + 1);
	if (d == NULL)
		return (NULL);
	i = 0;
	while (i < dlen)
	{
		d[i] = s1[i];
		i++;
	}
	d[i] = 0;
	return (d);
}
