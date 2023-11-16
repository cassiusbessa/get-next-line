/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caqueiro <caqueiro@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:15:55 by caqueiro          #+#    #+#             */
/*   Updated: 2023/11/13 19:25:45 by caqueiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static size_t line_len(t_list *lst)
{
	t_list	*current;
	size_t	count;
	char	*content;

	if (!lst)
		return (0);
	current = lst;
	count = 0;
	while (current)
	{
		content = current->content;
		while (*content)
		{
			if (*content == '\n')
				return (count + 1);
			content++;
			count++;
		}
		current = current->next;
	}
	return (count);
}

static int find_line_break(t_list *lst)
{
	t_list	*current;
	char	*content;

	if (!lst)
		return (0);
	current = lst;
	while (current)
	{
		content = current->content;
		printf("%s\n", content);
		while (content && *content)
		{
			if (*content == '\n')
				return (1);
			content++;
		}
		current = current->next;
	}
	return (0);
}

static void clean_list(t_list **lst)
{
	t_list	*current;
	t_list	*new;
	size_t	i;

	if (!lst || !*lst)
		return ;
	current = *lst;
	while (current->next)
		current = current->next;
	i = 0;
	while (current->content[i] != '\n' && current->content[i])
		i++;
	new = (t_list *)malloc(sizeof (t_list));
	new->content = ft_substr(current->content, i + 1, ft_strlen(current->content) - i);
	new->next = NULL;
	while (*lst)
	{
		current = *lst;
		*lst = (*lst)->next;
		free(current->content);
		free(current);
	}
	*lst = new;
	printf("novo conteúdo da lista:%s\n", (*lst)->content);
}

static char *get_line(t_list **lst)
{
	int		i;
	int		j;
	char	*line;
	t_list	*current;

	if (lst == NULL)
		return (NULL);
	line = malloc(sizeof (char) * line_len(*lst) + 1);
	if (!line)
		return (NULL);
	j = 0;
	current = *lst;
	while (current)
	{
		i = 0;
		while (current->content && current->content[i])
		{
			if (current->content[i] == '\n')
			{
				line[j++] = '\n';
				line[j] = '\0';
				clean_list(lst);
				return (line);
			}
			line[j++] = current->content[i++];
		}
		lst = &(*lst)->next;
	}
	line[j] = '\0';
	clean_list(lst);
	return (line);
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*buffer_line;
	int				count_read;

	count_read = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (!find_line_break(list) && count_read)
	{
		buffer_line = (char *)malloc(sizeof (char) * BUFFER_SIZE + 1);
		if (!buffer_line)
			return (NULL);
		count_read = read(fd, buffer_line, BUFFER_SIZE);
		if (count_read < 0)
		{
			free(buffer_line);
			return (NULL);
		}
		buffer_line[count_read] = '\0';
		ft_lstadd_back(&list, buffer_line);
	}
	return (get_line(&list));
}

#include <fcntl.h>
int main(void)
{
	int	fd = open("hino.txt", O_RDONLY);
	printf("primeira chamada: %s\n", get_next_line(fd));
	printf("segunda chamada: %s\n", get_next_line(fd));
	printf("terceira chamada: %s\n", get_next_line(fd));
	close(fd);
}
