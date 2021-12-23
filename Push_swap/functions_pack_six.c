/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_pack_six.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eosfryd <eosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 18:56:40 by eosfryd           #+#    #+#             */
/*   Updated: 2021/08/22 15:34:49 by eosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_item_into_stack(t_Main *main, t_Tack *src, t_Tack *dst, int index)
{
	t_Item	*tmp;
	char	*cmd;
	int		i;

	cmd = main->commands->pa;
	if (src == main->stk_a)
		cmd = main->commands->pb;
	i = 0;
	tmp = src->head;
	while (tmp && tmp->index != index)
	{
		i++;
		tmp = tmp->next;
	}
	push_item_into_stack_sequel(main, cmd, i);
	src->lnght--;
	dst->lnght++;
}

void	push_item_into_stack_sequel(t_Main *main, char *cmd, int i)
{
	char	*cr;

	if (main->stk_a->lnght / 2 > i)
	{
		cr = main->commands->rb;
		if (main->stk_a == main->stk_a)
			cr = main->commands->ra;
		while (i-- != 0)
			my_rarb(main, cr, 1);
	}
	else
	{
		i = main->stk_a->lnght - i;
		cr = main->commands->rrb;
		if (main->stk_a == main->stk_a)
			cr = main->commands->rra;
		while (i-- != 0)
			my_rrarrb(main, cr, 1);
	}
	my_papb(main, cmd);
}

void	split_stack_a(t_Main *main, int first, t_Item *tmp, int i)
{
	while (i <= main->stk_a->lnght && tmp->shift == 0)
	{
		if (tmp->index < main->mid)
		{
			my_papb(main, "pb");
			main->stk_a->lnght--;
			main->stk_b->lnght++;
		}
		else
		{
			my_rarb(main, "ra", 1);
			i++;
		}
		tmp = main->stk_a->head;
	}
	while (first == 0 && --i)
	{
		if (main->stk_b->head->index != main->next)
			my_rrr(main);
		else
			my_rrarrb(main, "rra", 1);
	}
}

void	split_stack_b(t_Main *main, t_Item *tmp, int i)
{
	while (i <= main->stk_b->lnght)
	{
		if (tmp->index == main->next)
		{
			tmp->shift = main->flag;
			my_papb(main, "pa");
			my_rarb(main, "ra", 1);
			main->next++;
			main->stk_a->lnght++;
			main->stk_b->lnght--;
		}
		else if (tmp->index >= main->mid)
		{
			tmp->shift = main->flag;
			my_papb(main, "pa");
			main->stk_a->lnght++;
			main->stk_b->lnght--;
		}
		else
		{
			my_rarb(main, "rb", 1);
			i++;
		}
		tmp = main->stk_b->head;
	}
}

void	finish_this(t_Main *main, t_Item *tmp, int i)
{
	while (tmp && tmp->shift == i && tmp->index >= main->next)
	{
		if (tmp->index == tmp->next->index + 1 && \
		tmp->next->index == main->next)
			my_sasb(main, "sa", 1);
		else if (tmp->index == main->next)
		{
			if (main->stk_b->head && main->stk_b->head->index != main->next)
				my_rr(main);
			else
				my_rarb(main, "ra", 1);
			main->next++;
		}
		else
		{
			my_papb(main, "pb");
			main->stk_a->lnght--;
			main->stk_b->lnght++;
		}
		tmp = main->stk_a->head;
	}
	main->max = main->mid;
	main->mid = ((main->max - main->next) / 2) + main->next;
	main->flag++;
	split_stack_b(main, main->stk_b->head, 1);
}
