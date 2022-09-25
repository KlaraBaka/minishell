/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radriann <radriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 18:00:02 by radriann          #+#    #+#             */
/*   Updated: 2022/09/18 13:33:38 by radriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free(char *str)
{
	if (str)
		free(str);
}

void	free_envp_list(t_envp *envp_list)
{
	if (!envp_list)
		return ;
	while (envp_list)
	{
		if (envp_list->key)
			ft_free(envp_list->key);
		if (envp_list->value)
			ft_free(envp_list->value);
		envp_list = envp_list->next;
	}
	free(envp_list);
	envp_list = NULL;
}

void	free_com_list(t_com *com)
{
	t_com	*tmp;

	if (com)
	{
		while (com)
		{
			tmp = com->next;
			if (com->name)
				ft_free(com->name);
			if (com->arg)
				free_array(com->arg);
			if (com->file)
				ft_free(com->file);
			com = tmp;
		}
		if (com)
			free(com);
	}
}

void	ft_free_com_list(t_com **com)
{
	t_com	*tmp;

	if (*com)
	{
		while (*com)
		{
			tmp = (*com)->next;
			if ((*com)->name)
				ft_free((*com)->name);
			if ((*com)->arg)
				free_array((*com)->arg);
			if ((*com)->file)
				ft_free((*com)->file);
			if (*com)
				free(*com);
			(*com) = tmp;
		}
		if ((*com))
			free((*com));
	}
}

void	free_array(char **arr)
{
	int	i;

	i = 0;
	if (arr)
	{
		if (arr[i])
		{
			while (arr[i])
			{
				ft_free(arr[i]);
				i++;
			}
		}
		free(arr);
	}
}
