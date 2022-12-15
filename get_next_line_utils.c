/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikarzum <mikarzum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 00:40:14 by mikarzum          #+#    #+#             */
/*   Updated: 2022/07/23 22:12:22 by mikarzum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *s)
{
	int		i;
	char	*rt;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	i += (s[i] == '\n');
	rt = malloc(sizeof(char) * (i + 1));
	if (!rt)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		rt[i] = s[i];
		i++;
	}
	if (s[i])
		rt[i++] = '\n';
	rt[i] = '\0';
	return (rt);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*sum;
	int		i;
	int		j;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	sum = malloc(sizeof(char) * (i + j + 1));
	if (!sum)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		sum[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		sum[i++] = s2[j++];
	sum[i] = '\0';
	free(s1);
	return (sum);
}
