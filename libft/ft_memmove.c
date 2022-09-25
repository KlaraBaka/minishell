/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radriann <radriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 13:42:16 by radriann          #+#    #+#             */
/*   Updated: 2022/09/18 13:42:20 by radriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *source, size_t n)
{
	unsigned int	i;
	char			*result;
	char			*original;

	if (!dest && !source)
		return (NULL);
	i = 0;
	result = (char *)dest;
	original = (char *)source;
	if (dest < source)
	{
		while (i < n)
		{
			result[i] = original[i];
			i++;
		}
	}
	else
	{
		while (n-- > 0)
			result[n] = original[n];
	}
	return (result);
}
