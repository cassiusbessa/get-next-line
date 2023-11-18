/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caqueiro <caqueiro@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:12:47 by caqueiro          #+#    #+#             */
/*   Updated: 2023/11/13 18:12:49 by caqueiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	ft_lstadd_back(t_list **lst, void *content)
{
	t_list	*new;
	t_list	*current;

	new = (t_list *)malloc(sizeof (t_list));
	if (!new)
		return ;
	new->content = content;
	new->next = NULL;
	if (!*lst || !lst)
	{
		*lst = new;
		return ;
	}
	current = *lst;
	while (current->next)
		current = current->next;
	current->next = new;
}

void	free_list(t_list **lst)
{
	t_list	*current;

	if (!lst || !*lst)
		return ;
	current = *lst;
	while (current)
	{
		*lst = current->next;
		free(current->content);
		free(current);
		current = *lst;
	}
	*lst = NULL;
}

size_t	line_len(t_list *lst)
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

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;
	size_t	size;

	if (!s)
		return (NULL);
	if (!len || start >= ft_strlen(s))
		return (ft_strdup(""));
	size = ft_strlen(s + start);
	if (size > len)
		size = len;
	sub = (char *)malloc(sizeof (char) * (size + 1));
	if (!sub)
		return (NULL);
	i = 0;
	while (len-- && s[start + i])
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*dup;
	int		i;

	i = 0;
	while (src[i])
		i++;
	dup = (char *)malloc(((i + 1) * sizeof (char)));
	if (!dup)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

/*void	ft_print_list(t_list *lst)
{
	t_list	*current;

	current = lst;
	while (current)
	{
		printf("%s", (char *)current->content);
		current = current->next;
	}
}*/
