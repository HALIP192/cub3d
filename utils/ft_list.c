/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:33:43 by ntitan            #+#    #+#             */
/*   Updated: 2022/10/01 16:42:44 by ntitan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

list_t	*ft_lstnew(void *content)
{
	list_t	*lst;

	lst = (list_t *)malloc(sizeof(list_t));
	if (!lst)
		return (NULL);
	lst->next = NULL;
	lst->content = content;
	return (lst);
}

void	ft_lstclear(list_t **lst, void (*del)(void*))
{
	list_t	*list;

	while (*lst)
	{
		list = *lst;
		(*del)(list->content);
		(*lst) = (*lst)->next;
		free(list);
	}
}

