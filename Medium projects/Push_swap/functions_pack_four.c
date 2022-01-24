/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_pack_four.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eosfryd <eosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 16:29:34 by eosfryd           #+#    #+#             */
/*   Updated: 2021/08/12 18:13:49 by eosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_free_stack(t_Tack *stack)
{
	t_Item	*tmp;

	if (stack && stack->head != NULL)
	{
		while (stack && stack->head)
		{
			tmp = stack->head->next;
			free(stack->head);
			stack->head = tmp;
		}
	}
	free(stack);
}

void	push_swap_free(t_Main *main)
{
	if (main->stk_a)
		push_swap_free_stack(main->stk_a);
	if (main->stk_b)
		push_swap_free_stack(main->stk_b);
	if (main->comma)
		ft_lstallfree(&main->comma);
	if (main->commands)
		free_commands(main);
	free(main);
}

t_Item	*itemi(t_Item *lst, int index)
{
	if (lst == NULL)
		return (NULL);
	while (lst)
	{
		if (lst->index == index)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

void	the_function_of_truth(t_Tack *stack, int a, int b, int p)
{
	int		l;
	int		r;
	t_Item	*temp;

	if (a < b)
	{
		p = itemi(stack->head, (a + b) / 2)->digit;
		l = a;
		r = b;
		while (l <= r)
		{
			while (itemi(stack->head, l)->digit < p)
				l++;
			while (itemi(stack->head, r)->digit > p)
				r--;
			if (l <= r)
			{
				temp = itemi(stack->head, l);
				(itemi(stack->head, r))->index = l++;
				temp->index = r--;
			}
		}
		the_function_of_truth(stack, a, r, 0);
		the_function_of_truth(stack, l, b, 0);
	}
}

void	make_things_right(t_Tack *stack)
{
	int	i;

	the_function_of_truth(stack, 0, stack->lnght - 1, 0);
	i = 1;
	stack->truehead = itemi(stack->head, 0);
	itemi(stack->head, 0)->trueprev = NULL;
	itemi(stack->head, 0)->truenext = NULL;
	itemi(stack->head, stack->lnght - 1)->truenext = NULL;
	while (i < stack->lnght)
	{
		itemi(stack->head, i)->trueprev = itemi(stack->head, i - 1);
		itemi(stack->head, i - 1)->truenext = itemi(stack->head, i);
		i++;
	}
}
