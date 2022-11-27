/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:33:43 by ntitan            #+#    #+#             */
/*   Updated: 2022/11/27 17:39:30 by ntitan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst->next = NULL;
	lst->content = content;
	return (lst);
}

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*list;

	while (*lst)
	{
		list = *lst;
		(*del)(list->content);
		(*lst) = (*lst)->next;
		free(list);
	}
}
