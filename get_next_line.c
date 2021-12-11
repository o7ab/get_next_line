/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 21:10:45 by oabushar          #+#    #+#             */
/*   Updated: 2021/12/11 09:48:56 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	str[BUFFER_SIZE];
	char	*res;
	int		bytes;

	res = 0;
	bytes = 1;
	while (!ft_strchr(res, '\n') && bytes != 0)
	{
		bytes = read(fd, str, BUFFER_SIZE);
		char *res = ft_strjoin(res, str);
	}
	if (bytes == 0)
		return (0);
	else 
		res = ft_strdup(res);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*ptr;

	i = 0;
	while (s1[i] != 0)
	{
		i++;
	}
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
	free (s1);
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	size;

	if (!s1 || !s2)
		return (0);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	ret = malloc (ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ret)
		return (0);
	ft_strlcpy(ret, s1, size);
	ft_strlcat(ret, s2, size);
	free (s1);
	return (ret);
}

int main()
{
	int fd;
	fd = open("file1", O_RDONLY);

	char *line = get_next_line(fd);
	printf("%s\n", line);
	//line = get_next_line(fd);
	//printf("%s\n", line);
	return 1;
}
