/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radriann <radriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 13:40:39 by radriann          #+#    #+#             */
/*   Updated: 2022/09/18 13:40:42 by radriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{	
	size_t	len_dest;
	size_t	len_src;
	size_t	i;

	i = 0;
	len_dest = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (!dst)
		return (ft_strlcpy(dst, src, n));
	if (!n)
		return (len_src);
	if (n <= len_dest)
		return (n + len_src);
	else if (n - len_dest <= len_src)
	{
		ft_memcpy(dst + len_dest, src, n - 1);
		dst[n - 1] = '\0';
	}
	else
		ft_memcpy(dst + len_dest, src, len_src + 1);
	return (len_dest + len_src);
}
