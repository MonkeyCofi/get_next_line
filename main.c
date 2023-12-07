/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:34:19 by uwubuntu          #+#    #+#             */
/*   Updated: 2023/12/06 20:14:38 by pipolint         ###   ########.fr       */
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
	char *str;
	while ((str = get_next_line(fd)))
		printf("%s", str), free(str);
}

