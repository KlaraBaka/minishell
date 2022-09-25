/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radriann <radriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 13:45:54 by radriann          #+#    #+#             */
/*   Updated: 2022/09/18 13:51:28 by radriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_env(t_envp *envp_list)
{
	if (!envp_list)
		return (1);
	if (var_position_in_envp(envp_list, "PATH") == -1)
	{
		ft_putendl_fd("minishell: env: No such file or directory", 2);
		return (127);
	}
	while (envp_list)
	{
		ft_putstr_fd(envp_list->key, 1);
		ft_putchar_fd('=', 1);
		ft_putendl_fd(envp_list->value, 1);
		envp_list = envp_list->next;
	}
	return (0);
}
