/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 12:27:16 by pedperei          #+#    #+#             */
/*   Updated: 2022/12/24 18:24:43 by pedperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s != NULL && s[i] != '\0' && s[i] != '\n')
	{
		i++;
	}
	return (i);
}

void	*ft_memset(void *ptr, int x, size_t n)
{
	size_t			i;
	unsigned char	*temp;

	i = 0;
	temp = (unsigned char *)ptr;
	while (i < n)
	{
		temp[i] = x;
		i++;
	}
	return (ptr);
}

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*temp;

	temp = (void *)malloc(size * nitems);
	if (!temp)
		return (NULL);
	ft_memset(temp, 0, size * nitems);
	return (temp);
}
