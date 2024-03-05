/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaracci <acaracci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:37:14 by acaracci          #+#    #+#             */
/*   Updated: 2024/03/05 16:11:09 by acaracci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *read_char(int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	size;
	int		count;
	char	*backup;

	backup = NULL;
	size = 1;
	count = 1;

	while (!ft_strchr(buffer, '\n'))
	{
		size = read(fd, buffer , BUFFER_SIZE);
		if (size == -1)
			return(NULL);
		buffer[size] = '\0';
		backup = ft_strjoin(backup, buffer);
	}
	return(backup);	 
}
char	*get_next_line(int fd)
{
	static char	*buffer;
	
	if(fd <= 0 || BUFFER_SIZE <= 0)
		return(NULL);
	printf("LINES: %s\n", read_char(fd));
	return(NULL);
}
char	*split_line(char *line)
{
	
}