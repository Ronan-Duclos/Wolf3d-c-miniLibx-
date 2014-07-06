/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 15:59:20 by rduclos           #+#    #+#             */
/*   Updated: 2014/01/18 14:51:07 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		ft_count_nb_in_str(char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 1)
			j++;
		i++;
	}
	return (j);
}

int		ft_count_str_of_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	return (i);
}

void	free_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab && tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	**ft_realloc_char_tab(char **tab, char *line)
{
	int		i;
	char	**tmp;

	i = ft_count_str_of_tab(tab);
	tmp = (char **)malloc(sizeof(char *) * (i + 2));
	i = 0;
	while (tab[i] != NULL)
	{
		tmp[i] = ft_strdup(tab[i]);
		i++;
	}
	tmp[i] = ft_strdup(line);
	i++;
	tmp[i] = NULL;
	free(line);
	free_tab(tab);
	return (tmp);
}
