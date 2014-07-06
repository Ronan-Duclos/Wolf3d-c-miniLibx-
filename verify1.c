/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 16:39:12 by rduclos           #+#    #+#             */
/*   Updated: 2014/01/19 15:45:58 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		verify_nb_line(char **tab)
{
	int		i;
	int		size;

	i = 1;
	if (tab[0] == NULL || tab[1] == NULL || tab[2] == NULL)
		return (0);
	else
	{
		size = ft_count_nb_in_str(tab[0]);
		while (tab[i] != NULL)
		{
			if (size != ft_count_nb_in_str(tab[i]))
				return (0);
			i++;
		}
	}
	return (size);
}

int		verify_map_wall2(char **tab, int i)
{
	int		j;

	j = 0;
	i--;
	while (tab[i][j] != '\0')
	{
		if (tab[i][j] == 0)
		{
			free(tab);
			return (0);
		}
		j++;
	}
	i = 0;
	j = ft_count_nbs(tab[0]) - 1;
	while (tab[i] != NULL)
	{
		if (tab[i][j] == 0)
		{
			free(tab);
			return (0);
		}
		i++;
	}
	return (1);
}

int		verify_map_wall(char **tab)
{
	int		i;

	i = 0;
	while (tab[0][i] != '\0')
	{
		if (tab[0][i] == 0)
		{
			free_tab(tab);
			return (0);
		}
		i++;
	}
	i = 0;
	while (tab[i] != NULL)
	{
		if (tab[i][0] == 0)
		{
			free_tab(tab);
			return (0);
		}
		i++;
	}
	if (verify_map_wall2(tab, i) == 0)
		return (0);
	return (1);
}

char	**verify_my_map(int fd)
{
	char	*line;
	char	**map;

	map = (char **)malloc(sizeof(char *) * 1 + 1);
	map[0] = NULL;
	while (get_next_line(fd, &line) > 0 && ft_strcmp(line, "start") != 0)
	{
		map = ft_realloc_char_tab(map, ft_strdup(line));
		free(line);
	}
	if (verify_nb_line(map) == 0)
		return (NULL);
	if (verify_map_wall(map) == 0)
		return (NULL);
	return (map);
}
