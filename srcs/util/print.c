/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 18:15:19 by alvrodri          #+#    #+#             */
/*   Updated: 2021/05/04 11:02:42 by alvrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	get_number(t_list *list)
{
	return (((t_stack *)list->content)->number);
}

void	exec_print(t_data *data, char *str)
{
	if (ft_strnstr(str, "sa", 2))
	{
		sa(data);
		instruction_add(data, "sa ");
	}
	else if (ft_strnstr(str, "sb", 2))
	{
		sb(data);
		instruction_add(data, "sb ");
	}
	else if (ft_strnstr(str, "ss", 2))
	{
		ss(data);
		instruction_add(data, "ss ");
	}
	else if (ft_strnstr(str, "pa", 2))
	{
		pa(data);
		instruction_add(data, "pa ");
	}
	else if (ft_strnstr(str, "pb", 2))
	{
		pb(data);
		instruction_add(data, "pb ");
	}
	else if (ft_strnstr(str, "rra", 3))
	{
		rra(data);
		instruction_add(data, "rra ");
	}
	else if (ft_strnstr(str, "rrb", 3))
	{
		rrb(data);
		instruction_add(data, "rrb ");
	}
	else if (ft_strnstr(str, "rrr", 3))
	{
		rrr(data);
		instruction_add(data, "rrr ");
	}
	else if (ft_strnstr(str, "ra", 2))
	{
		ra(data);
		instruction_add(data, "ra ");
	}
	else if (ft_strnstr(str, "rb", 2))
	{
		rb(data);
		instruction_add(data, "rb ");
	}
	else if (ft_strnstr(str, "rr", 2))
	{
		rr(data);
		instruction_add(data, "rr ");
	}
}

void	print_line(int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		printf("█");
		i++;
	}
	printf("\n");
}

void	print_instruction_color(t_data *data, char *instruction)
{
	t_list	*a;
	t_list	*b;


	a = data->a;
	b = data->b;
	printf("\e[1;1H\e[2J\n");
	printf("%30s\n", instruction);
	printf("\x1B[32m\n");
	while (1)
	{
		if (!a && !b)
			break ;
		if (a)
			print_line(get_number(a));
		if (b)
			print_line(get_number(b));
		if (a)
			a = a->next;
		if (b)
			b = b->next;
	}
	printf("\033[0m\n");
	usleep(1000);
}

void	print_instruction(t_data *data, char *instruction)
{
	t_list	*a;
	t_list	*b;


	a = data->a;
	b = data->b;
	printf("\e[1;1H\e[2J\n");
	printf("%30s\n", instruction);
	printf("%20c", 'A');
	printf("%20c\n", 'B');
	while (1)
	{
		if (!a && !b)
			break ;
		if (a)
			printf("%20d", get_number(a));
		else
			printf("%20c", ' ');
		if (b)
			printf("%20d", get_number(b));
		else
			printf("%20c", ' ');
		printf("\n");
		if (a)
			a = a->next;
		if (b)
			b = b->next;
	}
	usleep(100000);
	//print_instruction_color(data, instruction);
}

void	instruction_add(t_data *data, char *type)
{
	char	*tmp;

	tmp = data->instructions;
	data->instructions = ft_strjoin(tmp, type);
	free(tmp);
}

char	*remove_duplicates(t_data *data, char *type)
{
	char	*string;
	char	*find;
	char	*back;
	char	*tmp;

	string = data->instructions;
	find = ft_strnstr(string, type, ft_strlen(string));
	while (find != NULL)
	{
		*find = '\0';
		back = ft_strdup(find + ft_strlen(type));
		tmp = ft_strjoin(string, back);
		//free(string);
		free(back);
		string = tmp;
		find = ft_strnstr(string, type, ft_strlen(string));
	}
	return (string);
}

void	instructions_print(t_data *data)
{
	int		i;
	int		pb;
	int		pa;
	char	**split;

	i = 0;
	data->instructions = remove_duplicates(data, "pa pb");
	data->instructions = remove_duplicates(data, "pb pa ");
//	data->instructions = remove_duplicates(data, "ra rra");
//	data->instructions = remove_duplicates(data, "rra ra");
	split = ft_split(data->instructions, ' ');
	while (split[i])
	{
		if (split[i] && split[i][0] != ' ')
		{
			printf("%s\n", split[i]);
			free(split[i]);
		}
		i++;
	}
	free(split);
}

void	stack_print(t_list *list)
{
	t_stack	*stack;
	t_list	*curr;

	if (!list)
		return ;
	curr = list;
	while (curr)
	{
		stack = (t_stack *)curr->content;
		printf("%d\n", stack->number);
		curr = curr->next;
	}
	printf("------\n");
}
