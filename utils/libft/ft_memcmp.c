/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfunk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 22:02:02 by rfunk             #+#    #+#             */
/*   Updated: 2018/11/23 22:02:03 by rfunk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*ch_s1;
	const unsigned char	*ch_s2;

	i = 0;
	ch_s1 = (const unsigned char *)s1;
	ch_s2 = (const unsigned char *)s2;
	if (n > 0)
	{
		while (i < n)
		{
			if (ch_s1[i] != ch_s2[i])
				return ((int)(ch_s1[i] - ch_s2[i]));
			i++;
		}
	}
	return (0);
}
