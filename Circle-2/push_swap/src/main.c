/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:03:48 by acarpent          #+#    #+#             */
/*   Updated: 2024/06/24 13:58:05 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	micromain(int argc, char **argv, t_frst *stack)
{
	int	i;

	i = 0;
	if (argc == 1 || argc == (2 && !argv[1][0]))
		return (0);
	ft_argsec(argv);
	stack->spl = ft_argvsplit(argc, argv);
	i = 0;
	while (stack->spl[i])
	{
		ft_lst(&(stack->a), ft_atoll(stack->spl[i]));
		i++;
	}
	ft_free(stack->spl);
	return (1);
}

int	main(int argc, char **argv)
{
	t_frst	stack;

	null_init(&stack);
	if (!micromain(argc, argv, &stack))
		return (0);
	stack.size_a = ft_lstsize(stack.a);
	stack.size_b = 0;
	if (!is_sorted(stack))
	{
		median(&stack);
		cost(&stack);
	}
	ft_lstfree(&(stack.a));
	ft_lstfree(&(stack.b));
	return (0);
}
