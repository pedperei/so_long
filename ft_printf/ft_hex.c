/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 15:53:22 by pedperei          #+#    #+#             */
/*   Updated: 2022/11/30 17:43:16 by pedperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_zero(int fd)
{
	write(fd, "0", 1);
	return (1);
}

int	ft_putnbrhex_fd(unsigned int n, int fd, char r, int first)
{
	char		*base;
	int			temp;
	static int	counter;

	counter = 0;
	if (n == 0 && first == 0)
	{
		write(fd, "0", 1);
		return (1);
	}
	if (first == 0)
		first = 1;
	base = ft_base(r);
	temp = n;
	if (n != 0)
	{
		ft_putnbrhex_fd(n / 16, fd, r, first);
		temp = n % 16;
		write(fd, &base[temp], 1);
		counter++;
	}
	return (counter);
}
