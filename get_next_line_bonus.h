/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caqueiro <caqueiro@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 22:19:20 by caqueiro          #+#    #+#             */
/*   Updated: 2023/11/21 22:19:26 by caqueiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h> 

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef MAX_FD
#  define MAX_FD 1024
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
