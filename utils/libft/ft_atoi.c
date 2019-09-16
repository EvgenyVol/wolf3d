/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfunk <rfunk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 13:44:26 by rfunk             #+#    #+#             */
/*   Updated: 2018/11/30 18:15:27 by rfunk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
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
		res += (int)(*str) - '0';
		if (res < temp)
			return (sign == 1 ? 0 : -1);
		str++;
	}
	return (sign == 1 ? -res : res);
}
