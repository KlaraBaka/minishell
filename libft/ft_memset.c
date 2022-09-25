/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radriann <radriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 13:42:09 by radriann          #+#    #+#             */
/*   Updated: 2022/09/18 13:42:12 by radriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *arr, int ch, size_t size)
{
	unsigned int	i;
	char			*result;

	i = 0;
	result = (char *)arr;
	while (i < size)
	{
		result[i] = ch;
		i++;
	}
	return (result);
}
