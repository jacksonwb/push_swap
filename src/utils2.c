/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbeall <jbeall@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 11:06:58 by jbeall            #+#    #+#             */
/*   Updated: 2019/02/01 15:54:33 by jbeall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_val_at(t_stack *stk, int position)
{
	t_val *val;

	val = stk->start;
	while (position)
	{
		val = val->next;
		position--;
	}
	return (val->val);
}

int	get_val_end(t_stack *stk)
{
	t_val *val;

	val = stk->start;
	while (val->next)
		val = val->next;
	return (val->val);
}

int	round_sorted(t_stack *stk)
{
	int		breaks;
	t_val	*val;

	breaks = 0;
	val = stk->start;
	while (val->next)
	{
		if (val->val > val->next->val)
			breaks++;
		val = val->next;
	}
	if (val->val > stk->start->val)
		breaks++;
	if (breaks <= 1)
		return (1);
	else
		return (0);
}

int	round_sorted_rev(t_stack *stk)
{
	int		breaks;
	t_val	*val;

	breaks = 0;
	val = stk->start;
	while (val->next)
	{
		if (val->val < val->next->val)
			breaks++;
		val = val->next;
	}
	if (val->val < stk->start->val)
		breaks++;
	if (breaks <= 1)
		return (1);
	else
		return (0);
}

int	get_position_min(t_stack *stk)
{
	int		min;
	int		min_pos;
	int		i;
	t_val	*val;

	i = 1;
	val = stk->start;
	min = val->val;
	min_pos = 0;
	while (i < stk->size)
	{
		val = val->next;
		if (val->val < min)
		{
			min = val->val;
			min_pos = i;
		}
		i++;
	}
	return (min_pos);
}
