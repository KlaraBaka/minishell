/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radriann <radriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 17:53:00 by radriann          #+#    #+#             */
/*   Updated: 2022/09/18 13:33:38 by radriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_eve_quotes(char *str)
{
	int	count_one;
	int	count_double;
	int	i;

	i = 0;
	count_one = 0;
	count_double = 0;
	while (str[i])
	{
		if (str[i] == '\'' && count_double % 2 == 0)
			count_one++;
		if (str[i] == '\"' && count_one % 2 == 0)
			count_double++;
		i++;
	}
	if (count_double % 2 == 0 && count_one % 2 == 0)
		return (0);
	else
		return (1);
}

int	ft_check_first_end(char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = ft_strtrim(str, WHITE_SPACES);
	if (tmp[i] == '|')
	{
		ft_free(tmp);
		return (1);
	}
	while (tmp[i])
		i++;
	i--;
	if (tmp[i] == '|' || tmp[i] == '<' || tmp[i] == '>')
	{
		ft_free(tmp);
		return (1);
	}
	ft_free(tmp);
	return (0);
}

int	check_syntax(char *str)
{
	if (!ft_strlen(str) || ft_check_eve_quotes(str) || ft_check_first_end(str))
	{
		printf("syntax error near unexpected token `newline'\n");
		return (1);
	}
	else
		return (0);
}

int	check_double_delim(char **arr)
{
	int	i;

	i = 0;
	if (ft_isdelim(arr[i]) && !arr[i + 1])
		return (1);
	while (arr[i++])
		if (arr[i] && ft_isdelim(arr[i - 1]) && ft_isdelim(arr[i]))
			return (1);
	return (0);
}
