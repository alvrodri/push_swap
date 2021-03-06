/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvrodri <alvrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:06:27 by alvrodri          #+#    #+#             */
/*   Updated: 2021/05/17 09:03:27 by alvrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../resources/libft/libft.h"
# include "../resources/get_next_line/get_next_line.h"

typedef struct s_stack
{
	int			number;
}				t_stack;

typedef struct s_data
{
	t_list		*a;
	t_list		*b;
	int			debug;
	char		*line;
	char		*instructions;
}				t_data;

void			sa(t_data *data);
void			sb(t_data *data);
void			ss(t_data *data);
void			pa(t_data *data);
void			pb(t_data *data);
void			ra(t_data *data);
void			rb(t_data *data);
void			rr(t_data *data);
void			rra(t_data *data);
void			rrb(t_data *data);
void			rrr(t_data *data);

int				exec_print_s(t_data *data, char *str);
int				exec_print_p(t_data *data, char *str);
int				exec_print_rx(t_data *data, char *str);
int				exec_print_rrx(t_data *data, char *str);

void			ft_exit(t_data *data, char *status);
void			list_free(t_data *data);
void			stack_print(t_list *list);
void			print_instruction(t_data *data, char *instruction);
void			exec_print(t_data *data, char *str);

void			parse_args(t_data *data, char **argv);
void			parse_line(t_data *data);

void			move_smallest_to_b(t_data *data);

void			instruction_add(t_data *data, char *type);
void			instructions_print(t_data *data);

int				*get_ranges(t_data *data, int *numbers, int size, int n);
void			bubble_sort(int *arr, int n);
int				get_dir_closest_to_top(int n, t_list **list);
void			pass_better_to_b(t_data *data, int x, int y);
int				get_max_number(t_list *list);
void			what_number_to_move_to_b(t_data *data, t_list
					*first, t_list *second);

void			sort_two(t_data *data);
void			sort_three(t_data *data);
void			sort_four(t_data *data);
void			sort_five(t_data *data);
void			sort_large(t_data *data);

int				smallest_num_in_stack(t_list *list);
int				check_order(t_data *data);
int				get_number(t_list *list);
int				is_number(char *str);

int				main(int argc, char **argv);

#endif
