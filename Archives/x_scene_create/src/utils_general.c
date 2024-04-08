/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_general.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 07:09:03 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/03/17 14:53:53 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/scene_create.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*temp;

	temp = malloc(nmemb * size);
	if (!temp)
		return (NULL);
	ft_bzero(temp, nmemb * size);
	return (temp);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		s++;
		i++;
	}
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	while (n > 0)
	{
		*(char *)s = '\0';
		n--;
		s++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	length;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	length = ft_strlen(s1) + ft_strlen(s2);
	str = malloc((length + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (*s1)
		*str++ = *s1++;
	while (*s2)
		*str++ = *s2++;
	*str = '\0';
	return (str - length);
}

char	*ft_strdup(const char *s)
{
	char	*cpy;
	int		i;

	cpy = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!cpy)
		return (NULL);
	i = 0;
	while (*(s + i))
	{
		*(cpy + i) = *(s + i);
		i++;
	}
	*(cpy + i) = '\0';
	return (cpy);
}

static	int	ft_getsize(int n)
{
	int	size;

	size = 0;
	if (n == -2147483648)
		return (11);
	else if (n < 0)
	{
		size++;
		n = -n;
	}
	else if (n == 0)
		return (1);
	while (n)
	{
		size++;
		n = n / 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	int		sign;
	int		nb_carac;
	char	*str;

	nb_carac = ft_getsize(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = malloc((nb_carac + 1) * sizeof(char));
	if (!str)
		return (NULL);
	sign = (n < 0);
	n = n - 2 * n * (n < 0);
	if (sign == 1)
		str[0] = '-';
	str[nb_carac] = '\0';
	while (nb_carac - sign)
	{
		str[nb_carac - 1] = n % 10 + '0';
		n = n / 10;
		nb_carac--;
	}
	return (str);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned const char	*t1;
	unsigned const char	*t2;

	t1 = (unsigned const char *)s1;
	t2 = (unsigned const char *)s2;
	while (n)
	{
		if (*t1 != *t2 || !*t1 || !*t2)
			return (*t1 - *t2);
		n--;
		t1++;
		t2++;
	}
	return (0);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL)
		return ;
	write(fd, s, ft_strlen(s));
}

char	*ft_dbl2str(double num)
{
	char	*str;
	char	*temp1;
	char	*temp2;

	temp1 = ft_itoa(floor(num));
	if (num - trunc(num) != 0) {
		str = ft_strjoin(temp1, ".");
		free(temp1);
		temp1 = str;
		temp2 = ft_itoa(1000 * fabs(num - trunc(num)));
		str = ft_strjoin(temp1, temp2);
		free(temp1);
		free(temp2);
	}
	else
		str = temp1;
	return (str);
}
