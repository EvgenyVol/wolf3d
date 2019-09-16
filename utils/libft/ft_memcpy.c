/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfunk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 21:55:46 by rfunk             #+#    #+#             */
/*   Updated: 2018/11/23 21:55:47 by rfunk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*ch_dst;
	const unsigned char	*ch_src;

	if (dst == src)
		return (dst);
	ch_dst = dst;
	ch_src = src;
	while (n--)
		*ch_dst++ = *ch_src++;
	return (dst);
}
