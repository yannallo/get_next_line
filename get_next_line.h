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
# ifndef BUFFER_SIZE
# define BUFFER_SIZE 8
# endif
# include <stdlib.h>
# include <unistd.h>

# include <stdio.h>

typedef struct s_list
{
	char			*data;
	struct s_list	*next;
}				t_list;

char	*get_next_line(int fd);
void	ft_lstadd_back(t_list **head, char *buffer);
int		check(char *buffer);
char	*make_line(t_list *head, char *buffer);

#endif