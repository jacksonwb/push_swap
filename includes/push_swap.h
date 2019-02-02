/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbeall <jbeall@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 19:50:25 by jbeall            #+#    #+#             */
/*   Updated: 2019/02/01 16:44:36 by jbeall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include <unistd.h>
# include <curses.h>

# define PS_MAX_LEN 80
# define SLEEP_TIME "sleep 0.05"

typedef struct		s_op
{
	char			op;
	struct s_op		*next;
}					t_op;

typedef struct		s_val
{
	int				val;
	struct s_val	*next;
}					t_val;

typedef struct		s_stack
{
	t_val			*start;
	int				size;
	int				visual;
	int				max;
	int				min;
	int				total;
	WINDOW			*win;
}					t_stack;

void				operate(t_stack *stack_a, t_stack *stack_b, char *op);
void				push_swap(t_stack *a, t_stack *b, int len);

/*
** Sub sorts
*/
void				launch_ps_small(t_stack *a, t_stack *b);
void				push_swap_base(t_stack *a, t_stack *b, int len);
void				push_swap_small_b(t_stack *a, t_stack *b, int len);
void				push_swap_base_b(t_stack *a, t_stack *b, int len);
void				push_swap_small_b(t_stack *a, t_stack *b, int len);
void				ins_sort_helper_rev(t_stack *a, t_stack *b, int i);
void				ins_sort_helper(t_stack *a, t_stack *b, int i);
void				push_swap_small(t_stack *a, t_stack *b, int len);
void				push_swap_5(t_stack *a, t_stack *b, int len);

void				ps_5_helper(t_stack *a, t_stack *b);
int					get_good_placement_id(t_stack *a, int len, int invar,
						int current);
int					get_good_placement_id_rev(t_stack *b, int len,
						int invar, int current);
int					contains_lower(t_stack *a, int median);
int					find_median(t_stack *stk, int len);
int					sort_to_b(t_stack *a, t_stack *b, int median, int len);
int					sort_to_a(t_stack *a, t_stack *b, int median, int len);
void				move_num_to_a(t_stack *a, t_stack *b, int len);

void				smooth_operator(t_stack *a, t_stack *b, int i);
void				smooth_operator_2(t_stack *a, t_stack *b, int i);
void				smooth_operator_3(t_stack *a, t_stack *b, int place);
void				smooth_operator_main(t_stack *a, t_stack *b, int i);

/*
** Op Handlers
*/
int					op_type(char *op, char **codes);
int					get_op(int fd, char **codes);
int					ps_do_op(t_stack *stack_a, t_stack *stack_b, int op);

/*
** Stack Operations
*/
void				rotate_r(t_stack *a);
void				rotate_f(t_stack *a);
t_val				*ps_pop(t_stack *a);
void				ps_push(t_val *val, t_stack *a);

/*
** Sort Handlers
*/
int					handle_sa(t_stack *stack_a, t_stack *stack_b);
int					handle_sb(t_stack *stack_a, t_stack *stack_b);
int					handle_ss(t_stack *stack_a, t_stack *stack_b);
int					handle_pa(t_stack *stack_a, t_stack *stack_b);
int					handle_pb(t_stack *stack_a, t_stack *stack_b);
int					handle_ra(t_stack *stack_a, t_stack *stack_b);
int					handle_rb(t_stack *stack_a, t_stack *stack_b);
int					handle_rr(t_stack *stack_a, t_stack *stack_b);
int					handle_rra(t_stack *stack_a, t_stack *stack_b);
int					handle_rrb(t_stack *stack_a, t_stack *stack_b);
int					handle_rrr(t_stack *stack_a, t_stack *stack_b);

/*
** Utils
*/
int					convert_val(char *str);
void				ps_init(int num_vals, char **argv, t_stack **stack_a,
						t_stack **stack_b);
void				print_stack(t_stack *stack);
void				dup_check(t_stack *stack);
int					str_split_len(char **ar);
void				print_all(t_stack *a, t_stack *b);
int					get_val_at(t_stack *stk, int position);
int					get_val_end(t_stack *stk);
int					round_sorted(t_stack *stk);
int					round_sorted_rev(t_stack *stk);
int					get_position_min(t_stack *stk);
void				smart_rotate_a(t_stack *a, t_stack *b);
void				smart_rotate_b(t_stack *a, t_stack *b);
int					full_sorted(t_stack *stk, int len);
int					full_sorted_rev(t_stack *stk, int len);

/*
** Visual Mode
*/
void				init_visual(t_stack *a);
void				exit_visual(t_stack *a);
int					find_min(t_stack *a);
int					find_max(t_stack *a);
int					scale_val(int val, int max, int min, int max_len);
char				*dashes_str(int len);
void				put_line(int x, int y, int val, int dashes);
void				ps_visualize(t_stack *a, t_stack *b, char *op);

#endif
