/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaghda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:03:40 by mabaghda          #+#    #+#             */
/*   Updated: 2025/05/19 18:19:06 by mabaghda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/gnl.h"

size_t	gnl_strlen(const char *str)
{
	int	a;

	a = 0;
	if (str == NULL)
		return (0);
	while (str[a] != '\0')
		a++;
	return (a);
}

int	gnl_strchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*result;
	size_t	m;
	size_t	n;

	if (!s1 && !s2)
		return (NULL);
	result = (char *)malloc((gnl_strlen(s1)
				+ gnl_strlen(s2) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	m = 0;
	while (s1 && s1[m])
	{
		result[m] = s1[m];
		m++;
	}
	n = 0;
	while (s2 && s2[n])
		result[m++] = s2[n++];
	result[m] = '\0';
	free(s1);
	s1 = NULL;
	return (result);
}

char	*gnl_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= gnl_strlen(s))
	{
		substr = (char *)malloc(1);
		if (!substr)
			return (NULL);
		substr[0] = '\0';
		return (substr);
	}
	if (len > gnl_strlen(s) - start)
		len = gnl_strlen(s) - start;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len)
		substr[i++] = s[start++];
	substr[i] = '\0';
	return (substr);
}
