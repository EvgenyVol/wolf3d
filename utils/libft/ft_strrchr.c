/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfunk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 13:36:58 by rfunk             #+#    #+#             */
/*   Updated: 2018/11/26 13:37:48 by rfunk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	char	*last_c;

	last_c = NULL;
	len = ft_strlen(s) + 1;
	while (len--)
	{
		if (*s++ == c)
			last_c = (char *)(s - 1);
	}
	return (last_c);
}
