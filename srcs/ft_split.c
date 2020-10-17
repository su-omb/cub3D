/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 22:07:02 by obouykou          #+#    #+#             */
/*   Updated: 2020/03/08 19:29:05 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int		ft_words(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s && *s == c)
		s++;
	while (*s)
	{
		if ((*s == c && *(s + 1) != c) || *(s + 1) == '\0')
			len++;
		s++;
	}
	return (len);
}

static int		ft_len_elem(char const *s, char c)
{
	int		i;
	int		size;

	i = 0;
	size = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		i++;
		size++;
	}
	return (size);
}

static char		**ft_exception(char const *s)
{
	char	**tab;

	tab = NULL;
	if (!s)
	{
		tab = (char **)malloc(1 * sizeof(char *));
		tab[0] = NULL;
	}
	return (tab);
}

char			**free_str_table(char **tab, int size)
{
	if (!tab)
		return (NULL);
	while (size--)
		free(tab[size]);
	free(tab);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		l;

	if ((tab = ft_exception(s)))
		return (tab);
	l = ft_words(s, c);
	j = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * (l + 1))))
		return (NULL);
	tab[l] = NULL;
	while (j < l)
	{
		while (*s && *s == c)
			s++;
		if (!(tab[j] = (char *)malloc((ft_len_elem(s, c) + 1) * sizeof(char))))
			return (free_str_table(tab, l));
		i = 0;
		while (*s && *s != c)
			tab[j][i++] = *s++;
		tab[j++][i] = '\0';
	}
	return (tab);
}
