/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yallo <yallo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:17:07 by yallo             #+#    #+#             */
/*   Updated: 2022/12/23 15:17:07 by yallo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

char *get_next_line(int fd)
{
	char	*buf;
	t_list	*list;

	
	while (check(buf))
	{
		read(fd, buf, 5);

	}
}

#include <fcntl.h>

int main(void)
{
	get_next_line(open("book.txt", O_RDONLY));
}
