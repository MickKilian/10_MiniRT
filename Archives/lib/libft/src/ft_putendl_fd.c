/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:38:31 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/03/18 00:32:31 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (s == NULL)
		return ;
	write(fd, s, ft_strlen(s));
	ft_putchar_fd('\n', fd);
}

/*int	main(int argc, char **argv)
{
	int	fd;

	(void)argc;
	fd = open("test.txt", O_RDWR);
	if (fd != -1)
		ft_putendl_fd(argv[1], fd);
	close (fd);
	return (0);
}*/
