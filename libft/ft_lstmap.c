/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdessm <mabdessm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:19:54 by mabdessm          #+#    #+#             */
/*   Updated: 2024/05/03 12:16:25 by mabdessm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*temp;

	if (!lst || !f || !del)
		return (NULL);
	res = ft_lstnew(f(lst->content));
	if (!res)
		return (NULL);
	temp = res;
	lst = lst->next;
	while (lst)
	{
		res->next = ft_lstnew(f(lst->content));
		if (!res->next)
		{
			ft_lstclear(&temp, del);
			return (NULL);
		}
		res = res->next;
		lst = lst->next;
	}
	return (temp);
}
