/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 18:18:24 by oabushar          #+#    #+#             */
/*   Updated: 2021/12/16 10:20:59 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != 0)
		i++;
	return (i);
}

char	*ft_after_nl(char *res, char *store)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = 0;
	while (res[i] != '\n')
		i++;
	i++;
	store = malloc ((ft_strlen(res) - i) * sizeof(char)); 
	while (res[i])
	{
		store[j] = res[i];
		i++;
	}
	return (store);
}

char	*ft_strdup(char *s1)
{
	int		i;
	char	*ptr;

	i = 0;
	while (s1[i] != '\n')
		i++;
	i++;
	ptr = malloc((i * sizeof(char)) + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (s1[i] != '\n')
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = s1[i];
	ptr[++i] = 0;
	free (s1);
	return (ptr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ret;
	size_t	size;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (0);
	i = 0;
	j = 0;
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	ret = malloc (size * sizeof(char));
	if (!ret)
		return (0);
	if (s1)
	{
		while (s1[i] != '\0')
		{
			ret[i] = s1[i];
			i++;
		}
		free(s1);
	}
	while (j < BUFFER_SIZE)
		ret[i++] = s2[j++];
	ret[i] = 0;
	return (ret);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	j;

	j = (char) c;
	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s != NULL && s[i] == j )
		{
			return ((char *)s + i);
		}
		i++;
	}
	return (NULL);
}

