/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:56:32 by acarpent          #+#    #+#             */
/*   Updated: 2024/07/23 15:38:26 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s)
	{
		while (s[i])
			i++;
	}
	return (i);
}
/*
#include <stdio.h>

int	main(int argc, char **argv)
{
	(void)argc;

	ft_strlen(argv[1]);
	printf("%d", ft_strlen(argv[1]));
	return (0);
}
*/
