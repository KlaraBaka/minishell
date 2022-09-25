/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radriann <radriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 17:57:59 by radriann          #+#    #+#             */
/*   Updated: 2022/09/18 13:57:18 by radriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	left_redirect(t_com *com)
{
	int	output;

	output = 0;
	output = open(com->file, O_RDONLY);
	if (output == -1)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(com->file, 2);
		ft_putendl_fd(": No such file or directory", 2);
		g_exit_status = 126;
		return ;
	}
	dup2(output, 0);
	close(output);
}

void	right_redirect(t_com *com)
{
	int	output;

	output = 0;
	while (com->delim == 3 && com->file)
	{
		output = open(com->file, O_RDWR | O_CREAT | O_TRUNC, 0644);
		if (output == -1)
		{
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd(com->file, 2);
			ft_putendl_fd(": Permission denied", 2);
			g_exit_status = 126;
			return ;
		}
		if (com->next)
			com = com->next;
		else
			break ;
	}
	dup2(output, 1);
	close(output);
}

void	double_right_redirect(t_com *com)
{
	int	output;

	output = 0;
	while (com->delim == 5 && com->file)
	{
		output = open(com->file, O_RDWR | O_CREAT | O_APPEND, 0644);
		if (output == -1)
		{
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd(com->file, 2);
			ft_putendl_fd(": Permission denied", 2);
			g_exit_status = 126;
			return ;
		}
		if (com->next)
			com = com->next;
		else
			break ;
	}
	dup2(output, 1);
	close(output);
}

void	redirect_handler(t_com *com, int *pipefd)
{
	int	output;

	output = 0;
	if (com->delim == 2)
		left_redirect(com);
	if (com->delim == 3)
		right_redirect(com);
	if (com->delim == 5)
		double_right_redirect(com);
	if (com->delim == 4)
	{
		output = heredoc(com);
		dup2(output, 0);
		close(output);
		if (com->next && com->next->delim == 1)
		{
			close(1);
			dup2(pipefd[1], 1);
			close(pipefd[1]);
			close(pipefd[0]);
		}
	}
}
