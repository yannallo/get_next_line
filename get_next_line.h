/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yallo <yallo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:46:01 by yallo             #+#    #+#             */
/*   Updated: 2023/01/17 11:46:01 by yallo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

#include <stdio.h>

typedef struct s_list
{
	char			*data;
	struct s_list	*next;
}				t_list;

char	*get_next_line(int fd);
//GNL
void	read_addlst(int fd, t_list **list, int *readed_ptr);
void	make_line(t_list *list, char **line);
void	addlst(t_list **list, char *buffer, int readed);

//GNL utils
int		found_newline(t_list *head_ref);
size_t	line_len(t_list *list);

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 8
# endif
#endif