/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:56:23 by acarpent          #+#    #+#             */
/*   Updated: 2024/07/10 14:30:05 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ptrlen(void *p)
{
	char	x;
	int		len;

	x = 0;
	len = 2;
	if (p == 0)
		return (ft_putstrlen("(nil)"));
	ft_putstrlen("0x");
	return (len += ft_hexalen((uintptr_t)p, x));
}
