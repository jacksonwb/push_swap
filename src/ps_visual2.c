/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_visual2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbeall <jbeall@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 13:02:18 by jbeall            #+#    #+#             */
/*   Updated: 2019/02/01 13:03:18 by jbeall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_min(t_stack *a)
{
	t_val	*val;
	int		min;

	val = a->start;
	min = val->val;
	while (val)
	{
		if (val->val < min)
			min = val->val;
		val = val->next;
	}
	return (min);
}

int		find_max(t_stack *a)
{
	t_val	*val;
	int		max;

	val = a->start;
	max = val->val;
	while (val)
	{
		if (val->val > max)
			max = val->val;
		val = val->next;
	}
	return (max);
}

int		scale_val(int val, int max, int min, int max_len)
{
	return (val ? ((double)val - (double)min) / ((double)max - (double)min) *
		(double)max_len : 0);
}
