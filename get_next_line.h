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

typedef struct s_list
{
	char			*data;
	struct s_list	*next;
}				t_list;

//GNL
char	*get_next_line(int fd);
void	read_addlst(int fd, t_list **list);
void	make_line(t_list *list, char **line);
void	add_list(t_list **list, char *buffer, int readed);
void	clear_list(t_list **list);

//GNL utils
int		check_newline(t_list *head_ref);
void	malloc_line(t_list *list, char **line);
size_t	ft_strlen(char *buf);
t_list	*last_node(t_list *list);
void	free_list(t_list **list);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif
#endif
