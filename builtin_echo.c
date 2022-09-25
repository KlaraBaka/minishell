/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radriann <radriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 13:46:07 by radriann          #+#    #+#             */
/*   Updated: 2022/09/18 13:46:11 by radriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_to_string_from_array(char **array, int i)
{
	char	*tmp;

	while (array[i])
	{
		if (!ft_strcmp(array[i], "$?"))
		{
			tmp = ft_itoa(g_exit_status);
			ft_putstr_fd(tmp, 1);
			ft_free(tmp);
		}
		else
			ft_putstr_fd(array[i], 1);
		if (array[i + 1])
			ft_putchar_fd(' ', 1);
		i++;
	}
}

int	builtin_echo(t_com *com)
{
	int	i;

	i = 0;
	while (com)
	{
		if (!com->arg)
		{
			ft_putchar_fd('\n', 1);
		}
		else if (!ft_strcmp(com->arg[i], "-n"))
		{
			while (!ft_strcmp(com->arg[i], "-n"))
				i++;
			print_to_string_from_array(com->arg, i);
		}
		else
		{
			print_to_string_from_array(com->arg, i);
			ft_putchar_fd('\n', 1);
		}
		com = com->next;
	}
	return (0);
}
