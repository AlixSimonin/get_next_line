/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:48:11 by asimonin          #+#    #+#             */
/*   Updated: 2022/11/29 19:44:20 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line_bonus(int fd);
char	*ft_keep_rest(char *stock);
char	*ft_only_line(char *stock);
char	*ft_read_join(int fd, char *stock);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);

size_t	ft_strlen(char *s);

#endif