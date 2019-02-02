/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbeall <jbeall@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 20:55:16 by jbeall            #+#    #+#             */
/*   Updated: 2019/02/01 14:19:12 by jbeall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	operate(t_stack *stack_a, t_stack *stack_b, char *op)
{
	static char *codes[] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr",
		"rra", "rrb", "rrr", ""};

	ps_do_op(stack_a, stack_b, op_type(op, codes));
	if (stack_a->visual)
		ps_visualize(stack_a, stack_b, op);
	else
		ft_printf("%s\n", op);
}

void	push_swap(t_stack *a, t_stack *b, int len)
{
	int la;
	int lb;
	int lc;

	if (len < 5)
		push_swap_base(a, b, len);
	else
	{
		lc = len - sort_to_b(a, b, find_median(a, len), len);
		if (b->size && b->size <= 5)
			push_swap_small_b(a, b, b->size);
		lb = sort_to_a(a, b, find_median(b, len - lc), len - lc);
		la = len - lc - lb;
		move_num_to_a(a, b, la);
		push_swap(a, b, la);
		push_swap(a, b, lb);
		push_swap(a, b, lc);
	}
}

void	launch_ps_small(t_stack *a, t_stack *b)
{
	if (a->size <= 5)
	{
		push_swap_5(a, b, a->size);
		push_swap_base_b(a, b, b->size);
		move_num_to_a(a, b, b->size);
		ps_5_helper(a, b);
	}
	else
	{
		push_swap_small(a, b, a->size);
		push_swap_small_b(a, b, b->size);
		move_num_to_a(a, b, b->size);
		ps_5_helper(a, b);
	}
}

void	launch_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size < 16 && stack_a->size > 1)
		launch_ps_small(stack_a, stack_b);
	else if (stack_a->size > 1)
		push_swap(stack_a, stack_b, stack_a->size);
}

int		main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack *stack_b;
	char	**input;
	int		visual;

	visual = 0;
	if (argc > 1 && !ft_strcmp("-v", argv[1]))
	{
		visual = 1;
		argc--;
		argv++;
	}
	if (argc == 2)
	{
		input = ft_strsplit(argv[1], ' ');
		ps_init(str_split_len(input), input, &stack_a, &stack_b);
	}
	else if (argc > 2)
		ps_init(argc - 1, (argv + 1), &stack_a, &stack_b);
	else
		return (0);
	visual ? init_visual(stack_a) : 0;
	dup_check(stack_a);
	launch_sort(stack_a, stack_b);
	exit_visual(stack_a);
}
