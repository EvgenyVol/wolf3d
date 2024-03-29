/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfunk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 18:26:20 by rfunk             #+#    #+#             */
/*   Updated: 2018/11/26 18:27:27 by rfunk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *chain;

	if (!(chain = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		chain->content = NULL;
		chain->content_size = 0;
	}
	else
	{
		if (!(chain->content = malloc(content_size)))
		{
			free(chain);
			return (NULL);
		}
		ft_memcpy(chain->content, content, content_size);
		chain->content_size = content_size;
	}
	chain->next = NULL;
	return (chain);
}
