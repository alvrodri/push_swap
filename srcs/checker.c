/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 15:36:44 by alvrodri          #+#    #+#             */
/*   Updated: 2021/04/24 12:06:17 by alvaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_data	data;

	(void)argc;
	data.a = NULL;
	data.b = NULL;
	parse_args(&data, argv + 1);
	parse_line(&data);
	list_free(&data);
	return (0);
}
