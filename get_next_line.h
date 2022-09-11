/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 21:30:36 by ntitan            #+#    #+#             */
/*   Updated: 2022/01/06 21:30:38 by ntitan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 42

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

char	*ft_substr(char *s, int start, int len);
char	*get_next_line(const int fd);
char	*ft_strcpy(char *dst, char *src);
int		ft_strlen(char *c);
void	*ft_memcpy(void *dst, void *src, size_t n);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s1);
char	*ft_strchr(char *s, int c);
void	ft_strdel(char **basket);

#endif
