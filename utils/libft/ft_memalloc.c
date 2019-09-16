/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfunk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 13:56:00 by rfunk             #+#    #+#             */
/*   Updated: 2018/11/26 13:56:30 by rfunk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*fresh_mem;

	if (!(fresh_mem = (void *)malloc(sizeof(void) * size)))
		return (NULL);
	ft_bzero(fresh_mem, size);
	return (fresh_mem);
}
