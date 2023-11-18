/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caqueiro <caqueiro@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:08:41 by caqueiro          #+#    #+#             */
/*   Updated: 2023/11/13 18:09:01 by caqueiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	char				*content;
	struct s_list		*next;
}						t_list;
char	*get_next_line(int fd);
void	free_list(t_list **lst);
void	ft_lstadd_back(t_list **lst, void *content);
size_t	ft_strlen(char *s);
char	*ft_strdup(char *src);
char	*ft_substr(char *s, unsigned int start, size_t len);
size_t	line_len(t_list *lst);

#endif
