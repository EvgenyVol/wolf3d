/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfunk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 13:16:13 by rfunk             #+#    #+#             */
/*   Updated: 2018/11/26 13:16:21 by rfunk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*cp_s1;
	unsigned char	*cp_s2;

	i = 0;
	cp_s1 = (unsigned char *)s1;
	cp_s2 = (unsigned char *)s2;
	if (n > 0)
	{
		while (n-- && (cp_s1[i] == cp_s2[i]) && cp_s1[i])
			i++;
		if (n == (size_t)-1)
			return (0);
		return (cp_s1[i] - cp_s2[i]);
	}
	return (0);
}
