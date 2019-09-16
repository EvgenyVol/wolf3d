/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfunk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 13:52:54 by rfunk             #+#    #+#             */
/*   Updated: 2018/11/26 13:53:14 by rfunk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (src_len < len)
	{
		ft_memset(dst + src_len, '\0', len - src_len);
		return (ft_memcpy(dst, src, src_len));
	}
	else
		return (ft_memcpy(dst, src, len));
}
