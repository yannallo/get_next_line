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
#include <stdio.h>
#include <fcntl.h>

char *get_next_line(int fd)
{
	printf("%d", fd);
	return ("wow");
}

int main(void)
{
	get_next_line(open("book.txt", O_RDONLY));
}