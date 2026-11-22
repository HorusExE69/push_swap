/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habretag <habretag@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 15:55:33 by habretag          #+#    #+#             */
/*   Updated: 2026/11/22 11:06:53 by habretag         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	count_words(const char *str, char c)
{
	size_t	i;
	size_t	count;
	int		in_word;

	i = 0;
	count = 0;
	in_word = 0;
	while (str[i])
	{
		if (c != str[i] && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (c == str[i])
			in_word = 0;
		i++;
	}
	return (count);
}

static char	*dup_word(char *s, int len)
{
	char	*word;
	int		i;

	word = malloc(len + 1);
	if (!word)
		return (NULL);
	i = -1;
	while (++i < len)
		word[i] = s[i];
	word[len] = '\0';
	return (word);
}

static int	fill_words(char **tab, int *k, char *s)
{
	int	len;

	while (*s)
	{
		while (*s == ' ')
			s++;
		len = 0;
		while (s[len] && s[len] != ' ')
			len++;
		if (len == 0)
			break ;
		tab[*k] = dup_word(s, len);
		if (!tab[*k])
			return (0);
		(*k)++;
		s += len;
	}
	return (1);
}

char	**parse_args(int argc, char **argv, int *count)
{
	char	**tab;
	int		i;
	int		k;

	*count = 0;
	i = -1;
	while (++i < argc)
	{
		if (count_words(argv[i], ' ') == 0)
			return (NULL);
		*count += count_words(argv[i], ' ');
	}
	tab = malloc(sizeof(char *) * (*count + 1));
	if (!tab)
		return (NULL);
	k = 0;
	i = -1;
	while (++i < argc)
	{
		if (!fill_words(tab, &k, argv[i]))
			return (free_strs(tab));
	}
	tab[k] = NULL;
	return (tab);
}
