/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_handlers3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbeall <jbeall@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 21:31:41 by jbeall            #+#    #+#             */
/*   Updated: 2019/02/01 12:50:33 by jbeall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	handle_pa(t_stack *stack_a, t_stack *stack_b)
{
	t_val *a;

	a = ps_pop(stack_b);
	if (a)
		ps_push(a, stack_a);
	return (0);
}

int	handle_pb(t_stack *stack_a, t_stack *stack_b)
{
	t_val *a;

	a = ps_pop(stack_a);
	if (a)
		ps_push(a, stack_b);
	return (0);
}

int	handle_ra(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_b;
	rotate_f(stack_a);
	return (0);
}

int	handle_rb(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_a;
	rotate_f(stack_b);
	return (0);
}

int	handle_rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate_f(stack_a);
	rotate_f(stack_b);
	return (0);
}
