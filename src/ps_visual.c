/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_visual.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbeall <jbeall@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 15:12:31 by jbeall            #+#    #+#             */
/*   Updated: 2019/02/01 13:03:42 by jbeall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_visual(t_stack *a)
{
	WINDOW * win;
	if ((win = initscr()) == NULL)
	{
		exit(EXIT_FAILURE);
	}
	curs_set(0);
	a->visual = 1;
	a->win = win;
	a->max = find_max(a);
	a->min = find_min(a);
	wattron(win, A_BOLD);
	refresh();
}

void	exit_visual(t_stack *a)
{
	if (a->visual)
	{
		sleep(5);
		delwin(a->win);
		endwin();
		refresh();
	}
}

char	*dashes_str(int len)
{
	char	*str;
	int		i;

	i = 0;
	if (!len)
		return (NULL);
	str = (char *)ft_memalloc(len + 1);
	while (i < len)
		str[i++] = '-';
	str[i] = '\0';
	return (str);
}

void	put_line(int x, int y, int val, int dashes)
{
	char *str;

	str = dashes_str(dashes);
	mvprintw(y, x, "%d%s", val, str ? str : "");
	free(str);
}

void	ps_visualize(t_stack *a, t_stack *b, char *op)
{
	t_val	*val;
	int		y;

	y = 0;
	val = a->start;
	clear();
	while (val)
	{
		put_line(0, y++, val->val, scale_val(val->val, a->max,
			a->min, PS_MAX_LEN));
		val = val->next;
	}
	mvprintw(a->total, 0, "op: %s", op);
	y = 0;
	val = b->start;
	while (val)
	{
		put_line(PS_MAX_LEN + 5, y++, val->val, scale_val(val->val, a->max,
			a->min, PS_MAX_LEN));
		val = val->next;
	}
	refresh();
	system(SLEEP_TIME);
}
