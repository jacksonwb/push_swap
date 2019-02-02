/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbeall <jbeall@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 10:58:39 by jbeall            #+#    #+#             */
/*   Updated: 2019/02/01 14:55:52 by jbeall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		sort_to_b(t_stack *a, t_stack *b, int median, int len)
{
	int j;
	int rotate;
	int count;
	int first;

	j = 0;
	count = 0;
	rotate = 0;
	first = len == a->total ? 1 : 0;
	while (j < len)
	{
		if (get_val_at(a, j) <= median)
		{
			while (j-- && len-- && ++rotate)
				operate(a, b, "ra");
			operate(a, b, "pb");
			len--;
			++count;
		}
		++j;
	}
	while (rotate-- && !first)
		operate(a, b, "rra");
	return (count);
}

int		sort_to_a(t_stack *a, t_stack *b, int median, int len)
{
	int j;
	int count;

	j = 0;
	count = 0;
	while (j < len)
	{
		if (get_val_at(b, j) >= median)
		{
			while (j-- && len--)
				operate(a, b, "rb");
			operate(a, b, "pa");
			len--;
			++count;
		}
		++j;
	}
	return (count);
}

void	move_num_to_a(t_stack *a, t_stack *b, int len)
{
	while (len--)
		operate(a, b, "pa");
}

void	push_swap_base(t_stack *a, t_stack *b, int len)
{
	int i;
	int j;

	i = 0;
	while (i < len)
	{
		if (get_val_at(a, 0) > get_val_at(a, 1) && !full_sorted(a, len)
			&& i < len - 2)
			operate(a, b, "sa");
		if (i > 0 && get_val_at(a, 0) < get_val_end(a))
		{
			operate(a, b, "pb");
			j = 0;
			while (j++ < i && get_val_at(b, 0) < get_val_end(a))
				operate(a, b, "rra");
			operate(a, b, "pa");
			while (j-- > 1)
				operate(a, b, "ra");
		}
		operate(a, b, "ra");
		++i;
	}
}

void	push_swap_base_b(t_stack *a, t_stack *b, int len)
{
	int i;

	i = 0;
	while (i < len && len > 1)
	{
		if (round_sorted_rev(b))
		{
			smart_rotate_b(a, b);
			return ;
		}
		if (get_val_at(b, 0) < get_val_at(b, 1) && !full_sorted_rev(b, len)
			&& i < len - 2)
			operate(a, b, "sb");
		if (i > 0 && get_val_at(b, 0) > get_val_end(b))
			smooth_operator(a, b, i);
		if (full_sorted(b, len))
			return ;
		if (!round_sorted(b))
			operate(a, b, "rb");
		++i;
	}
}
