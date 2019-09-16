/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfunk <rfunk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:35:04 by rfunk             #+#    #+#             */
/*   Updated: 2019/09/06 16:35:05 by rfunk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atod(const char *str)
{
	long long int	sign;
	long long int	res;
	long long int	temp;

	sign = 0;
	res = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n'
			|| *str == '\v' || *str == '\r' || *str == '\f')
		str++;
	if (*str == '-')
		sign = 1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		temp = res;
		res = res * 10;
		res += (double)(*str) - '0';
		if (res < temp)
			return (sign == 1 ? 0 : -1);
		str++;
	}
	return (sign == 1 ? -res : res);
}
