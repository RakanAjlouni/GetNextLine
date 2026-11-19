/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rajlouni <rajlouni@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 15:53:03 by rajlouni          #+#    #+#             */
/*   Updated: 2026/10/09 15:43:55 by rajlouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != (char)c)
		i++;
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strjoin(char *stash, char *buffer)
{
	size_t	i;
	size_t	j;
	char	*result;

	if (!stash)
	{
		stash = malloc(1);
		if (!stash)
			return (NULL);
		stash[0] = '\0';
	}
	result = malloc(ft_strlen(stash) + ft_strlen(buffer) + 1);
	if (!result)
		return (free(stash), NULL);
	i = 0;
	while (stash[i])
	{
		result[i] = stash[i];
		i++;
	}
	j = 0;
	while (buffer[j])
		result[i++] = buffer[j++];
	result[i] = '\0';
	return (free (stash), result);
}
