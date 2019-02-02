/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_handlers2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbeall <jbeall@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 21:30:59 by jbeall            #+#    #+#             */
/*   Updated: 2019/02/01 12:50:04 by jbeall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_f(t_stack *a)
{
	t_val	*temp;
	t_val	*ptr;

	if (a->size > 1)
	{
		temp = a->start;
		a->start = a->start->next;
		ptr = a->start;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = temp;
		temp->next = NULL;
	}
}

void	rotate_r(t_stack *a)
{
	t_val	*ptr;

	if (a->size > 1)
	{
		ptr = a->start;
		while (a->start->next)
			a->start = a->start->next;
		a->start->next = ptr;
		while (ptr->next != a->start)
			ptr = ptr->next;
		ptr->next = NULL;
	}
}

int		handle_sa(t_stack *stack_a, t_stack *stack_b)
{
	t_val	*a;
	t_val	*b;

	(void)stack_b;
	a = ps_pop(stack_a);
	b = ps_pop(stack_a);
	if (a)
		ps_push(a, stack_a);
	if (b)
		ps_push(b, stack_a);
	return (0);
}

int		handle_sb(t_stack *stack_a, t_stack *stack_b)
{
	t_val	*a;
	t_val	*b;

	(void)stack_a;
	a = ps_pop(stack_b);
	b = ps_pop(stack_b);
	if (a)
		ps_push(a, stack_b);
	if (b)
		ps_push(b, stack_b);
	return (0);
}

int		handle_ss(t_stack *stack_a, t_stack *stack_b)
{
	handle_sa(stack_a, stack_b);
	handle_sb(stack_a, stack_b);
	return (0);
}
