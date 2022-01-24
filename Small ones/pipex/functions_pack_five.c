/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_pack_five.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eosfryd <eosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 17:33:48 by eosfryd           #+#    #+#             */
/*   Updated: 2021/08/22 15:41:56 by eosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	my_papb_sequel(t_Tack *s, t_Tack *d)
{
	t_Item	*tmp;

	if (d->head == NULL)
	{
		d->head = s->head;
		s->head = s->head->next;
		d->head->next = NULL;
		s->head->prev = NULL;
	}
	else
	{
		tmp = s->head;
		if (s->head->next)
			s->head->next->prev = NULL;
		s->head = tmp->next;
		tmp->next = d->head;
		d->head->prev = tmp;
		d->head = tmp;
	}
}

void	commands_init(t_Main *main)
{
	main->commands = (t_commands *)malloc(sizeof(t_commands));
	main->commands->sa = ft_strdup("sa");
	main->commands->sb = ft_strdup("sb");
	main->commands->ss = ft_strdup("ss");
	main->commands->pa = ft_strdup("pa");
	main->commands->pb = ft_strdup("pb");
	main->commands->ra = ft_strdup("ra");
	main->commands->rb = ft_strdup("rb");
	main->commands->rr = ft_strdup("rr");
	main->commands->rra = ft_strdup("rra");
	main->commands->rrb = ft_strdup("rrb");
	main->commands->rrr = ft_strdup("rrr");
}

void	free_commands(t_Main *main)
{
	free(main->commands->sa);
	free(main->commands->sb);
	free(main->commands->ss);
	free(main->commands->pa);
	free(main->commands->pb);
	free(main->commands->ra);
	free(main->commands->rb);
	free(main->commands->rr);
	free(main->commands->rra);
	free(main->commands->rrb);
	free(main->commands->rrr);
	free(main->commands);
}

void	sort_three(t_Main *main, int i)
{
	int	f;
	int	s;
	int	t;

	f = main->stk_a->head->digit;
	s = main->stk_a->head->next->digit;
	if (i == 3)
		t = main->stk_a->head->next->next->digit;
	if ((i == 2 && f > s) || (f > s && s < t && f < t) || (f > s && s > t) \
	|| (f < s && s > t && f < t))
		my_sasb(main, "sa", 1);
	if (i == 3 && (((f > s && s > t)) || (f < s && s > t && t < f)))
		my_rrarrb(main, "rra", 1);
	if (i == 3 && ((f > s && s < t && t < f) || (f < s && s > t && f < t)))
		my_rarb(main, "ra", 1);
}

void	sort_five(t_Main *main)
{
	push_item_into_stack(main, main->stk_a, main->stk_b, 0);
	push_item_into_stack(main, main->stk_a, main->stk_b, 1);
	sort_three(main, main->stk_a->lnght);
	my_papb(main, "pa");
	my_papb(main, "pa");
}
