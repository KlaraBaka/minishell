/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radriann <radriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 13:38:26 by radriann          #+#    #+#             */
/*   Updated: 2022/09/18 13:38:30 by radriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_next_line(char **line)
{
	int		result;
	int		i;
	char	*buffer;

	buffer = malloc(100000);
	if (!buffer)
		return (0);
	i = 0;
	*line = buffer;
	result = read(0, &buffer[i], 1);
	while (result > 0 && buffer[i] != '\n')
	{
		i++;
		result = read(0, &buffer[i], 1);
	}	
	buffer[i] = '\0';
	return (result);
}
