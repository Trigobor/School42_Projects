/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_pack_tree.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eosfryd <eosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 16:29:34 by eosfryd           #+#    #+#             */
/*   Updated: 2021/08/22 16:22:35 by eosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_exit(t_Main *main, int code)
{
	if (main)
		free(main);
	if (code == 0)
	{
		write(1, "\n", 1);
		exit (0);
	}
	write(1, "Error\n", ft_strlen("Error\n"));
	exit(1);
}

t_Item	*create_item(int i)
{
	t_Item	*itemnew;

	itemnew = (t_Item *)malloc(sizeof(t_Item));
	if (!itemnew)
		return (0);
	itemnew->trueprev = NULL;
	itemnew->prev = NULL;
	itemnew->digit = i;
	itemnew->order = -1;
	itemnew->index = -1;
	itemnew->shift = 0;
	itemnew->next = NULL;
	itemnew->truenext = NULL;
	return (itemnew);
}

void	add_item(t_Item *itemnew, t_Tack *stack)
{
	t_Item	*itembuf;

	if (stack->head == NULL)
	{
		stack->head = itemnew;
		itemnew->index = 0;
		itemnew->order = 0;
	}
	else
	{
		itembuf = stack->head;
		while (itembuf->next)
			itembuf = itembuf->next;
		itembuf->next = itemnew;
		itemnew->prev = itembuf;
		itemnew->index = 1 + itembuf->index;
		itemnew->order = itemnew->index;
	}
	stack->lnght++;
}

char	**argcreator(int ac, char **av, int *num)
{
	int		i;
	char	*str;
	char	*tmp;
	char	**rez;

	i = 2;
	*num = 0;
	str = ft_strdup(av[1]);
	while (i != ac)
	{
		tmp = str;
		str = ft_strjoin(str, " ");
		free(tmp);
		tmp = str;
		str = ft_strjoin(str, av[i++]);
		free(tmp);
	}
	rez = ft_split(str, ' ');
	free(str);
	while (rez[*num])
		*num = *num + 1;
	return (rez);
}

void	parce_args(t_Tack *stack, t_Main *main)
{
	int		i;
	int		num;
	t_Item	*item;

	i = 0;
	while (i < main->narg)
	{
		if (!ft_isnumber(main->args[i]))
			push_swap_exit(main, 1);
		if (!ft_isint(main->args[i]))
			push_swap_exit(main, 1);
		num = ft_atoi(main->args[i]);
		item = create_item(num);
		if (!item)
			push_swap_exit(main, 1);
		add_item(item, stack);
		i++;
	}
}
