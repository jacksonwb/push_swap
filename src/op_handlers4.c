/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_handlers4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbeall <jbeall@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 21:32:49 by jbeall            #+#    #+#             */
/*   Updated: 2019/02/01 16:36:29 by jbeall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	handle_rra(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_b;
	rotate_r(stack_a);
	return (0);
}

int	handle_rrb(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_a;
	rotate_r(stack_b);
	return (0);
}

int	handle_rrr(t_stack *stack_a, t_stack *stack_b)
{
	rotate_r(stack_a);
	rotate_r(stack_b);
	return (0);
}

int	str_split_len(char **ar)
{
	int i;

	i = 0;
	if (!*ar)
		return (0);
	while (ar[i])
		++i;
	return (i);
}
