/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikarzum <mikarzum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 19:41:08 by mikarzum          #+#    #+#             */
/*   Updated: 2022/07/24 20:54:43 by mikarzum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	nl(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*remove_line(char *s, char *line)
{
	int		i;
	int		j;
	char	*rt;

	i = 0;
	j = 0;
	rt = (char *)malloc(sizeof(char) * (ft_strlen(s) - ft_strlen(line) + 1));
	if (!rt)
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	i += (s[i] == '\n');
	while (s[i])
	{
		rt[j] = s[i];
		i++;
		j++;
	}
	free(s);
	rt[j] = '\0';
	return (rt);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	char		*line;
	static char	*s;
	int			fin;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	fin = 1;
	while (fin > 0)
	{
		fin = read(fd, buf, BUFFER_SIZE);
		if ((!s && !fin) || (s && !s[0] && !fin) || (fin < 0))
		{
			free(s);
			s = NULL;
			return (NULL);
		}
		buf[fin] = '\0';
		s = ft_strjoin(s, buf);
		if (nl(s))
			break ;
	}
	line = get_line(s);
	s = remove_line(s, line);
	return (line);
}
