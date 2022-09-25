/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radriann <radriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 13:39:49 by radriann          #+#    #+#             */
/*   Updated: 2022/09/18 13:39:52 by radriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*res;
	int		len;

	i = 0;
	res = (char *)s;
	len = 0;
	while (res[len])
		len++;
	while (len >= 0)
	{
		if (res[len] == (char)c)
			return (&res[len]);
		len--;
	}
	if (c == '\0')
		return (&res[len]);
	return (NULL);
}
