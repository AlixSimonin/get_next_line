/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:43:21 by asimonin          #+#    #+#             */
/*   Updated: 2022/11/29 19:45:37 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_keep_rest(char *stock);
char	*ft_only_line(char *stock);
char	*ft_read_join(int fd, char *stock);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);

size_t	ft_strlen(char *s);

#endif
