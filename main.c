/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:01:54 by jperez            #+#    #+#             */
/*   Updated: 2022/10/08 20:08:00 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

/*
int		main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc == 1)
		fd = 0;
	else if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		return (2);
	line = get_next_line(fd);
	printf("%s", line);
	while (line != NULL)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	}
	if (argc == 2)
		close(fd);
}
*/

/*
int		main(int argc, char **argv)
{
	int		fd;
	char *line;
	fd = open(argv[1], O_RDONLY);

	printf("\n-----------------------\n");

	line = get_next_line(fd);
	printf("%s", line);

	line = get_next_line(fd);
	printf("%s", line);
	
	close(fd);
	printf("\n-------- temp ---------------\n");
	char *temp;
	printf("%d\n", fd);
   	do
   	{
   		temp = get_next_line(fd);
   		free(temp);
   	} while (temp != NULL);

	printf("\n-------- new_open ---------------\n");

	fd = open(argv[1], O_RDONLY);
	while (line != NULL)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	}
}
*/
