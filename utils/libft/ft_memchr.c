/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfunk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 22:00:34 by rfunk             #+#    #+#             */
/*   Updated: 2018/11/23 22:00:35 by rfunk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ch_s;

	if (n || s)
	{
		ch_s = (unsigned char *)s;
		while (n--)
		{
			if (*ch_s++ == (unsigned char)c)
				return (ch_s - 1);
		}
	}
	return (NULL);
}
