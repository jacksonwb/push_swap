/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbeall <jbeall@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 11:07:57 by jbeall            #+#    #+#             */
/*   Updated: 2019/02/01 16:27:41 by jbeall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	smart_rotate_a(t_stack *a, t_stack *b)
{
	int i;

	i = get_position_min(a);
	if (get_position_min(a) <= a->size / 2)
		while (i--)
			operate(a, b, "ra");
	else
		while (i++ < a->size)
			operate(a, b, "rra");
}

void	smart_rotate_b(t_stack *a, t_stack *b)
{
	if (get_position_min(b) >= b->size / 2)
		while (!full_sorted_rev(b, b->size))
			operate(a, b, "rrb");
	else
		while (!full_sorted_rev(b, b->size))
			operate(a, b, "rb");
}

int		full_sorted(t_stack *stk, int len)
{
	t_val *val;

	val = stk->start;
	while (val->next && --len)
	{
		if (val->val > val->next->val)
			return (0);
		val = val->next;
	}
	return (1);
}

int		full_sorted_rev(t_stack *stk, int len)
{
	t_val *val;

	val = stk->start;
	while (val && val->next && --len)
	{
		if (val->val < val->next->val)
			return (0);
		val = val->next;
	}
	return (1);
}
