/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_pack_two.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eosfryd <eosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 16:30:06 by eosfryd           #+#    #+#             */
/*   Updated: 2021/08/22 16:07:23 by eosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	my_rrarrb(t_Main *main, char *comma, int i)
{
	t_Tack	*stack;
	t_Item	*tmp;

	if (!ft_strcmp(comma, "rra"))
		stack = main->stk_a;
	else
		stack = main->stk_b;
	if (stack->head == NULL || stack->head->next == NULL)
		return ;
	tmp = stack->head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = stack->head;
	stack->head->prev = tmp;
	tmp = tmp->prev;
	tmp->next->prev = NULL;
	tmp->next = NULL;
	stack->head = stack->head->prev;
	if (i)
		ft_lstadd_back(&main->comma, ft_lstnew(comma));
}

void	my_rrr(t_Main *main)
{
	my_rrarrb(main, "rra", 0);
	my_rrarrb(main, "rrb", 0);
	ft_lstadd_back(&main->comma, ft_lstnew("rrr"));
}

t_Tack	*stack_init(t_Main *main)
{
	t_Tack	*stack;

	stack = (t_Tack *)malloc(sizeof(t_Tack));
	if (!stack)
		push_swap_exit(main, 1);
	stack->head = NULL;
	stack->lnght = 0;
	return (stack);
}

t_Tack	*stack_a_init(t_Main *main)
{
	t_Tack	*stack;

	stack = stack_init(main);
	parce_args(stack, main);
	return (stack);
}

t_Main	*push_swap_init(int num, char **args)
{
	t_Main	*main;

	main = (t_Main *)malloc(sizeof(t_Main));
	main->args = args;
	main->narg = num;
	main->flag = 0;
	main->max = 0;
	main->mid = 0;
	main->min = 0;
	main->next = 1;
	main->stk_a = stack_a_init(main);
	main->stk_b = stack_init(main);
	main->comma = 0;
	commands_init(main);
	return (main);
}
