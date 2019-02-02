/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_sort2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbeall <jbeall@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 11:01:35 by jbeall            #+#    #+#             */
/*   Updated: 2019/02/01 16:35:57 by jbeall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ins_sort_helper_rev(t_stack *a, t_stack *b, int i)
{
	int place;

	place = get_good_placement_id_rev(b, b->size, i, b->start->val);
	if (place == b->size - 1)
	{
		operate(a, b, "rrb");
		operate(a, b, "sb");
		operate(a, b, "rb");
	}
	else if (place == 2)
		operate(a, b, "sb");
	else if (place > a->size / 2)
		smooth_operator_2(a, b, i);
	else
		smooth_operator_3(a, b, place);
}

void	push_swap_small_b(t_stack *a, t_stack *b, int len)
{
	int i;

	i = 0;
	while (!full_sorted_rev(b, b->size))
	{
		if (round_sorted_rev(b))
		{
			smart_rotate_b(a, b);
			break ;
		}
		else if (i > 0 && get_val_at(b, 0) > get_val_end(b)
			&& !round_sorted_rev(b))
			ins_sort_helper_rev(a, b, i);
		else if (get_val_at(b, 0) < get_val_at(b, 1) && !round_sorted_rev(b)
			&& i < len - 2)
			operate(a, b, "sb");
		else
		{
			operate(a, b, "rb");
			if (!round_sorted_rev(b))
				++i;
		}
	}
}

void	ins_sort_helper(t_stack *a, t_stack *b, int i)
{
	int j;
	int place;

	place = get_good_placement_id(a, a->size, i, a->start->val);
	if (place == a->size - 1)
	{
		operate(a, b, "rra");
		operate(a, b, "sa");
		operate(a, b, "ra");
	}
	else if (place == 2)
		operate(a, b, "sa");
	else if (place > a->size / 2)
		smooth_operator_main(a, b, i);
	else
	{
		operate(a, b, "pb");
		j = 0;
		while (j++ < place - 1)
			operate(a, b, "ra");
		operate(a, b, "pa");
		while (j-- > 1)
			operate(a, b, "rra");
	}
}

void	push_swap_small(t_stack *a, t_stack *b, int len)
{
	int i;
	int median;

	i = 0;
	median = find_median(a, len);
	while (!full_sorted(a, a->size) || contains_lower(a, median))
	{
		if (round_sorted(a) && (!contains_lower(a, median) || !b->size))
		{
			smart_rotate_a(a, b);
			break ;
		}
		if (get_val_at(a, 0) < median)
			operate(a, b, "pb");
		else if (i > 0 && get_val_at(a, 0) < get_val_end(a) && !round_sorted(a))
			ins_sort_helper(a, b, i);
		else if (get_val_at(a, 0) > get_val_at(a, 1) && !round_sorted(a)
			&& i < len - 2)
			operate(a, b, "sa");
		else
		{
			operate(a, b, "ra");
			!round_sorted(a) ? ++i : 0;
		}
	}
}

void	push_swap_5(t_stack *a, t_stack *b, int len)
{
	int i;
	int median;

	i = 0;
	median = find_median(a, len);
	while (!full_sorted(a, a->size))
	{
		if (round_sorted(a))
		{
			smart_rotate_a(a, b);
			break ;
		}
		if (get_val_at(a, 0) < median)
			operate(a, b, "pb");
		else if (i > 0 && get_val_at(a, 0) < get_val_end(a) && !round_sorted(a))
			ins_sort_helper(a, b, i);
		else if (get_val_at(a, 0) > get_val_at(a, 1) && !round_sorted(a)
			&& i < len - 2)
			operate(a, b, "sa");
		else
		{
			operate(a, b, "ra");
			!round_sorted(a) ? ++i : 0;
		}
	}
}
