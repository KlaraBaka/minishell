/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radriann <radriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 13:42:39 by radriann          #+#    #+#             */
/*   Updated: 2022/09/18 13:42:42 by radriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*array;

	i = 0;
	array = (char *)s;
	while (i < n)
	{
		if (array[i] == (char)c)
			return (&array[i]);
		i++;
	}
	return (NULL);
}
