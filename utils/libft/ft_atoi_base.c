/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfunk <rfunk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 20:08:24 by rfunk             #+#    #+#             */
/*   Updated: 2019/09/06 16:34:54 by rfunk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	char_value(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	else
		return (-1);
}

int			ft_atoi_base(const char *str, int base)
{
	int	res;
	int	temp;

	res = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n'
			|| *str == '\v' || *str == '\r' || *str == '\f')
		str++;
	if (base == 16 && (*str == '0') &&
			((*(str + 1) == 'x' || *(str + 1) == 'X')))
		str += 2;
	temp = char_value(*str);
	while (temp >= 0 && temp < base)
	{
		res = res * base + temp;
		str++;
		temp = char_value(*str);
	}
	return (res);
}
