/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radriann <radriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 13:46:16 by radriann          #+#    #+#             */
/*   Updated: 2022/09/18 13:46:19 by radriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*cut_tail_string(char *str)
{
	int	i;

	if (!str)
		return (NULL);
	i = ft_strlen(str);
	while (str[i] != '/')
		i--;
	return (ft_substr(str, 0, i + 1));
}

static int	home_directory(t_com *com, char *home)
{
	char	*tmp;

	if (!com->arg || !ft_strcmp(com->arg[0], "~"))
		chdir(home);
	else
	{
		if (!ft_strncmp(com->arg[0], "~/", 2))
		{
			tmp = com->arg[0] + 1;
			com->arg[0] = ft_strjoin(home, "/");
			com->arg[0] = ft_strjoin(com->arg[0], tmp);
		}
		else
		{
			tmp = cut_tail_string(home);
			com->arg[0] = ft_strjoin(tmp, com->arg[0] + 1);
			ft_free(tmp);
		}
		chdir(com->arg[0]);
	}
	return (0);
}

static int	change_directory(t_com *com, char *home, char *pwd, char *old_pwd)
{
	char	*tmp;

	if (!com->arg || !ft_strncmp(com->arg[0], "~", 1))
		home_directory(com, home);
	else if (!ft_strcmp(com->arg[0], "."))
		chdir(pwd);
	else if (!ft_strcmp(com->arg[0], "-"))
	{
		chdir(old_pwd);
		ft_putendl_fd(old_pwd, 1);
	}
	else if (!ft_strcmp(com->arg[0], ".."))
	{
		tmp = cut_tail_string(pwd);
		chdir(tmp);
		ft_free(tmp);
	}
	else
	{
		if (chdir(com->arg[0]) == -1)
			perror("cd");
	}
	return (0);
}

int	builtin_cd(t_com *com, t_envp *envp_list)
{
	char	*home;
	char	*pwd;
	char	*old_pwd;

	if (!envp_list || !com)
		return (1);
	home = get_value_from_envp(envp_list, "HOME");
	pwd = get_value_from_envp(envp_list, "PWD");
	old_pwd = get_value_from_envp(envp_list, "OLDPWD");
	if (!home || !pwd || !old_pwd)
		return (1);
	change_directory(com, home, pwd, old_pwd);
	if (put_value_to_envp(envp_list, "OLDPWD", pwd))
		return (1);
	if (put_value_to_envp(envp_list, "PWD", getcwd(NULL, 0)))
		return (1);
	ft_free(home);
	ft_free(old_pwd);
	return (0);
}
