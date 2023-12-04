/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwubuntu <uwubuntu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:34:19 by uwubuntu          #+#    #+#             */
/*   Updated: 2023/10/29 14:43:35 by uwubuntu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Enter file to read\n");
		return (1);
	}
	int fd = open(argv[1], O_RDONLY);
	char	*bf;
	get_next_line(fd, &bf);
	// printf("%s", bf);
}

