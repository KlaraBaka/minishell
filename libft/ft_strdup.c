/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radriann <radriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 13:41:02 by radriann          #+#    #+#             */
/*   Updated: 2022/09/18 13:41:05 by radriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*pointer;
	size_t	i;
	size_t	size;

	i = 0;
	size = ft_strlen(s1);
	pointer = malloc(sizeof(char) * (size + 1));
	if (!(pointer))
		return (NULL);
	while (s1[i] != '\0')
	{
		pointer[i] = s1[i];
		i++;
	}
	pointer[i] = '\0';
	return (pointer);
}
