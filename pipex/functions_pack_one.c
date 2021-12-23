/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_pack_one.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eosfryd <eosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 16:30:06 by eosfryd           #+#    #+#             */
/*   Updated: 2021/08/22 15:33:44 by eosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	my_sasb(t_Main *main, char *comma, int i)
{
	t_Item	*tmp;
	t_Tack	*stack;

	if (!ft_strcmp(comma, "sa"))
		stack = main->stk_a;
	else
		stack = main->stk_b;
	if (!stack->head || !stack->head->next)
		return ;
	tmp = stack->head;
	stack->head = stack->head->next;
	tmp->next = stack->head->next;
	tmp->prev = stack->head;
	stack->head->prev = NULL;
	stack->head->next = tmp;
	if (i)
		ft_lstadd_back(&main->comma, ft_lstnew(comma));
}

void	my_ss(t_Main *main)
{
	my_sasb(main, "sa", 0);
	my_sasb(main, "sb", 0);
	ft_lstadd_back(&main->comma, ft_lstnew("ss"));
}

void	my_papb(t_Main *main, char *comma)
{
	t_Tack	*stack_src;
	t_Tack	*stack_dst;

	stack_src = main->stk_a;
	stack_dst = main->stk_b;
	if (!ft_strcmp(comma, "pa"))
	{
		stack_src = main->stk_b;
		stack_dst = main->stk_a;
	}
	if (stack_src->head->next == NULL)
	{
		stack_src->head->next = stack_dst->head;
		stack_dst->head->prev = stack_src->head;
		stack_dst->head = stack_src->head;
		stack_src->head = NULL;
	}
	else if (stack_src->head == NULL)
		return ;
	else
		my_papb_sequel(stack_src, stack_dst);
	ft_lstadd_back(&main->comma, ft_lstnew(comma));
}

void	my_rarb(t_Main *main, char *comma, int i)
{
	t_Tack	*stack;
	t_Item	*tmp;

	if (!ft_strcmp(comma, "ra"))
		stack = main->stk_a;
	else
		stack = main->stk_b;
	if (stack->head == NULL || stack->head->next == NULL)
		return ;
	tmp = stack->head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	stack->head->prev = tmp;
	tmp->next = stack->head;
	stack->head->next->prev = NULL;
	tmp = stack->head->next;
	stack->head->next = NULL;
	stack->head = tmp;
	if (i)
		ft_lstadd_back(&main->comma, ft_lstnew(comma));
}

void	my_rr(t_Main *main)
{
	my_rarb(main, "ra", 0);
	my_rarb(main, "rb", 0);
	ft_lstadd_back(&main->comma, ft_lstnew("rr"));
}
