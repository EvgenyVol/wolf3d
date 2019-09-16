/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfunk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 13:18:28 by rfunk             #+#    #+#             */
/*   Updated: 2018/11/26 13:18:37 by rfunk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char	*cp_s1;

	cp_s1 = (char *)s1;
	while (*cp_s1)
		cp_s1++;
	while (*s2)
		*cp_s1++ = *s2++;
	*cp_s1++ = '\0';
	return (s1);
}
