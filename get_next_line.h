/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yallo <yallo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:22:09 by yallo             #+#    #+#             */
/*   Updated: 2023/01/12 14:22:09 by yallo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE
#include <stdlib.h>
#include <unistd.h>

typedef	struct s_list
{
	char			*data;
	struct s_list	*next;
}				t_list;

char	*get_next_line(int fd);
void	ft_lstadd_back(t_list **head, char *buf);

#endif