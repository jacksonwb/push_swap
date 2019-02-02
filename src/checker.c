/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbeall <jbeall@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 19:50:29 by jbeall            #+#    #+#             */
/*   Updated: 2019/02/01 12:47:43 by jbeall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check(t_stack *stack_a, t_stack *stack_b)
{
	t_val	*a;

	a = stack_a->start;
	while (a->next)
	{
		if (a->val > a->next->val)
			return (0);
		a = a->next;
	}
	if (!stack_b->start)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	int			op_code;
	char		**input;
	static char	*codes[] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr",
		"rra", "rrb", "rrr", ""};

	if (argc == 2)
	{
		input = ft_strsplit(argv[1], ' ');
		ps_init(str_split_len(input), input, &stack_a, &stack_b);
	}
	else if (argc > 2)
		ps_init(argc - 1, (argv + 1), &stack_a, &stack_b);
	else
		return (0);
	dup_check(stack_a);
	while ((op_code = get_op(0, codes)) >= 0)
		ps_do_op(stack_a, stack_b, op_code);
	ft_printf(check(stack_a, stack_b) ? "OK\n" : "KO\n");
	return (0);
}
