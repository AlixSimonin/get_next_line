/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:45:11 by asimonin          #+#    #+#             */
/*   Updated: 2022/11/26 16:18:19 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_only_line(char *stock)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	if (!stock[i])
		return (NULL);
	while (stock[i] && stock[i] != '\n')
		i++;
	str = malloc((i + 2) * sizeof(char));
	if (!str)
		return (NULL);
	j = 0;
	while (j <= i)
	{
		str[j] = stock [j];
		j++;
	}
	if (stock[i] == '\n')
	{
		str[i] = stock[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_keep_rest(char *stock)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (stock[i] && stock[i] != '\n')
		i++;
	if (!stock[i])
	{
		free(stock);
		return (NULL);
	}
	str = malloc((ft_strlen(stock) - i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i++;
	while (stock[i])
		str[j++] = stock[i++];
	str[j] = '\0';
	free(stock);
	return (str);
}

char	*ft_read_join(int fd, char *stock)
{
	char	*buf;
	int		size_read;

	size_read = 1;
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	while (!ft_strchr(stock, '\n') && size_read != 0)
	{
		size_read = read(fd, buf, BUFFER_SIZE);
		if (size_read == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[size_read] = '\0';
		stock = ft_strjoin(stock, buf);
	}
	free(buf);
	return (stock);
}

char	*get_next_line(int fd)
{
	static char	*stock[4096];
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	stock[fd] = ft_read_join(fd, stock[fd]);
	if (!stock[fd])
		return (NULL);
	str = ft_only_line(stock[fd]);
	stock[fd] = ft_keep_rest (stock[fd]);
	return (str);
}
