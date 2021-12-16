/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 21:10:45 by oabushar          #+#    #+#             */
/*   Updated: 2021/12/16 10:13:57 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "get_next_line_utils.c"

char	*get_next_line(int fd)
{
	char	str[BUFFER_SIZE + 1];
	char	*res;
	int		bytes;
	static char *store;

	bytes = 1;
	res = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	while (bytes > 0 && !ft_strchr(res, '\n'))
	{
		if (store)
			res = ft_strcat(store, res);
		bytes = read(fd, str, BUFFER_SIZE);
		str[BUFFER_SIZE] = 0;
		res = ft_strjoin(res, str);
	}
	if (bytes == 0)
		return (0);
	else
		store = ft_after_nl(res, store);
		res = ft_strdup(res);
	return(res);
}

char	*ft_strcat(char *dst, char *src)
{
	size_t	i;
	size_t	srclen;
	size_t	dstlen;

	i = 0;
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	while (src[i])
	{
		dst[dstlen] = src[i];
		dstlen++;
		i++;
	}
	dst[dstlen] = 0;
	return (dst);
}

int main()
{
	int fd;
	// char *line;
	 fd = open("file1", O_RDONLY);
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	// line = get_next_line(fd);
	// printf("%s\n", line);
	return 1;
}
