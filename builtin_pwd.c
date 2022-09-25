/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radriann <radriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 17:52:23 by radriann          #+#    #+#             */
/*   Updated: 2022/09/18 13:52:13 by radriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_pwd(t_envp *envp_list)
{
	char	*pwd;

	if (!envp_list)
		return (1);
	pwd = get_value_from_envp(envp_list, "PWD");
	if (!pwd)
	{
		pwd = getcwd(NULL, 0);
		if (!pwd)
		{
			if (chdir("..") == -1)
			{
				perror("minishell: pwd: ");
				return (1);
			}
			pwd = getcwd(NULL, 0);
		}
	}
	ft_putendl_fd(pwd, 1);
	ft_free(pwd);
	return (0);
}
