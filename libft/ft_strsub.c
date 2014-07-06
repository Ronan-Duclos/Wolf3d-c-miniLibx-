/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 17:07:59 by rduclos           #+#    #+#             */
/*   Updated: 2013/11/29 12:23:06 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char		*ft_strnew(size_t size);
char		*ft_strncpy(char *s1, const char *s2, size_t n);

char		*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char		*str;

	str = ft_strnew(len);
	if (str == NULL || len == 0)
		return (NULL);
	ft_strncpy(str, s + start, len);
	return (str);
}
