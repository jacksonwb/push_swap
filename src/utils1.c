/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbeall <jbeall@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 21:28:31 by jbeall            #+#    #+#             */
/*   Updated: 2019/02/01 15:53:08 by jbeall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		convert_val(char *str)
{
	int		val;
	char	*conv;

	val = ft_atoi(str);
	if (ft_strcmp((conv = ft_itoa(val)), str))
		die("Error");
	free(conv);
	return (val);
}

void	ps_init(int num_vals, char **argv, t_stack **stack_a, t_stack **stack_b)
{
	t_val	*temp;
	int		i;

	i = 0;
	*stack_a = (t_stack*)ft_memalloc(sizeof(t_stack));
	*stack_b = (t_stack*)ft_memalloc(sizeof(t_stack));
	(*stack_a)->start = (t_val*)ft_memalloc(sizeof(t_val));
	(*stack_a)->start->val = convert_val(argv[num_vals - 1]);
	(*stack_a)->size = 1;
	(*stack_a)->total = num_vals;
	while (--num_vals > 0)
	{
		temp = (t_val*)ft_memalloc(sizeof(t_val));
		temp->val = convert_val(argv[num_vals - 1]);
		ps_push(temp, (*stack_a));
	}
}

void	print_stack(t_stack *stack)
{
	t_val *ptr;

	ptr = stack->start;
	while (ptr)
	{
		ft_printf("%d\n", ptr->val);
		ptr = ptr->next;
	}
}

void	print_all(t_stack *a, t_stack *b)
{
	ft_printf("stack a:\n");
	print_stack(a);
	ft_printf("stack b:\n");
	print_stack(b);
	ft_printf("\n");
}

void	dup_check(t_stack *stack)
{
	t_val *a;
	t_val *b;

	if (stack->size > 1)
	{
		a = stack->start;
		while (a->next)
		{
			b = a->next;
			while (b)
			{
				if (a->val == b->val)
					die("Error");
				b = b->next;
			}
			a = a->next;
		}
	}
}
