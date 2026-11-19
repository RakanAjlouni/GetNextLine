/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rajlouni <rajlouni@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 19:58:34 by rajlouni          #+#    #+#             */
/*   Updated: 2026/10/09 17:20:12 by rajlouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_and_stash(int fd, char *stash)
{
	char	*buffer;
	int		bytes_read;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (free (stash), NULL);
	bytes_read = 1;
	while (!ft_strchr(stash, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			free(stash);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		stash = ft_strjoin(stash, buffer);
		if (!stash)
			return (free(buffer), NULL);
	}
	free(buffer);
	return (stash);
}

char	*extract_line(char *stash)
{
	int		i;
	int		j;
	char	*line;

	if (!stash || !stash[0])
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		i++;
	}
	if (stash[i] == '\n')
		i += 1;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = stash[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*clean_stash(char *stash)
{
	int		i;
	int		j;
	char	*leftovers;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
		return (free(stash), NULL);
	i++;
	if (!stash[i])
		return (free(stash), NULL);
	leftovers = malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	if (!leftovers)
	{
		free(stash);
		return (NULL);
	}
	j = 0;
	while (stash[i])
		leftovers[j++] = stash[i++];
	leftovers[j] = '\0';
	free(stash);
	return (leftovers);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_and_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = extract_line(stash);
	stash = clean_stash(stash);
	return (line);
}
