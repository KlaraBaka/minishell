/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radriann <radriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 13:42:25 by radriann          #+#    #+#             */
/*   Updated: 2022/09/18 13:42:27 by radriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *source, size_t n)
{
	char			*result;
	char			*original;
	unsigned int	i;

	if (!dest && !source)
		return (NULL);
	i = 0;
	result = (char *)dest;
	original = (char *)source;
	while (i < n)
	{
		result[i] = original[i];
		i++;
	}
	return (result);
}
