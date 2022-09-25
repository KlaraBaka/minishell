/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radriann <radriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 13:36:16 by radriann          #+#    #+#             */
/*   Updated: 2022/09/18 13:36:38 by radriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*addr_of_next_el;

	while (*lst)
	{
		addr_of_next_el = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = addr_of_next_el;
	}
	*lst = NULL;
}
