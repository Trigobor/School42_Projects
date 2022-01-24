/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_pack_seven.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eosfryd <eosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 18:56:40 by eosfryd           #+#    #+#             */
/*   Updated: 2021/08/22 17:21:50 by eosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_Main *main)
{
	t_Item	*tmp;

	tmp = main->stk_a->head;
	while (tmp)
	{
		if (tmp->next != tmp->truenext)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	find_median(t_Main *main, int first)
{
	int		rez;
	t_Item	*tmp;

	tmp = main->stk_a->head;
	rez = tmp->index;
	while (tmp->next)
	{
		if (tmp->index > rez && tmp->shift == 0)
			rez = tmp->index;
		tmp = tmp->next;
	}
	if (first == 1)
		rez = rez / 2 + main->next;
	else
		rez = ((rez - main->next) / 2) + main->next;
	return (rez);
}

void	sort_many(t_Main *main)
{
	int	first;

	main->next = 0;
	first = 1;
	while (!check_sort(main))
	{
		main->mid = find_median(main, first);
		split_stack_a(main, first, main->stk_a->head, 1);
		first = 0;
		while (main->stk_b->head != NULL)
		{
			main->max = main->mid;
			main->mid = ((main->max - main->next) / 2) + main->next;
			main->flag++;
			split_stack_b(main, main->stk_b->head, 1);
		}
		finish_this(main, main->stk_a->head, main->stk_a->head->shift);
	}
}
