/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:52:49 by bsousa-d          #+#    #+#             */
/*   Updated: 2023/11/11 16:46:08 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *node;
	t_list *head;

	if (!lst || !f || !del)
		return (NULL);
	node = ft_lstnew(f(lst->content));
	head = node;
	while (lst->next)
	{
		lst = lst->next;
		node->next = ft_lstnew(f(lst->content));
		if (!node->next)
			ft_lstclear(&head, del);
		node = node->next;
	}
	return (head);
}
