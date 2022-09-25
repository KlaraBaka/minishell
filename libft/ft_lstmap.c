/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radriann <radriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 13:43:15 by radriann          #+#    #+#             */
/*   Updated: 2022/09/18 13:43:18 by radriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*element;

	if (!lst || !f)
		return (NULL);
	result = NULL;
	while (lst)
	{
		element = ft_lstnew(f(lst->content));
		if (!element)
		{
			if (result)
				ft_lstclear(&result, del);
			return (NULL);
		}
		ft_lstadd_back(&result, element);
		lst = lst->next;
	}
	return (result);
}
