/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radriann <radriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 17:53:11 by radriann          #+#    #+#             */
/*   Updated: 2022/09/18 13:33:38 by radriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_separator(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == '|' || c == '<' || c == '>')
		return (1);
	else
		return (0);
}

void	count_redirects(char *str, int *ind, int *num_words)
{
	int	i;
	int	words;

	i = *ind;
	words = *num_words;
	if (str[i] == '<')
	{
		if (str[i + 1] && str[i + 1] == '<')
			i++;
		words++;
		i++;
	}
	else if (str[i] == '>')
	{
		if (str[i + 1] && str[i + 1] == '>')
			i++;
		words++;
		i++;
	}
	*num_words = words;
	*ind = i;
}

void	count_rest(char *str, int *ind, int *num_words)
{
	int	i;
	int	count_one;
	int	count_double;

	count_one = 0;
	count_double = 0;
	i = *ind;
	while (str[i])
	{
		if (ft_separator(str[i]) && count_one % 2 == 0 && count_double % 2 == 0)
		{
			(*num_words)++;
			*ind = i;
			return ;
		}
		if (str[i] == '\'' && count_double % 2 == 0)
			count_one++;
		if (str[i] == '\"' && count_one % 2 == 0)
			count_double++;
		i++;
	}
	(*num_words)++;
	*ind = i;
}

int	count_words(char *str, int i, int words)
{
	while (str[i])
	{
		while (str[i] && ft_isspace(str[i]))
			i++;
		if (str[i] == '|')
		{
			words++;
			i++;
		}
		else if (str[i] == '<' || str[i] == '>')
			count_redirects(str, &i, &words);
		else if (str[i + 1] && (!ft_strncmp(&str[i], "\'\'", 2)
				|| !ft_strncmp(&str[i], "\"\"", 2)))
			i += 2;
		else
			count_rest(str, &i, &words);
	}
	return (words);
}
