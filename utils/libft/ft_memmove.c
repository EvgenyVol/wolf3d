/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfunk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 21:59:02 by rfunk             #+#    #+#             */
/*   Updated: 2018/11/23 21:59:17 by rfunk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const unsigned char		*ch_src;
	unsigned char			*ch_dst;

	ch_src = (unsigned char *)src;
	ch_dst = (unsigned char *)dst;
	if (ch_src < ch_dst)
		while (len--)
			*(ch_dst + len) = *(ch_src + len);
	else if (ch_src > ch_dst)
		ft_memcpy(dst, src, len);
	return (dst);
}
