/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfunk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 21:57:51 by rfunk             #+#    #+#             */
/*   Updated: 2018/11/23 21:58:22 by rfunk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*cp_dst;
	unsigned char	*cp_src;
	size_t			i;

	i = 0;
	cp_dst = (unsigned char *)dst;
	cp_src = (unsigned char *)src;
	while (i < n)
	{
		cp_dst[i] = cp_src[i];
		if (cp_dst[i] == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
