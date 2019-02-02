/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_sort_helpers2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbeall <jbeall@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 15:20:18 by jbeall            #+#    #+#             */
/*   Updated: 2019/02/01 16:29:01 by jbeall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	smooth_operator(t_stack *a, t_stack *b, int i)
{
	int j;

	operate(a, b, "pa");
	j = 0;
	while (j++ < i && get_val_at(a, 0) > get_val_end(b))
		operate(a, b, "rrb");
	operate(a, b, "pb");
	while (j-- > 1)
		operate(a, b, "rb");
}

void	smooth_operator_2(t_stack *a, t_stack *b, int i)
{
	int j;

	operate(a, b, "pa");
	j = 0;
	while (j++ < i && get_val_at(a, 0) > get_val_end(b))
		operate(a, b, "rrb");
	operate(a, b, "pb");
	while (j-- > 1 && !round_sorted(b))
		operate(a, b, "rb");
}

void	smooth_operator_3(t_stack *a, t_stack *b, int place)
{
	int j;

	operate(a, b, "pa");
	j = 0;
	while (j++ < place - 1)
		operate(a, b, "rb");
	operate(a, b, "pb");
	while (j-- > 1)
		operate(a, b, "rrb");
}

void	smooth_operator_main(t_stack *a, t_stack *b, int i)
{
	int j;

	operate(a, b, "pb");
	j = 0;
	while (j++ < i && get_val_at(b, 0) < get_val_end(a))
		operate(a, b, "rra");
	operate(a, b, "pa");
	while (j-- > 1 && !round_sorted(a))
		operate(a, b, "ra");
}
