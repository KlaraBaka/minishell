/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radriann <radriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 17:53:36 by radriann          #+#    #+#             */
/*   Updated: 2022/09/18 13:33:38 by radriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	heredoc(t_com *com)
{
	char	*line;
	int		fd[2];

	pipe(fd);
	while (1)
	{
		line = readline("> ");
		if (!line || !ft_strcmp(com->file, line))
		{
			ft_free(line);
			close(fd[1]);
			return (fd[0]);
		}
		ft_putendl_fd(line, fd[1]);
		ft_free(line);
	}
}
