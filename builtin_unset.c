/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radriann <radriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 17:52:45 by radriann          #+#    #+#             */
/*   Updated: 2022/09/18 13:33:38 by radriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	delete_from_env(t_envp **envp_list, char *arg)
{
	t_envp	*tmp;

	tmp = *envp_list;
	while (*envp_list)
	{
		if (*envp_list && !ft_strcmp((*envp_list)->key, arg))
		{
			tmp = (*envp_list)->next;
			ft_free((*envp_list)->key);
			ft_free((*envp_list)->value);
			free (*envp_list);
			*envp_list = tmp;
		}
		if ((*envp_list)->next && !ft_strcmp((*envp_list)->next->key, arg))
		{
			ft_free((*envp_list)->next->key);
			ft_free((*envp_list)->next->value);
			free((*envp_list)->next);
			(*envp_list)->next = (*envp_list)->next->next;
		}
		*envp_list = (*envp_list)->next;
	}
	*envp_list = tmp;
}

int	builtin_unset(t_com *com, t_envp **envp_list)
{
	int	i;

	if (!envp_list || !com)
		return (1);
	if (!com->arg)
		return (0);
	i = 0;
	while (com->arg[i])
	{
		delete_from_env(envp_list, com->arg[i]);
		i++;
	}
	return (0);
}
