/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radriann <radriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 13:32:42 by radriann          #+#    #+#             */
/*   Updated: 2022/09/18 13:32:52 by radriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(char c)
{
	if ((c == ' ' || c == '\t' || c == '\n' || c == '\v'
			|| c == '\f' || c == '\r'))
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	unsigned int			i;
	int						sign;
	unsigned long long int	num;

	i = 0;
	num = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (num > 9223372036854775807 && sign == 1)
			return (-1);
		if (num > 9223372036854775807 && sign == -1)
			return (0);
		num = num * 10 + (str[i++] - '0');
	}
	return ((int)(num * sign));
}
