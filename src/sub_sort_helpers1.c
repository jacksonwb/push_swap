/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_sort_helpers1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbeall <jbeall@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 11:04:34 by jbeall            #+#    #+#             */
/*   Updated: 2019/02/01 14:26:42 by jbeall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_5_helper(t_stack *a, t_stack *b)
{
	if (get_val_at(a, 0) > get_val_at(a, 1))
		operate(a, b, "sa");
}

int		get_good_placement_id(t_stack *a, int len, int invar, int current)
{
	t_val	*val;
	int		i;

	val = a->start;
	i = 0;
	while (i < len - invar)
	{
		val = val->next;
		i++;
	}
	while (val->val < current && val->next)
	{
		val = val->next;
		i++;
	}
	return (i);
}

int		get_good_placement_id_rev(t_stack *b, int len, int invar, int current)
{
	t_val	*val;
	int		i;

	val = b->start;
	i = 0;
	while (i < len - invar)
	{
		val = val->next;
		i++;
	}
	while (val->val > current && val->next)
	{
		val = val->next;
		i++;
	}
	return (i);
}

int		contains_lower(t_stack *a, int median)
{
	t_val *val;

	val = a->start;
	while (val)
	{
		if (val->val < median)
			return (1);
		val = val->next;
	}
	return (0);
}

int		find_median(t_stack *stk, int len)
{
	int under;
	int over;
	int i;
	int j;

	i = -1;
	while (++i < len)
	{
		under = 0;
		over = 0;
		j = -1;
		while (++j < len)
		{
			if (i != j)
			{
				if (get_val_at(stk, j) < get_val_at(stk, i))
					++under;
				else if (get_val_at(stk, j) > get_val_at(stk, i))
					++over;
			}
		}
		if (ft_abs(over - under) <= 1)
			return (get_val_at(stk, i));
	}
	return (get_val_at(stk, i));
}
