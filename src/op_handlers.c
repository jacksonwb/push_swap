/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_handlers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbeall <jbeall@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 13:13:59 by jbeall            #+#    #+#             */
/*   Updated: 2019/02/01 12:48:48 by jbeall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		op_type(char *op, char **codes)
{
	int	i;

	i = 0;
	while (**codes)
	{
		if (!ft_strcmp(*codes, op))
			return (i);
		codes++;
		i++;
	}
	return (-1);
}

int		get_op(int fd, char **codes)
{
	char	*op_string;
	int		status;
	int		op;

	if ((status = get_next_line(fd, &op_string)))
	{
		if (status == 1 && (op = op_type(op_string, codes)) >= 0)
		{
			free(op_string);
			return (op);
		}
		else
			die("Error");
	}
	return (-1);
}

int		ps_do_op(t_stack *stack_a, t_stack *stack_b, int op)
{
	static int	(*handlers[11])(t_stack *stack_a, t_stack *stack_b) = {
		&handle_sa,
		&handle_sb,
		&handle_ss,
		&handle_pa,
		&handle_pb,
		&handle_ra,
		&handle_rb,
		&handle_rr,
		&handle_rra,
		&handle_rrb,
		&handle_rrr
	};

	return (handlers[op](stack_a, stack_b));
}

void	ps_push(t_val *val, t_stack *a)
{
	val->next = a->start;
	a->start = val;
	a->size += 1;
}

t_val	*ps_pop(t_stack *a)
{
	t_val *val;

	if (a->size)
	{
		val = a->start;
		a->start = (a->start)->next;
		a->size -= 1;
		return (val);
	}
	return (NULL);
}
