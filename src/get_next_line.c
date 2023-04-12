/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 21:11:34 by yarutiun          #+#    #+#             */
/*   Updated: 2023/04/12 21:13:51 by yarutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

char *get_next_line(int fd)
{
	int i;
	int readed;
	char c;
	char *buff;

	i = 0;
	buff = malloc(sizeof(char) * 100);
	while((readed = read(fd, &c, 1)) > 0)
	{
		buff[i++] = c;
		if(c == '\n')
			break;
	}
	if((!buff[i - 1] && !readed) || readed == -1)
	{
		free(buff);
		return(NULL);
	}
	buff[i] = '\0';
	return(buff);
}