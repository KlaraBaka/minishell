/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radriann <radriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 17:59:53 by radriann          #+#    #+#             */
/*   Updated: 2022/09/18 13:33:38 by radriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	lstsize(t_com *lst)
{
	int	i;

	i = 0;
	if (lst)
	{
		while (lst)
		{
			i++;
			lst = lst->next;
		}
	}
	return (i);
}

int	envsize(t_envp *lst)
{
	int	i;

	i = 0;
	if (lst)
	{
		while (lst)
		{
			i++;
			lst = lst->next;
		}
	}
	return (i);
}

int	count_array(t_com *com)
{
	int	i;

	i = 0;
	while (com->arg[i])
		i++;
	return (i);
}

int	count_pipes(t_com *com)
{
	t_com	*command;
	int		pipes;

	pipes = 0;
	command = com;
	while (command)
	{
		if (command->delim == 1)
			pipes++;
		command = command->next;
	}
	return (pipes);
}
